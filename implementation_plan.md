# BoseRV — RISC-V Processor Design Curriculum
## From Single-Cycle to Linux-Bootable Core with Verilator

> **Your project is called `BoseRV`** — a RISC-V core built from scratch, named after you.
> We will build it incrementally, with theory, Verilog implementation, and Verilator tests at each stage.

---

## Roadmap Overview

| Module | Topic | Tools | Goal |
|--------|-------|-------|------|
| **M1** | Single-Cycle RV32I Core | Verilog, iverilog | Execute all RV32I base instructions |
| **M2** | Verilator Integration & Self-Testing | Verilator, C++ | Replace iverilog with Verilator, write C++ testbenches |
| **M3** | 5-Stage Pipeline (IF/ID/EX/MEM/WB) | Verilog, Verilator | Classic textbook pipeline, no hazards yet |
| **M4** | Hazard Detection & Forwarding | Verilog | Data hazards, control hazards, stalls, bypasses |
| **M5** | RV32I + M Extension (Multiply/Divide) | Verilog | Add the M-extension to your pipeline |
| **M6** | Memory Subsystem (Cache + TLB basics) | Verilog | I-Cache, D-Cache, simple MMU |
| **M7** | Privileged ISA & CSRs | Verilog | Machine mode, trap handling, MTVEC, MEPC |
| **M8** | CLINT, PLIC, UART (Peripheral bus) | Verilog | Timer interrupts, MMIO peripherals |
| **M9** | Supervisor Mode + Sv32 MMU | Verilog | Virtual memory, page tables |
| **M10** | Linux Boot on BoseRV | QEMU, OpenSBI, Linux | Boot Linux using OpenSBI + your core |

---

## Module 1 — Single-Cycle RV32I Core

### Theory You Need to Know First

**What is RISC-V?**
- Open, royalty-free ISA specification maintained by RISC-V International
- RV32I = 32-bit base integer ISA (47 instructions)
- Registers: x0–x31 (32 general-purpose 32-bit registers; x0 is hardwired to 0)
- Program Counter (PC): starts at `0x00000000` (or `0x80000000` for Linux)

**Instruction Formats (RV32I has 6):**
```
R-type:  [funct7|rs2|rs1|funct3|rd|opcode]   — register-register ops
I-type:  [imm[11:0]|rs1|funct3|rd|opcode]     — loads, arithmetic imm, jalr
S-type:  [imm[11:5]|rs2|rs1|funct3|imm[4:0]|opcode] — stores
B-type:  [imm[12|10:5]|rs2|rs1|funct3|imm[4:1|11]|opcode] — branches
U-type:  [imm[31:12]|rd|opcode]               — LUI, AUIPC
J-type:  [imm[20|10:1|11|19:12]|rd|opcode]    — JAL
```

**Single-Cycle Datapath — 5 Stages in 1 clock:**
```
PC → IMEM → Decode → ALU → DMEM → Regfile Writeback
          ↑                              ↓
          ←————————— Control Unit ————————
```

**The 10 key instruction groups for RV32I:**
1. `LUI`, `AUIPC` — load upper immediate
2. `JAL`, `JALR` — jumps
3. `BEQ`,`BNE`,`BLT`,`BGE`,`BLTU`,`BGEU` — branches
4. `LB`,`LH`,`LW`,`LBU`,`LHU` — loads
5. `SB`,`SH`,`SW` — stores
6. `ADDI`,`SLTI`,`SLTIU`,`XORI`,`ORI`,`ANDI`,`SLLI`,`SRLI`,`SRAI` — I-type
7. `ADD`,`SUB`,`SLL`,`SLT`,`SLTU`,`XOR`,`SRL`,`SRA`,`OR`,`AND` — R-type

---

### BoseRV Module 1 — File Structure

```
riscv-core/
├── src/
│   ├── imem.v          ← Instruction memory (fixed)
│   ├── dmem.v          ← Data memory (fixed)
│   ├── regfile.v       ← Register file (fixed)
│   ├── alu.v           ← ALU (Assignment A1)
│   ├── decoder.v       ← Instruction decode + control (Assignment A2)
│   ├── fetch.v         ← PC + fetch stage (Assignment A3)
│   └── top.v           ← Top-level single-cycle core (Assignment A4)
├── sim/
│   ├── tb_alu.v        ← ALU testbench
│   ├── tb_fetch.v      ← Fetch testbench
│   └── tb_top.v        ← Full core testbench
├── tests/
│   ├── instr_mem.hex   ← Test program
│   └── gen_hex.py      ← Helper to generate hex from RISC-V asm
└── Makefile
```

---

### Assignments

#### **Assignment A1 — ALU** (`src/alu.v`)
Implement a 32-bit ALU supporting:
- `ADD`, `SUB`, `AND`, `OR`, `XOR`
- `SLL`, `SRL`, `SRA` (shifts)
- `SLT`, `SLTU` (signed/unsigned compare)
- For branches: `BEQ`, `BNE`, `BLT`, `BGE`, `BLTU`, `BGEU` → output a `zero` flag

