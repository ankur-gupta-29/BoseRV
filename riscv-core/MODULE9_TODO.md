# Module 9 — Supervisor Mode & Virtual Memory (Sv32): Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

**Privilege Levels:**
- Machine Mode (M): Highest privilege, firmware/bootloader
- Supervisor Mode (S): OS kernel mode
- User Mode (U): User applications

**Virtual Memory:**
- User programs see a **virtual address space** (0x00000000 - 0xFFFFFFFF)
- OS provides **page tables** that translate virtual → physical addresses
- Allows memory protection (user code can't access kernel memory)
- Enables swapping, shared libraries, and efficient memory use

**Sv32** is RISC-V's 32-bit virtual memory system:
- 4KB pages (12-bit offset)
- Two-level page tables (VPN[1] and VPN[0], 10 bits each)
- TLB (Translation Lookaside Buffer) caches recent translations

```
Virtual Address:  [VPN[1] (10) | VPN[0] (10) | Offset (12)]
                  bits 31-22      bits 21-12    bits 11-0

Translation:
  Page table base (from satp CSR)
  → Level 1 page table [VPN[1]] → L1 PTE
  → Level 2 page table [VPN[0]] → L2 PTE
  → Physical Page Number (PPN) from PTE + Offset → Physical Address
```

---

## Assignment I1 — Supervisor Mode CSRs

**Goal:** Add Supervisor-mode CSRs alongside Machine-mode CSRs.

### Step 1 — Extend CSR File

- [ ] Add S-mode CSRs to `src/csr_file.v`:
  ```
  sstatus (0x100)  ← Supervisor status (interrupt enable, privilege bits)
  sie     (0x104)  ← Supervisor interrupt enable
  stvec   (0x105)  ← Supervisor trap vector
  sepc    (0x141)  ← Supervisor exception PC
  scause  (0x142)  ← Supervisor exception cause
  stval   (0x143)  ← Supervisor trap value
  sip     (0x144)  ← Supervisor interrupt pending
  satp    (0x180)  ← Supervisor address translation and protection
            [31] = MODE (0=off, 1=Sv32)
            [30:22] = ASID (address space ID, unused for now)
            [21:0] = PPN of root page table
  ```

- [ ] Update privilege tracking:
  ```verilog
  reg [1:0] current_mode;  // 0=U, 1=S, 3=M
  // Read CSRs based on privilege (sstatus visible from S-mode, etc)
  ```

- [ ] **Test:** Run `make py_csr_s_mode` — read/write S-mode CSRs

**Concept check:**
> Why does satp have an ASID field even if we don't use it?

---

## Assignment I2 — Page Table Walker (PTW)

**File:** `src/ptw.v` (NEW — you create this)
**Goal:** Translate virtual address → physical address using page tables in DRAM.

### Concept: Two-Level Page Table Walk

```
Virtual Address: 0x12345678
  VPN[1] = 0x12345[31:22] = bits from addr[31:22]
  VPN[0] = 0x45[21:12] = bits from addr[21:12]
  Offset = 0x678 = addr[11:0]

SATP register (from CSR file):
  PPN_root = satp[21:0] (root page table PPN)

Step 1: Fetch L1 PTE
  L1 address = (PPN_root << 12) + (VPN[1] * 4)
  Load 32-bit PTE from memory at L1 address

Step 2: Check L1 PTE
  if not valid → page fault
  if leaf (V=1 and R/W set) → use as megapage (2MB), translate offset
  else → get PPN from L1 PTE, continue to L2

Step 3: Fetch L2 PTE
  L2 address = (PPN_from_L1 << 12) + (VPN[0] * 4)
  Load 32-bit PTE from memory at L2 address

Step 4: Check L2 PTE
  if not valid → page fault
  else → use PPN from L2 PTE + Offset → physical address
```

### Step 1 — Create `src/ptw.v`

- [ ] Declare module:
  - Inputs: `vaddr [31:0]` (virtual address to translate), `satp [31:0]`, `mem_req`, `mem_data [31:0]` (PTE from memory)
  - Outputs: `paddr [31:0]` (physical address), `hit` (translation valid), `fault` (page fault)

- [ ] Implement state machine (3 states: idle, fetch_L1, fetch_L2):
  ```verilog
  reg [1:0] state;
  reg [31:0] pte_l1, pte_l2;
  
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      state <= IDLE;
    end else begin
      case (state)
        IDLE: begin
          if (mem_req) begin
            // Start L1 table walk
            mem_addr <= (satp[21:0] << 12) + (vaddr[31:22] << 2);
            state <= FETCH_L1;
          end
        end
        FETCH_L1: begin
          pte_l1 <= mem_data;
          if (pte_l1[0] == 0) begin  // Not valid
            fault <= 1;  state <= IDLE;
          end else if (pte_l1[3] | pte_l1[1]) begin  // Leaf: R=1 or X=1
            // Use as megapage (4MB superpage)
            hit <= 1;  state <= IDLE;
          end else begin
            // Fetch L2 — pte_l1[31:10] is the 22-bit PPN in Sv32
            mem_addr <= ({10'b0, pte_l1[31:10]} << 12) + (vaddr[21:12] << 2);
            state <= FETCH_L2;
          end
        end
        FETCH_L2: begin
          pte_l2 <= mem_data;
          if (pte_l2[0] == 0) begin  // Not valid
            fault <= 1;  state <= IDLE;
          end else begin
            hit <= 1;  state <= IDLE;
          end
        end
      endcase
    end
  end
  ```

- [ ] Compute physical address from PTE:
  ```verilog
  // In Sv32: PTE[31:10] = PPN (22 bits), not [29:10]
  wire [21:0] ppn = pte_l2[31:10];  // 22-bit PPN from leaf PTE
  assign paddr = {ppn, vaddr[11:0]};  // PPN (22 bits) + page offset (12 bits) = 34-bit PA
  // For RV32 with physical address space <= 4GB, use ppn[19:0] + offset
  ```

- [ ] **Test:** Run `make py_ptw` — virtual → physical translation correct

**Concept check:**
> What permissions (R, W, X) should be checked in the PTW? When do you return a page fault?

---

## Assignment I3 — TLB (Translation Lookaside Buffer)

**File:** `src/tlb.v` (NEW — you create this)
**Goal:** Cache recent virtual → physical translations to avoid repeated PTW.

### Concept: TLB

A TLB is a small, fast cache (typically 16-64 entries) that stores recent page translations:

```
Entry = [VPN (20 bits), PPN (20 bits), permissions (4 bits), ASID (9 bits)]
```

On each memory access:
1. Check TLB with virtual address VPN
2. If hit: return physical address immediately (1 cycle)
3. If miss: trigger PTW (32+ cycles to walk page table), then update TLB

### Step 1 — Create `src/tlb.v`

- [ ] Declare module:
  - Inputs: `vaddr [31:0]`, `ptw_result [31:0]`, `ptw_valid`, `ptw_update`
  - Outputs: `paddr [31:0]`, `hit`

- [ ] Implement 16-entry direct-mapped TLB:
  ```verilog
  reg [27:0] tlb_entry [0:15];  // VPN (20) + PPN (20)... actually need to split
  // Better: VPN (20 bits) + PPN (20 bits) = 40 bits per entry, use 2 regs per entry
  
  wire [3:0] tlb_index = vaddr[15:12];  // Use lower address bits for indexing
  wire [19:0] vpn = vaddr[31:12];
  wire tlb_hit = (tlb_vpn[tlb_index] == vpn);
  
  always @(posedge clk) begin
    if (ptw_update) begin
      // Update TLB with new translation from PTW
      tlb_vpn[tlb_index] <= ptw_vaddr[31:12];
      tlb_ppn[tlb_index] <= ptw_result[31:12];
    end
  end
  
  assign paddr = tlb_hit ? {tlb_ppn[tlb_index], vaddr[11:0]} : 32'hxxxxxxxx;
  assign hit = tlb_hit;
  ```

- [ ] On TLB miss, send request to PTW:
  ```verilog
  ptw_request = ~hit;
  ```

- [ ] **Test:** Run `make py_tlb` — hits cache recent translations, misses trigger PTW

**Concept check:**
> If you modify a page table in memory (OS changing permissions), how does the TLB know to update?

---

## Assignment I4 — Integrate Virtual Memory into Pipeline

**Goal:** Wire PTW and TLB into memory subsystem, translate all addresses.

### Step 1 — Add Virtual Memory to Memory Stage

- [ ] In `pipe_top.v`, check if S-mode or U-mode (use mstatus CSR):
  ```verilog
  wire vm_enabled = (satp[31] == 1) & (current_mode != MACHINE_MODE);
  ```

- [ ] When virtual memory enabled, translate addresses:
  ```verilog
  tlb tlb_inst (
    .vaddr(alu_result_MEM),
    .ptw_result(ptw_paddr),
    .ptw_valid(ptw_done),
    .ptw_update(ptw_done),
    .paddr(phys_addr),
    .hit(tlb_hit)
  );
  
  ptw ptw_inst (
    .vaddr(alu_result_MEM),
    .satp(satp_val),
    .mem_req(~tlb_hit & mem_read_MEM),
    .mem_data(mem_data),  // PTW reads from memory
    .paddr(ptw_paddr),
    .hit(ptw_done),
    .fault(page_fault)
  );
  
  // Use physical address for memory access
  final_addr = vm_enabled ? phys_addr : alu_result_MEM;
  ```

- [ ] Handle page faults (raise exception):
  ```verilog
  if (page_fault) begin
    exception <= 1;
    mcause <= (mem_write_MEM) ? STORE_PAGE_FAULT : LOAD_PAGE_FAULT;
    stval <= vaddr;  // Save faulting address
  end
  ```

### Step 2 — Test Virtual Memory

- [ ] Write test program:
  - Set up a simple page table (map VPN 0 → PPN 0)
  - Enable virtual memory in satp
  - Change privilege to S-mode
  - Load from virtual address → should translate and work

- [ ] **Test:** Run `make py_pipe_top`, verify:
  - Virtual addresses translate correctly
  - TLB caches translations
  - Page faults raise exceptions

**Concept check:**
> If you have a self-modifying program that changes page table entries, what needs to happen?

---

## Completion Gate

Before calling Module 9 done:
- [ ] `make py_csr_s_mode` passes S-mode CSR tests
- [ ] `make py_ptw` passes page table walk tests
- [ ] `make py_tlb` passes TLB hit/miss tests
- [ ] `make py_pipe_top` works with virtual memory enabled
- [ ] Page faults are caught and trigger exceptions
- [ ] You can explain: why TLB before PTW vs direct PTW?

---

## Files Changed in Module 9

| File | Change |
|------|--------|
| `src/csr_file.v` | [MODIFY] Add S-mode CSRs (sstatus, stvec, sepc, satp) |
| `src/ptw.v` | [NEW] Page table walker (2-level walk) |
| `src/tlb.v` | [NEW] 16-entry TLB cache |
| `src/pipe_top.v` | [MODIFY] Integrate PTW/TLB, translate all D-Cache addresses |

---

## Sv32 Page Table Entry (PTE)

```
[31:10] = PPN (physical page number, 22 bits for 4MB physical space)
[9:4]   = Reserved (for future use)
[3]     = Dirty (D) — page written
[2]     = Accessed (A) — page read
[1]     = Writable (W)
[0]     = Readable (R)
         If R=0 and W=1: Reserved for future
         If R=1 and W=1: Writable page
         If R=1 and W=0: Read-only page
```

## Exception Codes for Virtual Memory

```
0xC  = Instruction page fault
0xD  = Load page fault
0xF  = Store page fault
```

## Privilege Modes

```
00 = User (U)
01 = Supervisor (S)
11 = Machine (M)
```
