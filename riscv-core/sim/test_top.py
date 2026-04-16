import cocotb
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
    
    # 3. Wait for the processor to execute the code
    # TODO: Wait for another 20 clock cycles
    
    # 4. Assert the final architectural state!
    # Use .value.integer to read the raw Verilog memory array
    # TODO: assert dut.regfile_inst.regs[1].value.integer == 5
    # TODO: assert exact values for regs[2], regs[3], and regs[5] (like your tb_top.v did!)


# =========================================================================
# Pytest Runner
# =========================================================================
def test_top_runner():
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
