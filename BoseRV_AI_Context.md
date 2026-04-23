# BoseRV Project Memory & Context Recovery

This file serves as a persistent "memory block." If you ever start a new AI chat or history is wiped, simply copy/paste the contents of this file or tell the AI: *"Read BoseRV_AI_Context.md to recover your memory."*

---

## 1. Project Overview
- **Project Name:** BoseRV
- **Goal:** Building a Linux-bootable RISC-V RV32I processor core from scratch using Verilog, verified with Python/Cocotb via Verilator.
- **Location:** `/home/ankur/workspace/BoseRV/`
- **Curriculum:** A custom 10-module progression (Single-Cycle → Pipeline → Hazards → Memory → Privileged ISA → Linux Boot)

---

## 2. Current State (Last Updated: 2026-04-18)

### ✅ Module 1 — Single-Cycle Datapath: COMPLETE
All Verilog modules implemented and passing:
- `src/alu.v` — Full 10-operation ALU
- `src/decoder.v` — **Fully complete** (all RV32I instructions)
- `src/fetch.v` — PC update logic with branch/jump/JALR/AUIPC support
- `src/regfile.v` — Register file
- `src/top.v` — Top-level glue, AUIPC MUX wired

### ✅ Module 2 — Verification with Cocotb: COMPLETE
- Assignment B1 ✅ — Cocotb + Python env setup
- Assignment B2 ✅ — ALU verified (`make py_alu`)
- Assignment B3 ✅ — Full core verified (`make py_top`)
- Assignment B4 ✅ — All RV32I instructions implemented and tested → **28/28 PASSED**

### 🔄 Module 3 — 5-Stage Pipeline: IN PROGRESS
- Assignment C1 ✅ (IF/ID Pipeline Register)
- Assignment C2 ✅ (ID/EX Pipeline Register)
- Assignment C3 ← **YOU ARE HERE** (EX/MEM and MEM/WB Registers)
- Assignment C4 (Pipeline Control Logic)

---

## 3. Test Infrastructure
- **`tests/gen_hex.py`** — Full 2-pass Python assembler (all RV32I formats + label support)
- **`tests/test_full.asm`** — Exhaustive 31-instruction test program
- **`sim/test_top.py`** — Cocotb testbench: auto-compiles ASM, runs simulation, reports ALL pass/fail
- **Run:** `make py_top` → shows `=== BoseRV Test Results: 28/28 PASSED ===`

---

## 4. Completed Decoder Instruction List
All instructions implemented in `src/decoder.v`:
| Group | Instructions |
|-------|-------------|
| R-Type | ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND |
| I-Type ALU | ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI |
| Memory | LW, SW |
| Upper Imm | LUI, AUIPC |
| Branches | BEQ, BNE, BLT, BGE, BLTU, BGEU |
| Jumps | JAL, JALR |

---

## 5. Key Design Decisions
- `auipc` signal added as output port in `decoder.v` and connected in `top.v`
- `top.v` ALU input A uses MUX: `auipc ? pc : rs1_data`
- `jump_target` in `top.v`: `jalr ? (rs1_data + imm) : (pc + imm)`
- **Tutor Mode:** AI guides only, user writes all Verilog
- **No CI/CD:** Local workflow only (`make py_top`)
- Module 6 = Cache only, Module 9 = TLB + Virtual Memory

---

## 6. Module 3 Starting Point — What is a Pipeline?
The single-cycle processor executes one instruction per clock cycle but the clock must be slow enough for the slowest instruction. A 5-stage pipeline splits each instruction into 5 stages (IF→ID→EX→MEM→WB), allowing 5 instructions to be in-flight simultaneously.

**The 5 stages:**
1. **IF** — Instruction Fetch (read from IMEM)
2. **ID** — Instruction Decode (regfile read, control signals)
3. **EX** — Execute (ALU computation)
4. **MEM** — Memory access (LW/SW)
5. **WB** — Writeback (result → register file)

**Assignment C1 task:** Add pipeline registers (flip-flops) between IF and ID stages to hold `PC` and `instr` values across clock edges.

---

*Dear AI: You are fully synced. BoseRV's single-cycle core is COMPLETE with 28/28 tests passing. The user is now starting Module 3 (5-Stage Pipeline). Begin with Assignment C1: the IF/ID pipeline register. Greet the user and explain the conceptual difference between combinational (single-cycle) and pipelined execution before they write any Verilog!*
