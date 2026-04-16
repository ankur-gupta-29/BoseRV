import cocotb
from cocotb.triggers import Timer
from cocotb_test.simulator import run

# =========================================================================
# Part 1: The Cocotb Testbench
# This runs INSIDE the simulator and drives the Verilog signals.
# =========================================================================
@cocotb.test()
async def test_alu_addition(dut):
    """Test standard addition: 5 + 14 = 19"""
    
    # 1. Drive inputs
    dut.a.value = 5
    dut.b.value = 14
    dut.op.value = 0  # 4'b0000 is ADD
    
    # 2. Wait for signals to propagate through the combinatorial logic
    await Timer(10, units="ns")
    
    # 3. Assert outputs
    assert dut.result.value == 19, f"ALU produced {dut.result.value} instead of 19"
    assert dut.zero.value == 0, "Zero flag should be 0"

    # TODO: Add more test cases here! 
    # Try testing Subtraction, AND, OR, and the Zero flag.
    # 1. Drive inputs
    dut.a.value = 14
    dut.b.value = 5
    dut.op.value = 1  # 4'b0000 is SUB
    
    # 2. Wait for signals to propagate through the combinatorial logic
    await Timer(10, units="ns")
    
    # 3. Assert outputs
    assert dut.result.value == 9, f"ALU produced {dut.result.value} instead of 9"
    assert dut.zero.value == 0, "Zero flag should be 0"

        # 1. Drive inputs
    dut.a.value = 5
    dut.b.value = 0
    dut.op.value = 2  # 4'b0000 is AND
    
    # 2. Wait for signals to propagate through the combinatorial logic
    await Timer(10, units="ns")
    
    # 3. Assert outputs
    assert dut.result.value == 0, f"ALU produced {dut.result.value} instead of 0"
    assert dut.zero.value == 0, "Zero flag should be 0"


# =========================================================================
# Part 2: The Pytest Runner
# This tells python how to compile your Verilog using Verilator
# =========================================================================
def test_alu_runner():
    run(
        verilog_sources=["src/alu.v"], # The verilog file being tested
        toplevel="alu",                # The top-level verilog module
        module="test_alu",             # The name of this python file (without .py)
        simulator="verilator",         # Use verilator under the hood
        extra_args=["--trace", "-Wno-fatal"]  # Ignore warnings, dump waveforms
    )
