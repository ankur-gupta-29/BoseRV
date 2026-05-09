# Module 6 — Memory Subsystem (L1 Caches): Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Verilog logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

Memory (RAM) is **slow** — 100+ cycles to fetch from DRAM. Caches are **fast memories** near the processor that store recently-used data. Without caches, your CPU spends 99% of time waiting.

```
CPU registers (1 cycle) → L1 Cache (4 cycles) → L2 Cache (20 cycles) → DRAM (100+ cycles)
```

Module 6 adds:
- **L1 Instruction Cache (I-Cache)**: 4KB, 64B lines, direct-mapped
- **L1 Data Cache (D-Cache)**: 4KB, 64B lines, write-through

---

## Assignment F1 — L1 Instruction Cache

**File:** `src/icache.v` (NEW — you create this)
**Goal:** Cache fetched instructions, reduce fetch latency to IMEM.

### Concept: Direct-Mapped Cache

A direct-mapped cache has:
- **Lines**: blocks of memory (64 bytes = 16 words)
- **Tag**: upper address bits (which memory location)
- **Index**: selects which cache line
- **Offset**: byte within the line

```
Address [31:0]:  [tag (20) | index (6) | offset (6)]
                  bits 31-12    bits 11-6   bits 5-0

  4KB cache / 64B lines = 64 lines → 6-bit index
  64-byte line → 6-bit byte offset (use bits [3:2] for 32-bit word select within line)
  Tag = remaining 32 - 6 - 6 = 20 bits
```

Entry structure (simplified — word-granular for teaching clarity):
```
valid (1 bit) | tag (20 bits) | data (32 bits) = 53 bits per entry
On miss: fetch one 32-bit word from memory (not full cache line — simplification)
```

### Step 1 — Create `src/icache.v`

- [ ] Declare module:
  - Inputs: `clk, rst`, `addr [31:0]` (fetch address), `imem_data [31:0]`, `imem_valid` (from memory)
  - Outputs: `data [31:0]` (instruction), `hit` (1 if in cache)

- [ ] Implement cache table (64 entries, word-granular):
  ```verilog
  reg        cache_valid [0:63];
  reg [19:0] cache_tag   [0:63];
  reg [31:0] cache_data  [0:63];
  
  wire [5:0]  index = addr[11:6];   // 6 bits → 64 lines
  wire [19:0] tag   = addr[31:12];  // 20 bits
  ```

- [ ] Implement hit logic:
  ```verilog
  wire hit = cache_valid[index] & (cache_tag[index] == tag);
  assign data = cache_data[index];
  ```

- [ ] On miss, initiate memory fetch (write data when imem_valid arrives)

- [ ] **Test:** Run `make py_icache` — hit/miss behavior correct

**Concept check:**
> If your program loops forever at address 0x1000, does every fetch hit the cache after the first time?

---

## Assignment F2 — L1 Data Cache (Write-Through)

**File:** `src/dcache.v` (NEW — you create this)
**Goal:** Cache loaded data, reduce load latency; write through to memory.

### Concept: Write-Through vs Write-Back

- **Write-Through**: Write goes to both cache AND memory immediately (slow but simple)
- **Write-Back**: Write goes to cache only, memory updated later (fast but complex)

For simplicity, use **write-through**.

### Step 1 — Create `src/dcache.v`

- [ ] Similar structure to I-Cache:
  - Inputs: `clk, rst`, `addr [31:0]`, `data_in [31:0]` (from ALU), `mem_read`, `mem_write`
  - Outputs: `data_out [31:0]` (loaded data), `hit`

- [ ] On **read (mem_read=1)**:
  - If hit: return cached data
  - If miss: initiate memory read, wait for valid

- [ ] On **write (mem_write=1)**:
  - Write to cache AND memory simultaneously (write-through)
  - Always succeeds (no stall needed)

- [ ] **Test:** Run `make py_dcache` — load/store behavior correct

**Concept check:**
> In write-through, why don't you need to stall on writes? What about reads?

---

## Assignment F3 — Cache Integration & Performance Measurement

**Goal:** Wire caches into pipeline, measure hit rate.

### Step 1 — Integrate I-Cache into Fetch Stage

- [ ] Replace direct imem connection with icache:
  ```verilog
  icache icache_inst (
    .clk(clk), .rst(rst),
    .addr(pc),
    .data_out(instr),
    .hit(icache_hit),
    .imem_data(imem_data), .imem_valid(imem_valid)
  );
  
  // Stall if miss
  icache_miss = ~icache_hit;
  ```

### Step 2 — Integrate D-Cache into Memory Stage

- [ ] Replace direct dmem connection with dcache:
  ```verilog
  dcache dcache_inst (
    .clk(clk), .rst(rst),
    .addr(alu_result_MEM),
    .data_in(rs2_data_MEM),
    .mem_read(mem_read_MEM), .mem_write(mem_write_MEM),
    .data_out(mem_data),
    .hit(dcache_hit)
  );
  
  // Stall if load miss
  dcache_miss = mem_read_MEM & ~dcache_hit;
  ```

### Step 3 — Test with Real Program

- [ ] Write a program that repeatedly loads from same address (should hit cache):
  ```asm
  ADDI x1, x0, 0      # x1 = base address
  LOOP:
    LW x2, 0(x1)       # Load from [x1]
    ADDI x3, x3, 1     # Increment counter
    BLT x3, x0, LOOP   # Loop 100 times
  ```

- [ ] Measure cache hit rate:
  ```python
  total_accesses = icache_accesses + dcache_accesses
  total_hits = icache_hits + dcache_hits
  hit_rate = total_hits / total_accesses
  ```

- [ ] **Test:** Run `make py_pipe_top` with cache enabled, measure hit rate > 90% on looping program

**Concept check:**
> In a nested loop (loop within a loop), what's the I-Cache hit rate for the inner loop's instructions?

---

## Completion Gate

Before calling Module 6 done:
- [ ] `make py_icache` passes cache hit/miss tests
- [ ] `make py_dcache` passes load/store tests
- [ ] `make py_pipe_top` still passes all base tests with caches integrated
- [ ] Pipeline stalls on I-Cache miss (fetch blocked)
- [ ] Pipeline stalls on D-Cache load miss (read blocked)
- [ ] Measured hit rate > 90% on typical looping programs
- [x] You can explain: why write-through simplifies cache design

---

## Files Changed in Module 6

| File | Change |
|------|--------|
| `src/icache.v` | [NEW] 4KB direct-mapped I-Cache |
| `src/dcache.v` | [NEW] 4KB direct-mapped D-Cache, write-through |
| `src/pipe_top.v` | [MODIFY] Integrate caches, add miss stall logic |
| `src/fetch.v` | [MODIFY] Use I-Cache instead of direct imem |

---

## Cache Configuration

```
I-Cache:
  Size: 4KB (4096 bytes)
  Line: 64 bytes (16 words)
  Lines: 64 (4096 / 64)
  Index: bits [11:6] (6 bits = 64 lines)
  Tag:   bits [31:12] (20 bits)

D-Cache:
  Size: 4KB
  Line: 64 bytes
  Lines: 64
  Index: bits [11:6]
  Tag:   bits [31:12]
```

Hit latency: 1 cycle
Miss latency: 100+ cycles (stall pipeline)
