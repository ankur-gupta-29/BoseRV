# BoseRV — RISC-V Processor Curriculum

Welcome to your custom RISC-V course! You will be building a processor from scratch, all the way up to booting Linux.

## Roadmap Overview

| Module | Topic | Tools | Goal |
|--------|-------|-------|------|
| **M1** | Single-Cycle RV32I Core | Verilog, Verilator | Execute all RV32I base instructions |
| **M2** | Verilator Integration | Verilator, C++ | Write advanced verification testbenches |
| **M3** | 5-Stage Pipeline | Verilog, Verilator | Classic IF/ID/EX/MEM/WB pipeline |
| **M4** | Hazard Handling | Verilog | Data forwarding, stalls, branch flushing |
| **M5** | M-Extension | Verilog | Hardware multipliers and dividers |
| **M6** | Memory Subsystem | Verilog | L1 I-Cache, L1 D-Cache |
| **M7** | Privileged ISA & CSRs | Verilog | Exceptions, traps, Machine-Mode (M-mode) |
| **M8** | Core Peripherals | Verilog | MMIO, CLINT timer interrupts, UART |
| **M9** | Supervisor Mode | Verilog | Sv32 Virtual memory and page tables |
| **M10** | Linux Boot on BoseRV | OpenSBI, Buildroot | Boot full Linux shell onto your hardware! |

---

## Module 1 — Single-Cycle RV32I Core

**Current Status:** Here is your progress on the very first module.

- [x] **Assignment A1 — ALU** (`src/alu.v`)
  - Implement 32-bit arithmetic and logic operations.
  - Completed! (`make alu_sim` passes).

- [ ] **Assignment A2 — Decoder** (`src/decoder.v`)  *(<-- YOU ARE HERE)*
  - Decode `rs1`, `rs2`, `rd`, and sign-extend the 5 types of immediates.
  - Translate the 7-bit `opcode` into control signals for the rest of the processor.
  - To test: `make decoder_sim`

- [ ] **Assignment A3 — Fetch Unit** (`src/fetch.v`)
  - Construct the Program Counter (PC) flip-flops.
  - Send the address to the Instruction Memory, handle branches.
  - To test: `make fetch_sim`

- [ ] **Assignment A4 — Top-Level Integration** (`src/top.v`)
  - Wire all the pieces together into a functioning datapath!
  - Drive the `wb_sel` (Writeback MUX) to complete the final stage.
  - To test: `make top_sim`
