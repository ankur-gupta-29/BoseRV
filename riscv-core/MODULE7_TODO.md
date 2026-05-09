# Module 7 — Privileged ISA & CSRs (Machine Mode): Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

User programs can't directly manage interrupts, exceptions, or privilege levels. **Machine Mode (M-mode)** is the highest privilege level where the OS runs. Key features:

1. **CSRs (Control & Status Registers)**: 4096 special registers (12-bit address) that control CPU behavior
2. **Trap Handling**: When an exception/interrupt occurs, jump to `mtvec` (trap vector) and save PC in `mepc`
3. **Exception Types**: Illegal instruction, divide by zero, system call (`ecall`), breakpoint (`ebreak`)

```
Exception occurs → CPU saves PC to mepc → Jump to mtvec → Handler code → mret (return)
```

---

## Assignment G1 — CSR Register File

**File:** `src/csr_file.v` (NEW — you create this)
**Goal:** Implement 4096 CSRs that control processor behavior.

### Concept: CSR Organization

CSRs are 32-bit registers accessed by 12-bit address. Key Machine-Mode CSRs:

```
mstatus  (0x300): Global interrupt enable, privilege bits
mtvec    (0x305): Address of exception handler (trap vector)
mepc     (0x341): Exception PC (saved PC when trap occurs)
mcause   (0x342): Reason for exception (illegal instr, ecall, etc)
mie      (0x304): Interrupt enable bits
mip      (0x344): Interrupt pending bits
mscratch (0x340): Scratch register for M-mode
```

### Step 1 — Create `src/csr_file.v`

- [ ] Declare module:
  - Inputs: `clk, rst`, `csr_addr [11:0]`, `csr_data_in [31:0]`, `csr_write`
  - Outputs: `csr_data_out [31:0]`

- [ ] Implement CSR storage (can use 4096-entry array or explicit assignments):
  ```verilog
  reg [31:0] csr_file [0:4095];
  
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      csr_file[12'h300] <= 32'h00000000;  // mstatus
      csr_file[12'h305] <= 32'h00000000;  // mtvec
      // ... initialize other CSRs
    end else if (csr_write) begin
      csr_file[csr_addr] <= csr_data_in;
    end
  end
  
  assign csr_data_out = csr_file[csr_addr];
  ```

- [ ] Implement read-modify-write logic (for CSRRS, CSRRC instructions):
  - CSRRW (CSR Read/Write): write directly
  - CSRRS (CSR Read/Set): data_out |= data_in
  - CSRRC (CSR Read/Clear): data_out &= ~data_in

- [ ] **Test:** Run `make py_csr` — read/write CSRs correctly

**Concept check:**
> What happens if you write to a read-only CSR? Should the CPU ignore it or fault?

---

## Assignment G2 — CSR Instructions (CSRRW, CSRRS, CSRRC)

**Goal:** Decode and execute CSR manipulation instructions.

### Step 1 — Extend Decoder for CSR Instructions

- [ ] Add opcode case for SYSTEM instructions (opcode = 1110011):
  ```verilog
  7'b1110011: begin  // SYSTEM
    case (funct3)
      3'b001: csr_op = CSR_RW;     // CSRRW
      3'b010: csr_op = CSR_RS;     // CSRRS
      3'b011: csr_op = CSR_RC;     // CSRRC
      3'b101: csr_op = CSR_RWI;    // CSRRWI (immediate)
      3'b110: csr_op = CSR_RSI;    // CSRRSI
      3'b111: csr_op = CSR_RCI;    // CSRRCI
      default: csr_op = NO_CSR_OP;
    endcase
    csr_addr = imm[11:0];  // CSR address from immediate
  end
  ```

- [ ] Also decode special instructions:
  - `ecall` (funct3=0, funct12=0): system call → raise exception
  - `ebreak` (funct3=0, funct12=1): debugger breakpoint

### Step 2 — Implement CSR Operations in ALU/EX Stage

- [ ] When `csr_op != 0`:
  ```verilog
  reg [31:0] csr_result;
  always @(*) begin
    case (csr_op)
      CSR_RW:  csr_result = rs1_data;           // Write rs1 to CSR
      CSR_RS:  csr_result = csr_data | rs1_data; // Set bits
      CSR_RC:  csr_result = csr_data & ~rs1_data; // Clear bits
      CSR_RWI: csr_result = imm;                 // Write immediate
      // ... immediate versions
    endcase
  end
  ```

- [ ] Output includes both:
  - New CSR value (to write back to CSR file)
  - Old CSR value (to write back to rd register)

- [ ] **Test:** Run `make py_csr_ops` — all CSR instructions execute correctly

**Concept check:**
> If you CSRRS (set bits) with all 1s in rs1, what does it do? What about CSRRC?

---

## Assignment G3 — Exception Handling (Trap Entry & Exit)

**Goal:** Detect exceptions and jump to handler.

### Concept: Exception Causes

Each exception type has a numeric code:

```
mcause[31] = 1 (interrupt bit)
mcause[30:0] = cause code:
  0 = Instruction address misaligned
  2 = Illegal instruction
  3 = Breakpoint (ebreak)
  5 = Load address misaligned
  8 = Environment call from U-mode (ecall from user)
  9 = Environment call from S-mode
  11 = Environment call from M-mode (ecall from machine)
```

### Step 1 — Detect Exceptions in EX Stage

> **RISC-V spec note:** Division by zero is NOT a trap. RISC-V defines the result: `DIV/REM by 0 → quotient = 0xFFFFFFFF (-1), remainder = dividend`. Your divider must handle this in hardware, not via an exception.

