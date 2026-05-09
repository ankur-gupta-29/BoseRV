# Module 2 — Advanced Verification with Cocotb: Learning Checklist

Work top-to-bottom. Each assignment builds on the previous.
Rule: **you write all Python test logic**. Ask teacher for hints if stuck.

---

## Why Do We Need This?

Module 1 works in simulation, but:
- Writing testbenches in Verilog is **tedious and error-prone**
- You want to test with **realistic programs**, not just hand-crafted vectors
- You want **high-level assertions** in Python, not waveforms

**Cocotb** lets you write testbenches purely in Python while driving Verilog simulation. Verilator compiles Verilog → C++, and Cocotb injects Python test coroutines.

```
Your Python code → Cocotb → Verilator simulation → Verilog behavior
```

---

## Assignment B1 — Setup Cocotb and Python Environment

**Goal:** Install tools, understand the Cocotb flow.

### Step 1 — Verify Tools

- [ ] Check Verilator installed:
  ```bash
  verilator --version
  ```

- [ ] Create Python virtual environment (optional but recommended):
  ```bash
  python3 -m venv .venv
  source .venv/bin/activate
  ```

- [ ] Install Cocotb:
  ```bash
  pip install cocotb cocotb-test pytest
  ```

- [ ] Install Python RISC-V utilities:
  ```bash
  pip install patchelf
  ```

### Step 2 — Understand Cocotb Flow

**Cocotb Architecture:**
```
Makefile
  ↓
Verilator compiles .v → C++ binary
  ↓
Cocotb wraps binary, runs Python tests
  ↓
Python test drives HDL simulation
```

**Key Cocotb Concepts:**
- **Coroutines:** async Python functions that drive simulation
- **Signals:** Python objects representing HDL signals
- **Assertions:** Check outputs match expected behavior

### Step 3 — Create Example Cocotb Test

- [ ] Read existing Cocotb example or documentation
- [ ] Understand: `@cocotb.test`, `dut`, `yield`, assertions

**Concept check:**
> In Cocotb, when you do `yield dut.clk.posedge`, what happens? Does it advance 1 cycle or wait for the clock to rise?

---

## Assignment B2 — Write Python Testbench for ALU

**File:** `tests/test_alu.py` (NEW)
**Goal:** Test `alu.v` using Python + Cocotb.

### Step 1 — Create `tests/test_alu.py`

- [ ] Import Cocotb:
  ```python
  import cocotb
  from cocotb.triggers import Timer
  import random
  ```

- [ ] Write a basic test:
  ```python
  @cocotb.test()
  async def test_alu_add(dut):
      """Test ALU ADD operation"""
      dut.alu_op.value = 4'b0000  # ADD
      dut.a.value = 10
      dut.b.value = 20
      await Timer(1, units='ns')  # Let combinational logic settle
      assert dut.result.value == 30, f"Expected 30, got {dut.result.value}"
  ```

- [ ] Write tests for all 10 ALU operations:
  - ADD, SUB, AND, OR, XOR
  - SLL, SRL, SRA
  - SLT, SLTU

- [ ] Include edge cases:
  - Negative numbers (for signed operations)
  - Shifting by 0 and 31
  - Zero results (check `zero` flag)

- [ ] **Test:** Run `make py_alu` — all tests pass

**Concept check:**
> Why do you need `await Timer(1, units='ns')` after setting inputs? What are you waiting for?

---

## Assignment B3 — Full Core Verification with Memory Vectors

**File:** `tests/test_top.py` (NEW)
**Goal:** Test the entire single-cycle core with realistic programs.

### Concept: Test Vector Format

A test program is a list of RISC-V instructions and expected results:
```python
tests = [
    {
        "name": "ADD",
        "program": [
            0x00300093,  # ADDI x1, x0, 3
            0x00500113,  # ADDI x2, x0, 5
            0x00208233,  # ADD x4, x1, x2
        ],
        "expected_registers": {
            1: 3,   # x1 = 3
            2: 5,   # x2 = 5
            4: 8,   # x4 = 8 (result of ADD)
        }
    }
]
```

### Step 1 — Create `tests/test_top.py`