**Op encoding (4-bit):**
```
0000 = ADD    0001 = SUB    0010 = AND    0011 = OR
0100 = XOR    0101 = SLL    0110 = SRL    0111 = SRA
1000 = SLT    1001 = SLTU
```
**Deliverable:** Complete `alu.v` + run `make alu_sim` (all tests pass)

---

#### **Assignment A2 — Instruction Decoder** (`src/decoder.v`)
Given a 32-bit instruction, decode and output:
- `rs1`, `rs2`, `rd` (5-bit register addresses)
- `imm` (32-bit sign-extended immediate)
- `alu_op` (4-bit op for the ALU)
- `alu_src` — 0=register, 1=immediate
- `mem_read`, `mem_write` — memory control
- `reg_write` — write result to regfile
- `branch`, `jump` — PC control
- `pc_src` — where next PC comes from

**Deliverable:** Complete `decoder.v` + trace through 5 instructions manually

---

#### **Assignment A3 — Fetch Stage** (`src/fetch.v`)
Implement the PC register + fetch logic:
- On reset, PC = `32'h00000000`
- Each cycle: `PC <= PC + 4` (unless branch/jump overrides)
- Output: `pc`, `instr` (from imem)

**Deliverable:** Complete `fetch.v` + run `make fetch_sim`

---

#### **Assignment A4 — Top-Level Core** (`src/top.v`)
Wire all modules together:
- `fetch.v` → `decoder.v` → `alu.v` → `dmem.v` → `regfile.v`
- Control signals from decoder drive everything
- Correctly compute `PC + 4`, `PC + imm` (branch), and `rs1 + imm` (JALR)

**Deliverable:** Complete `top.v` + run test program that computes `5 + 20 = 25`, stores to memory, and halts

---

## Module 2 — Verilator + C++ Testbenches

### Theory
- Verilator compiles Verilog to C++ for **cycle-accurate simulation** (10-100x faster than iverilog)
- You write a C++ `main()` that drives clock, resets, and checks outputs
- Outputs: VCD waveforms, pass/fail assertions, coverage

### Assignments
- **B1**: Install Verilator, convert `tb_alu.v` to a C++ testbench
- **B2**: Write a self-checking C++ testbench for the full single-cycle core
  - Load 50 RISC-V instructions, compare register file state to a golden reference

---

## Module 3 — 5-Stage Pipeline

### Theory — The Classic 5 Stages
```
Cycle:  1    2    3    4    5    6    7
Instr1: IF → ID → EX → MEM→ WB
Instr2:      IF → ID → EX → MEM→ WB
Instr3:           IF → ID → EX → MEM→ WB
```
**Pipeline registers:** IF/ID, ID/EX, EX/MEM, MEM/WB — store intermediate state

### Assignments
- **C1**: Add the 4 pipeline registers to your datapath
- **C2**: Verify basic execution (no hazards yet — insert NOPs manually)
- **C3**: Measure CPI (Cycles Per Instruction) with and without NOPs

---

## Module 4 — Hazard Handling

### Theory — 3 Types of Hazards
1. **Data Hazard (RAW)** — Instruction reads register being written by previous instruction
   - Solution: **Forwarding** (bypass from EX/MEM or MEM/WB stage)
   - When forwarding impossible: **Stall** (insert bubble)
2. **Control Hazard** — Branch outcome not known until EX stage
   - Solution: **Predict not-taken**, flush on misprediction (2-cycle penalty)
   - Advanced: **Branch prediction** (later)
3. **Structural Hazard** — Two instructions need same HW resource
   - Solution: Separate I-Cache and D-Cache (eliminate for our design)

### Assignments
- **D1**: Implement forwarding unit
- **D2**: Implement hazard detection unit (stall insertion)
- **D3**: Implement branch flush (predict not-taken)
- **D4**: Run compliance test suite with `riscv-tests`

---

## Module 5 — M Extension

### Theory
- Adds: `MUL`, `MULH`, `MULHSU`, `MULHU`, `DIV`, `DIVU`, `REM`, `REMU`
- Multi-cycle: Division takes up to 32 cycles → stall pipeline while computing
- Opcode: All M-extension ops have `funct7 = 0000001`

### Assignments
- **E1**: Add `mul` to ALU (combinational, 1-cycle)
- **E2**: Add iterative divider (32-cycle) — pipeline stalls during division

---

## Module 6 — Cache & Memory

### Theory
- Direct-mapped I-Cache (4KB, 64B lines)
- Direct-mapped D-Cache (4KB, write-through)
- Cache miss → stall pipeline

### Assignments
- **F1**: Implement I-Cache with hit/miss logic
- **F2**: Implement D-Cache
- **F3**: Measure cache hit rate on a bubble sort program

