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

- [x] **Assignment A2 — Decoder** (`src/decoder.v`)
  - Decode `rs1`, `rs2`, `rd`, and sign-extend the 5 types of immediates.
  - Translate the 7-bit `opcode` into control signals for the rest of the processor.
  - Completed! (`make decoder_sim` passes).

- [x] **Assignment A3 — Fetch Unit** (`src/fetch.v`)
  - Construct the Program Counter (PC) flip-flops.
  - Send the address to the Instruction Memory, handle branches.
  - Completed! (`make fetch_sim` passes).

- [x] **Assignment A4 — Top-Level Integration** (`src/top.v`)
  - Wire all the pieces together into a functioning datapath!
  - Drive the `wb_sel` (Writeback MUX) to complete the final stage.
  - Completed! (`make top_sim` passes).

---

## Module 2 — Advanced Verification with Cocotb
- [x] Assignment B1 — Setup Cocotb and Python Environment 
- [x] Assignment B2 — Write a Python Testbench for the ALU (`test_alu.py`)
- [ ] Assignment B3 — Full Core Verification with memory vectors in Python *(<-- YOU ARE HERE)*
- [ ] Assignment B4 — Complete the RV32I Decoder (TDD all remaining instructions!)

---

## Module 3 — 5-Stage Pipeline
*(Locked until Module 2 is finished)*
- [ ] Assignment C1 — IF/ID Pipeline Register
- [ ] Assignment C2 — ID/EX Pipeline Register
- [ ] Assignment C3 — EX/MEM and MEM/WB Registers
- [ ] Assignment C4 — Pipeline Control Logic

---

## Module 4 — Hazard Handling
*(Locked until Module 3 is finished)*
- [ ] Assignment D1 — Data Forwarding Unit (Bypassing)
- [ ] Assignment D2 — Hazard Detection Unit (Stalls / Bubbles)
- [ ] Assignment D3 — Control Hazards (Branch Flushing)

---

## Module 5 — M-Extension
*(Locked until Module 4 is finished)*
- [ ] Assignment E1 — Multiplier Unit (Hardware Multiplication)
- [ ] Assignment E2 — Divider Unit (State Machine Division)
- [ ] Assignment E3 — Decoder Updates

---

## Module 6 — Memory Subsystem
*(Locked until Module 5 is finished)*
- [ ] Assignment F1 — L1 Instruction Cache
- [ ] Assignment F2 — L1 Data Cache
- [ ] Assignment F3 — Cache Controller / Memory interface

---

## Module 7 — Privileged ISA & CSRs
*(Locked until Module 6 is finished)*
- [ ] Assignment G1 — Control & Status Registers (CSRs)
- [ ] Assignment G2 — Trap & Exception Handler logic
- [ ] Assignment G3 — Machine Mode instructions (`mret`, `ecall`)

---

## Module 8 — Core Peripherals
*(Locked until Module 7 is finished)*
- [ ] Assignment H1 — Memory-Mapped I/O (MMIO) Router
- [ ] Assignment H2 — CLINT (Core Local Interruptor / Timers)
- [ ] Assignment H3 — Simple UART & Boot ROM

---

## Module 9 — Supervisor Mode (MMU)
*(Locked until Module 8 is finished)*
- [ ] Assignment I1 — Supervisor Mode CSRs
- [ ] Assignment I2 — Sv32 Page Table Walker (Virtual Memory)
- [ ] Assignment I3 — TLB (Translation Lookaside Buffer)

---

## Module 10 — Linux Boot on BoseRV
*(Locked until Module 9 is finished)*
- [ ] Assignment J1 — OpenSBI Integration
- [ ] Assignment J2 — Device Tree Blob (DTB) Configuration
- [ ] Assignment J3 — Booting Buildroot Linux via C++ Verilator Wrapper!