- [ ] Load a test program into instruction memory
- [ ] Reset the core
- [ ] Clock through enough cycles for the program to complete (single-cycle = 1 cycle per instr)
- [ ] Check register file values match expected

  ```python
  @cocotb.test()
  async def test_add(dut):
      # Load instruction into imem
      dut.imem.mem[0].value = 0x00300093  # ADDI x1, x0, 3
      dut.imem.mem[1].value = 0x00500113  # ADDI x2, x0, 5
      dut.imem.mem[2].value = 0x00208233  # ADD x4, x1, x2
      
      # Reset
      dut.rst.value = 1
      await Timer(1, units='ns')
      dut.rst.value = 0
      
      # Clock 3 cycles (1 per instruction)
      for _ in range(3):
          await dut.clk.posedge
      
      # Check results
      assert dut.regfile.regs[1].value == 3
      assert dut.regfile.regs[2].value == 5
      assert dut.regfile.regs[4].value == 8
  ```

- [ ] Generate 20+ test programs covering:
  - Arithmetic: ADD, SUB, ADDI
  - Logic: AND, OR, XOR, ANDI, ORI, XORI
  - Shift: SLL, SRL, SRA
  - Compare: SLT, SLTU
  - Memory: LW, SW
  - Branches: BEQ, BNE, BLT, BGE
  - Jumps: JAL, JALR
  - Upper immediates: LUI, AUIPC

- [ ] **Test:** Run `make py_top` — all tests pass

**Concept check:**
> Why does a single-cycle program with 3 instructions only need 3 clock cycles, but what if the third instruction is a branch?

---

## Assignment B4 — Complete the RV32I Decoder (TDD)

**Goal:** Ensure ALL 47 RV32I instructions are correctly decoded.

### Concept: Test-Driven Development (TDD)

- Write test FIRST (red)
- See it fail (proves test works)
- Implement decoder logic (green)
- Refactor if needed

### Step 1 — Create Test Vectors for All 47 Instructions

- [ ] For each instruction in RV32I:
  - Generate a hex encoding
  - Test that decoder extracts correct fields (rs1, rs2, rd, imm)
  - Test that decoder outputs correct control signals

  ```python
  @cocotb.test()
  async def test_decode_addi(dut):
      # ADDI x1, x2, 100
      # Encoding: imm[11:0]=100, rs1=2, funct3=0, rd=1, opcode=0010011
      dut.instr.value = 0x06410093
      await Timer(1, units='ns')
      assert dut.rs1.value == 2
      assert dut.rd.value == 1
      assert dut.imm.value == 100
      assert dut.alu_op.value == 4'b0000  # ADD
      assert dut.alu_src.value == 1  # immediate
  ```

- [ ] Systematically add all 47 instructions:
  - LUI, AUIPC
  - JAL, JALR
  - BEQ, BNE, BLT, BGE, BLTU, BGEU (6 branches)
  - LB, LH, LW, LBU, LHU (5 loads)
  - SB, SH, SW (3 stores)
  - ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI (9 I-type)
  - ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND (10 R-type)

- [ ] **Test:** Run `make py_decoder` — all 47 instructions pass

### Step 2 — Fix Any Decoder Bugs

- [ ] As tests fail, update `src/decoder.v` to handle each instruction correctly
- [ ] Verify sign-extension works for all immediate types
- [ ] Verify control signal combinations are correct

**Concept check:**
> For the shift instructions (SLLI, SRLI, SRAI), what's the difference in the immediate encoding compared to ADDI?

---

## Completion Gate

Before calling Module 2 done:
- [x] Cocotb environment set up and working
- [x] `make py_alu` passes all ALU operation tests
- [x] `make py_top` passes all core integration tests
- [x] `make py_decoder` passes all 47 instruction decode tests
- [x] You understand: how Cocotb drives Verilator simulation
- [x] You understand: why TDD (test first) is valuable

---

## Files Changed in Module 2

| File | Change |
|------|--------|
| `tests/test_alu.py` | [NEW] Cocotb testbench for ALU |
| `tests/test_top.py` | [NEW] Cocotb testbench for single-cycle core |
| `tests/test_decoder.py` | [NEW] Cocotb testbench for decoder (all 47 instructions) |
| `Makefile` | [MODIFY] Add Cocotb test targets |

---

## Key Cocotb Patterns

```python
# Wait for clock edge
await dut.clk.posedge

# Set a signal
dut.signal_name.value = 42

# Read a signal
read_value = dut.signal_name.value

# Assert with custom message
assert result == expected, f"Got {result}, expected {expected}"

# Wait for combinational logic to settle
await Timer(1, units='ns')
```