- [ ] Illegal instruction: `instr_is_unknown` (decoder couldn't decode it)
- [ ] Load/store misalignment: `(mem_read || mem_write) && (addr[1:0] != 0)` for LW/SW
- [ ] System call: `ecall` instruction decoded

  ```verilog
  wire exception = illegal_instr | load_misalign | store_misalign | ecall_instr | ebreak_instr;
  wire [31:0] mcause_value = illegal_instr  ? 32'd2  :
                             load_misalign  ? 32'd4  :
                             store_misalign ? 32'd6  :
                             ecall_instr    ? 32'd11 :  // M-mode ecall
                             ebreak_instr   ? 32'd3  :
                             32'hxxxxxxxx;
  ```

### Step 2 — On Exception, Update CSRs and Flush Pipeline

- [ ] When `exception = 1` in EX stage:
  ```verilog
  // Save PC of faulting instruction to mepc
  csr_write_en = 1;
  csr_write_addr = 12'h341;  // mepc
  csr_write_data = pc_EX;
  
  // Update mcause
  csr_write_en = 1;
  csr_write_addr = 12'h342;  // mcause
  csr_write_data = mcause_value;
  
  // Jump to mtvec
  flush_pipeline = 1;
  next_pc = mtvec_value;  // From CSR file
  ```

- [ ] Flush the pipeline (like branch mispredict):
  - Clear IF/ID (stall new instructions from fetching)
  - Clear ID/EX (bubble out the faulting instruction)
  - PC jumps to mtvec

### Step 3 — Return from Exception (mret)

- [ ] Decode `mret` instruction (opcode=1110011, funct3=0, funct12=0x302):
  ```verilog
  if (funct12 == 12'h302) begin
    mret_inst = 1;  // Return from exception
  end
  ```

- [ ] When `mret` executes:
  ```verilog
  // Jump back to saved PC
  flush_pipeline = 1;
  next_pc = mepc_value;  // From CSR file
  ```

### Step 4 — Test Exception Handling

- [ ] Write test programs:
  - Divide by zero → caught, jump to handler
  - Illegal instruction → caught, jump to handler
  - Handler saves registers, calls ecall, returns via mret
  - Execution continues after mret

- [ ] **Test:** Run `make py_exceptions` — all exception types handled

**Concept check:**
> If an exception occurs inside the exception handler, can it be caught or does it cause a fault?

---

## Assignment G4 — Interrupt Handling (Timer Interrupts)

**Goal:** Handle external interrupts (like timer ticks).

### Concept: Interrupts vs Exceptions

- **Exception**: internal (illegal instr, misaligned access, ecall, ebreak)
- **Interrupt**: external (timer, I/O device) — can happen any time

Interrupts have:
- `mie` (machine interrupt enable) CSR — bits enable each interrupt type
- `mip` (machine interrupt pending) CSR — bits show which interrupts are pending
- If `mie[type] & mip[type]`, take the interrupt

### Step 1 — Add Interrupt Signals

- [ ] Add inputs to top module:
  - `timer_interrupt` (from CLINT)
  - `external_interrupt` (from PLIC)

- [ ] When `mie[7] & timer_interrupt`:
  - Take trap (same as exception)
  - mcause = 0x80000007 (bit 31 = interrupt, bits 30:0 = timer)

- [ ] **Test:** Run `make py_interrupts` — timer interrupt taken and handled

**Concept check:**
> If an interrupt occurs while handling an exception, what happens? Which takes priority?

---

## Completion Gate

Before calling Module 7 done:
- [ ] `make py_csr` passes CSR read/write tests
- [ ] `make py_csr_ops` passes all CSRRW/CSRRS/CSRRC tests
- [ ] `make py_exceptions` detects illegal instr, misaligned access, ecall
- [ ] Exception handler receives mepc and mcause correctly
- [ ] `mret` returns to saved PC
- [ ] Timer interrupts are detected and handled
- [ ] You can explain: why do we need separate mepc vs PC?

---

## Files Changed in Module 7

| File | Change |
|------|--------|
| `src/csr_file.v` | [NEW] 4096-entry CSR register file |
| `src/decoder.v` | [MODIFY] Decode CSRRW, CSRRS, CSRRC, ecall, ebreak, mret |
| `src/pipe_top.v` | [MODIFY] Exception detection, CSR writes, flush on trap/interrupt |
| `src/alu.v` | [MODIFY] Return old CSR value for read-modify-write |

---

## Machine Mode CSR Addresses

```
0x300 (mstatus)   — Global interrupt enable, privilege bits
0x301 (misa)      — Supported ISA extensions
0x304 (mie)       — Interrupt enable bits
0x305 (mtvec)     — Trap vector base address
0x340 (mscratch)  — Scratch register
0x341 (mepc)      — Exception program counter (saved PC)
0x342 (mcause)    — Exception/interrupt cause code
0x343 (mtval)     — Trap value (faulting address or instr)
0x344 (mip)       — Interrupt pending bits
```

## Exception Codes (mcause)

```
0x0  = Instruction address misaligned
0x1  = Instruction access fault
0x2  = Illegal instruction
0x3  = Breakpoint (ebreak)
0x4  = Load address misaligned
0x5  = Load access fault
0x6  = Store address misaligned
0x7  = Store access fault
0x8  = Environment call from U-mode
0x9  = Environment call from S-mode
0xB  = Environment call from M-mode (ecall)

Interrupts (mcause[31] = 1):
0x80000003 = Machine software interrupt (from CLINT)
0x80000007 = Machine timer interrupt (from CLINT)
0x8000000B = Machine external interrupt (from PLIC)
```
