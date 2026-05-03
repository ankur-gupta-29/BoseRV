"""
BoseRV — Module 4 Hazard Unit Test (test_hazard.py)
=====================================================
Tests the forwarding unit and load-use hazard detection unit
IN ISOLATION before the full pipeline test.

Run with:  make py_hazard

Tests are grouped:
  SECTION A — Forwarding unit (D1)
  SECTION B — Hazard detection unit (D2)
  SECTION C — Full pipeline with hazards fixed (D1+D2+D3)
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer
from cocotb_test.simulator import run
from pathlib import Path
import subprocess, shutil, os


# =========================================================================
# SECTION A — Forwarding Unit Tests (forwarding.v)
# =========================================================================

@cocotb.test()
async def test_forwarding_no_hazard(dut):
    """A1: No hazard — both outputs should be 00 (use register file)"""
    dut.rs1_EX.value = 1
    dut.rs2_EX.value = 2
    dut.rd_MEM.value  = 5   # different register — no conflict
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 6   # different register — no conflict
    dut.reg_write_WB.value  = 1
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b00, f"forward_A should be 00 (no hazard), got {dut.forward_A.value}"
    assert dut.forward_B.value == 0b00, f"forward_B should be 00 (no hazard), got {dut.forward_B.value}"

@cocotb.test()
async def test_forwarding_ex_ex_rs1(dut):
    """A2: EX-EX hazard on rs1 — forward_A should be 10"""
    dut.rs1_EX.value = 3    # EX stage reading x3
    dut.rs2_EX.value = 2
    dut.rd_MEM.value  = 3   # MEM stage writing x3 — hazard!
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 0
    dut.reg_write_WB.value  = 0
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b10, f"forward_A should be 10 (EX-EX), got {dut.forward_A.value}"
    assert dut.forward_B.value == 0b00, f"forward_B should be 00 (no hazard on rs2), got {dut.forward_B.value}"

@cocotb.test()
async def test_forwarding_ex_ex_rs2(dut):
    """A3: EX-EX hazard on rs2 — forward_B should be 10"""
    dut.rs1_EX.value = 1
    dut.rs2_EX.value = 4    # EX stage reading x4
    dut.rd_MEM.value  = 4   # MEM stage writing x4 — hazard!
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 0
    dut.reg_write_WB.value  = 0
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b00, f"forward_A should be 00, got {dut.forward_A.value}"
    assert dut.forward_B.value == 0b10, f"forward_B should be 10 (EX-EX on rs2), got {dut.forward_B.value}"

@cocotb.test()
async def test_forwarding_mem_wb_rs1(dut):
    """A4: MEM-WB hazard on rs1 (no EX-EX conflict) — forward_A should be 01"""
    dut.rs1_EX.value = 7    # EX stage reading x7
    dut.rs2_EX.value = 2
    dut.rd_MEM.value  = 5   # MEM stage: different reg, no conflict
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 7   # WB stage writing x7 — MEM-WB hazard
    dut.reg_write_WB.value  = 1
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b01, f"forward_A should be 01 (MEM-WB), got {dut.forward_A.value}"
    assert dut.forward_B.value == 0b00, f"forward_B should be 00, got {dut.forward_B.value}"

@cocotb.test()
async def test_forwarding_mem_wb_rs2(dut):
    """A5: MEM-WB hazard on rs2 (no EX-EX conflict) — forward_B should be 01"""
    dut.rs1_EX.value = 1
    dut.rs2_EX.value = 9    # EX stage reading x9
    dut.rd_MEM.value  = 0   # MEM stage: x0, reg_write=1 but x0 is special
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 9   # WB stage writing x9
    dut.reg_write_WB.value  = 1
    await Timer(1, unit="ns")
    assert dut.forward_B.value == 0b01, f"forward_B should be 01 (MEM-WB on rs2), got {dut.forward_B.value}"

@cocotb.test()
async def test_forwarding_ex_ex_wins_over_mem_wb(dut):
    """A6: Both EX-EX and MEM-WB match rs1 — EX-EX (10) must win (higher priority)"""
    dut.rs1_EX.value = 5
    dut.rs2_EX.value = 2
    dut.rd_MEM.value  = 5   # EX-EX hazard on rs1
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 5   # MEM-WB hazard on rs1 too
    dut.reg_write_WB.value  = 1
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b10, f"forward_A should be 10 (EX-EX wins), got {dut.forward_A.value}"

@cocotb.test()
async def test_forwarding_no_forward_to_x0(dut):
    """A7: rd=x0 must NEVER trigger forwarding (x0 is always 0)"""
    dut.rs1_EX.value = 0    # reading x0
    dut.rs2_EX.value = 0    # reading x0
    dut.rd_MEM.value  = 0   # writing x0 — must be ignored!
    dut.reg_write_MEM.value = 1
    dut.rd_WB.value   = 0   # writing x0 — must be ignored!
    dut.reg_write_WB.value  = 1
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b00, f"forward_A should be 00 (x0 never forwarded)"
    assert dut.forward_B.value == 0b00, f"forward_B should be 00 (x0 never forwarded)"

@cocotb.test()
async def test_forwarding_reg_write_0_suppresses(dut):
    """A8: reg_write=0 suppresses forwarding even if rd matches"""
    dut.rs1_EX.value = 3
    dut.rs2_EX.value = 3
    dut.rd_MEM.value  = 3   # would match, but reg_write=0 (e.g. SW)
    dut.reg_write_MEM.value = 0
    dut.rd_WB.value   = 3   # would match, but reg_write=0
    dut.reg_write_WB.value  = 0
    await Timer(1, unit="ns")
    assert dut.forward_A.value == 0b00, f"forward_A should be 00 (reg_write=0 suppresses)"
    assert dut.forward_B.value == 0b00, f"forward_B should be 00 (reg_write=0 suppresses)"


# =========================================================================
# SECTION B — Hazard Detection Unit Tests (hazard.v)
# =========================================================================

@cocotb.test()
async def test_hazard_no_stall(dut):
    """B1: No stall — non-load instruction in EX stage"""
    dut.mem_read_EX.value = 0   # not a load
    dut.rd_EX.value  = 1
    dut.rs1_ID.value = 1        # would match, but not a load
    dut.rs2_ID.value = 2
    await Timer(1, unit="ns")
    assert dut.stall.value == 0, f"stall should be 0 (not a load instruction)"

@cocotb.test()
async def test_hazard_load_use_rs1(dut):
    """B2: LW followed by instruction that reads the loaded register (rs1)"""
    dut.mem_read_EX.value = 1   # LW is in EX stage
    dut.rd_EX.value  = 4        # LW is writing x4
    dut.rs1_ID.value = 4        # next instruction reads x4 from rs1
    dut.rs2_ID.value = 2
    await Timer(1, unit="ns")
    assert dut.stall.value == 1, f"stall should be 1 (load-use hazard on rs1)"

@cocotb.test()
async def test_hazard_load_use_rs2(dut):
    """B3: LW followed by instruction that reads the loaded register (rs2)"""
    dut.mem_read_EX.value = 1
    dut.rd_EX.value  = 7
    dut.rs1_ID.value = 2        # different register — no match
    dut.rs2_ID.value = 7        # rs2 matches — stall!
    await Timer(1, unit="ns")
    assert dut.stall.value == 1, f"stall should be 1 (load-use hazard on rs2)"

@cocotb.test()
async def test_hazard_load_no_dependence(dut):
    """B4: LW in EX but the next instruction reads DIFFERENT registers — no stall"""
    dut.mem_read_EX.value = 1
    dut.rd_EX.value  = 3
    dut.rs1_ID.value = 1        # different
    dut.rs2_ID.value = 2        # different
    await Timer(1, unit="ns")
    assert dut.stall.value == 0, f"stall should be 0 (no register overlap)"

@cocotb.test()
async def test_hazard_load_to_x0(dut):
    """B5: LW to x0 never causes a stall (x0 is always 0, no real dependence)"""
    dut.mem_read_EX.value = 1
    dut.rd_EX.value  = 0        # LW x0 — nonsensical but must not stall
    dut.rs1_ID.value = 0
    dut.rs2_ID.value = 0
    await Timer(1, unit="ns")
    assert dut.stall.value == 0, f"stall should be 0 (rd_EX=x0 never causes stall)"


# =========================================================================
# SECTION C — Full Pipeline Test (should be 56/56 after D1+D2+D3 done)
# =========================================================================
# This is the same as make py_pipe_top.
# Run test_pipe_top.py for the full pipeline test.


# =========================================================================
# pytest Runners — one for forwarding, one for hazard
# =========================================================================

def test_forwarding_runner():
    proj_root = Path(__file__).resolve().parent.parent
    src_dir   = proj_root / "src"

    run(
        verilog_sources=[str(src_dir / "forwarding.v")],
        toplevel="forwarding",
        module="test_hazard",
        simulator="verilator",
        testcase="test_forwarding_no_hazard,test_forwarding_ex_ex_rs1,test_forwarding_ex_ex_rs2,"
                 "test_forwarding_mem_wb_rs1,test_forwarding_mem_wb_rs2,"
                 "test_forwarding_ex_ex_wins_over_mem_wb,test_forwarding_no_forward_to_x0,"
                 "test_forwarding_reg_write_0_suppresses",
        extra_args=["-Wno-fatal", "-Wno-UNUSEDSIGNAL"],
        sim_build="sim_build/forwarding",
    )


def test_hazard_runner():
    proj_root = Path(__file__).resolve().parent.parent
    src_dir   = proj_root / "src"

    run(
        verilog_sources=[str(src_dir / "hazard.v")],
        toplevel="hazard",
        module="test_hazard",
        simulator="verilator",
        testcase="test_hazard_no_stall,test_hazard_load_use_rs1,test_hazard_load_use_rs2,"
                 "test_hazard_load_no_dependence,test_hazard_load_to_x0",
        extra_args=["-Wno-fatal", "-Wno-UNUSEDSIGNAL"],
        sim_build="sim_build/hazard",
    )
