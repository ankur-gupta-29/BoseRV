import cocotb
import os
import shutil
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
from cocotb_test.simulator import run

@cocotb.test()
async def test_top_fibonacci(dut):
    """Run the BoseRV top-level core and verify the register sequence."""
    
    # 1. Start the clock
    # This creates a ticking background thread on dut.clk (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # 2. Reset Sequence
    # TODO: Drive dut.rst.value High (1)
    # TODO: Wait for 2 clock cycles using: await ClockCycles(dut.clk, 2)
    # TODO: Drive dut.rst.value Low (0)
    dut.rst.value = 1
    await ClockCycles(dut.clk,2)
    dut.rst.value = 0
    
    # 3. Wait for the processor to execute the exhaustive code
    await ClockCycles(dut.clk, 50)
    
    # 4. Assert the final architectural state!
    failures = []
    passed = []
    def check_reg(idx, expected, name):
        # Convert to unsigned 32-bit since cocotb integer getter casts as unsigned
        val = dut.regfile_inst.regs[idx].value.integer
        unsigned_expected = expected & 0xFFFFFFFF
        if val != unsigned_expected:
            failures.append(f"  FAIL [{name}] x{idx}: expected {unsigned_expected}, got {val}")
        else:
            passed.append(f"  PASS [{name}] x{idx} = {val}")

    check_reg(1, 15, "ADDI")
    check_reg(2, 5,  "ADDI")
    check_reg(3, -5, "ADDI (Negative)")
    
    check_reg(4, 20, "ADD")
    check_reg(5, 10, "SUB")
    check_reg(6, 160, "SLL")
    check_reg(7, 1,  "SLT")
    check_reg(8, 0,  "SLTU")
    check_reg(9, 10, "XOR")
    check_reg(10, 0, "SRL")
    check_reg(11, -1, "SRA")
    check_reg(12, 15, "OR")
    check_reg(13, 5,  "AND")
    
    check_reg(14, 1,  "SLTI")
    check_reg(15, 0,  "SLTIU")
    check_reg(16, 10, "XORI")
    check_reg(17, 15, "ORI")
    check_reg(18, 5,  "ANDI")
    check_reg(19, 20, "SLLI")
    check_reg(20, 7,  "SRLI")
    check_reg(21, -3, "SRAI")
    
    check_reg(22, -3, "LW/SW")
    
    check_reg(23, 4096, "LUI")
    check_reg(24, 4188, "AUIPC")
    
    check_reg(25, 1, "Branches (BEQ,BNE,BLT,BGE,BLTU,BGEU)")
    
    check_reg(26, 152, "JAL Link")
    check_reg(27, 1, "JAL Jump")
    
    check_reg(31, 100, "Program Completion")

    # Final report -- show passed and failed
    total_tests = len(passed) + len(failures)
    pass_report = "\n".join(passed)
    dut._log.info(f"\n=== BoseRV Test Results: {len(passed)}/{total_tests} PASSED ===\n{pass_report}")
    if failures:
        fail_report = "\n".join(failures)
        assert False, f"\n\n=== {len(failures)} FAILED ===\n{fail_report}\n"




# =========================================================================
# Pytest Runner
# =========================================================================
import subprocess

def test_top_runner():
    # 1. Compile the assembly code dynamically before running tests!
    subprocess.run(["python3", "tests/gen_hex.py", "tests/test_full.asm", "tests/instr_mem.hex"], check=True)
    
    # 2. Copy the hex file into the sim_build folder
    os.makedirs("sim_build/tests", exist_ok=True)
    shutil.copy("tests/instr_mem.hex", "sim_build/tests/instr_mem.hex")

    run(
        # We need to compile ALL the verilog files for the top module!
        verilog_sources=[
            "src/imem.v", "src/dmem.v", "src/regfile.v", 
            "src/alu.v", "src/decoder.v", "src/fetch.v", "src/top.v"
        ],
        toplevel="top",
        module="test_top",
        simulator="verilator",
        # Ignore warning flags to ensure Verilator spins up gracefully
        extra_args=["--trace", "-Wno-fatal", "-Wno-DECLFILENAME"]
    )
