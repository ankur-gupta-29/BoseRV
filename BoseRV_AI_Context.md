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
All Verilog modules are implemented and passing the Verilog testbench (`make top_sim`):
- `src/alu.v` — Full 10-operation ALU
- `src/decoder.v` — Partially complete (see below)
- `src/fetch.v` — PC update logic with branch/jump support
- `src/regfile.v` — Register file
- `src/top.v` — Top-level glue wiring all modules

### 🔄 Module 2 — Verification with Cocotb: IN PROGRESS
- Assignment B1 ✅ (Cocotb + Python env setup, `.venv/`)
- Assignment B2 ✅ (ALU verified with `test_alu.py` → `make py_alu`)
- Assignment B3 ✅ (Full core verified with `test_top.py` → `make py_top`)
- Assignment B4 🔄 (TDD to complete all RV32I instructions in `decoder.v`)

---

## 3. The Critical Issue — What Needs to Be Done

**The exhaustive test suite (`make py_top`) currently reports 19 FAILING instructions:**

| Register | Instruction | Status |
|----------|-------------|--------|
| x6  | `SLL`  | ❌ |
| x7  | `SLT`  | ❌ |
| x9  | `XOR`  | ❌ |
| x10 | `SRL`  | ❌ |
| x11 | `SRA`  | ❌ |
| x12 | `OR`   | ❌ |
| x13 | `AND`  | ❌ |
| x14 | `SLTI` | ❌ |
| x15 | `SLTIU`| ❌ |
| x16 | `XORI` | ❌ |
| x17 | `ORI`  | ❌ |
| x18 | `ANDI` | ❌ |
| x19 | `SLLI` | ❌ |
| x20 | `SRLI` | ❌ |
| x21 | `SRAI` | ❌ |
| x22 | `LW/SW`| ❌ |
| x23 | `LUI`  | ❌ |
| x24 | `AUIPC`| ❌ |
| x26 | `JAL Link` | ❌ |

**What's already passing:** `ADDI`, `ADD`, `SUB`, `SLTU`, `BEQ`, `BNE`, `JAL Jump`

**Root Cause:** `src/decoder.v` only has `funct3`/`funct7` case entries for a handful of instructions. The `OP_REG`, `OP_IMM`, and `OP_BRANCH` blocks are missing most cases.

**The Fix:** Open `src/decoder.v` and add the missing `funct3` case statements under `OP_REG` and `OP_IMM`. The ALU operation codes are defined at the top of `src/alu.v`:
```
4'b0000 = ADD    4'b0001 = SUB
4'b0010 = AND    4'b0011 = OR
4'b0100 = XOR    4'b0101 = SLL
4'b0110 = SRL    4'b0111 = SRA
4'b1000 = SLT    4'b1001 = SLTU
```

---

## 4. Test Infrastructure (What We Built This Session)

- **`tests/gen_hex.py`** — Full 2-pass Python assembler supporting all RV32I instruction formats including labels for branches and jumps.
- **`tests/test_full.asm`** — Exhaustive assembly program testing all 31 core instructions.
- **`sim/test_top.py`** — Cocotb Python testbench that auto-compiles `test_full.asm`, runs the simulation, and reports ALL failing instructions at once instead of stopping at the first failure.

---

## 5. Key Design Decisions & Preferences
- **Verification:** Pure Python using Cocotb + Pytest. No raw C++ Verilator wrappers.
- **Toolchain:** `make py_top` runs the full test suite. `make top_sim` runs the old Verilog testbench.
- **Tutor Mode:** The AI acts as a tutor — explains, hints, and reviews but does NOT write the user's Verilog for them.
- **No CI/CD:** The user keeps this entirely local. No GitHub Actions workflow.
- **Module 6 scope:** Cache only. TLB and Virtual Memory are strictly Module 9.
- **Module 4 includes:** Assignment D4 — 2-bit Branch Predictor (BHT).

---

## 6. Obsidian Graph View
- The Obsidian dashboard file is at `BoseRV_Dashboard.md` (root of the project).
- Symlink the full project into Obsidian vault: `ln -s /home/ankur/workspace/BoseRV /home/ankur/Dropbox/PhD_Work/BoseRV_Project`

---

*Dear AI: You are now fully synced to Session 4. Greet the user and tell them they have 19 failing instructions left to implement in `src/decoder.v`. Ask which instruction they want to tackle first!*