---

## Module 7 — Privileged ISA (Machine Mode)

### Theory — RISC-V Privilege Levels
```
Level 3: Machine Mode (M-mode)   — Always present, highest privilege
Level 1: Supervisor Mode (S-mode) — For OS kernel
Level 0: User Mode (U-mode)       — For user applications
```
**Key CSRs (Control and Status Registers):**
- `mstatus` — global interrupt enable, privilege bits
- `mtvec` — trap vector (where to jump on exception)
- `mepc` — exception PC (return address)
- `mcause` — reason for trap
- `mie/mip` — interrupt enable/pending
- `mscratch` — scratch register for M-mode

**Trap flow:**
```
Exception occurs → save PC to mepc → jump to mtvec → handle → mret
```

### Assignments
- **G1**: Add CSR register file (4096 CSRs addressed by 12-bit)
- **G2**: Implement `csrrw`, `csrrs`, `csrrc`, `csrrwi`, `csrrsi`, `csrrci`
- **G3**: Implement trap entry: mepc←PC, mstatus←updated, PC←mtvec
- **G4**: Implement `mret` (return from trap)
- **G5**: Test with a timer interrupt handler

---

## Module 8 — Peripherals (CLINT, UART)

### Theory — MMIO Bus
- Memory-mapped I/O: peripherals appear as memory addresses
- **CLINT** (Core Local Interruptor): Timer at `0x02000000`, generates `mtime` interrupt
- **UART** (MMIO): TX/RX registers at fixed addresses — used for `putchar()` in OpenSBI

### Assignments
- **H1**: Implement simple address decoder (MMIO router)
- **H2**: Implement CLINT with `mtime` / `mtimecmp`
- **H3**: Implement UART TX (just a write-to-stdout for simulation)

---

## Module 9 — Supervisor Mode + Virtual Memory (Sv32)

### Theory — Sv32 Page Tables
- 32-bit virtual address → 4KB pages
- Two-level page table: VPN[1] (10 bits) → VPN[0] (10 bits) → PPN + offset
- `satp` CSR: controls page table base address and mode
- **TLB** (Translation Lookaside Buffer): cache of recent translations

### Assignments
- **I1**: Add S-mode CSRs: `sstatus`, `stvec`, `sepc`, `scause`, `satp`
- **I2**: Implement PTW (Page Table Walker) on D-Cache miss
- **I3**: Implement TLB (16-entry, direct-mapped)
- **I4**: Boot OpenSBI in M-mode (it jumps to S-mode kernel)

---

## Module 10 — Booting Linux

### Theory — Boot Sequence
```
Power On
  → MROM (reset vector at 0x1000)
  → OpenSBI firmware (M-mode)
      → Sets up CLINT, UART, page tables
      → Jumps to Linux kernel (S-mode)
          → Mounts rootfs
          → Runs /init
          → Shell!
```

### Tools & Build
- **OpenSBI**: M-mode firmware, handles SBI calls from Linux
- **Linux Kernel**: Configured with `rv32_defconfig`
- **Buildroot**: Creates minimal rootfs (BusyBox shell)
- **QEMU** (for reference): Validate your Linux boots on qemu-system-riscv32 first

### Assignments
- **J1**: Run `qemu-system-riscv32` with OpenSBI and see boot log
- **J2**: Boot OpenSBI on your Verilator simulation (M-mode only)
- **J3**: Enable S-mode + MMU → boot Linux kernel
- **J4**: Full Linux boot with BusyBox shell

---

## Verification Strategy (Every Module)

| Level | Tool | What it checks |
|-------|------|----------------|
| Unit | iverilog/Verilator | Individual module correctness |
| Integration | Verilator C++ TB | Full core against golden reference |
| Compliance | riscv-tests | Official RISC-V compliance suite |
| System | OpenSBI/Linux boot | End-to-end correctness |

---

## Prerequisites to Install Now

```bash
# Verilog simulator
sudo apt install iverilog gtkwave

# Verilator
sudo apt install verilator

# RISC-V toolchain (for assembling test programs)
sudo apt install gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu

# Or get the 32-bit bare-metal toolchain:
sudo apt install gcc-riscv64-unknown-elf

# QEMU for Linux boot validation
sudo apt install qemu-system-misc
```

---

## Current State of Your `BoseRV` Skeleton

| File | Status | Issue |
|------|--------|-------|
| `imem.v` | ⚠️ Has bugs | Port syntax errors, wrong var names |
| `dmem.v` | ⚠️ Has bugs | Missing `begin`/`end` match |
| `regfile.v` | ⚠️ Skeleton only | No implementation |
| `alu.v` | ⚠️ Skeleton only | No implementation |

**We will fix all these as part of Assignment A1–A4.**

---

## Where We Start Right Now

**Current session goal:** Fix the buggy skeleton files, implement the complete ALU (A1), and get your first successful simulation running.
