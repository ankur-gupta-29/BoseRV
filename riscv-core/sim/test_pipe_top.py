import cocotb
import os
import shutil
import subprocess
from pathlib import Path
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles
from cocotb_test.simulator import run

# =========================================================================
# BoseRV — Full Pipelined RV32I Cocotb Testbench
# =========================================================================

ERROR_MAP = {
    1:  "ADD basic",
    2:  "ADD overflow wraps to 0",
    3:  "SUB basic",
    4:  "SUB negative result",
    5:  "SLL basic",
    6:  "SLL by 0 is identity",
    7:  "SLL by 31",
    8:  "SRL no sign-extend",
    9:  "SRA sign-extends",
    10: "SRA by 0 is identity",
    11: "SLT: neg < pos = 1",
    12: "SLT: equal = 0",
    13: "SLT: pos not < neg = 0",
    14: "SLTU: small < large-unsigned = 1",
    15: "SLTU: nothing < 0 = 0",
    16: "SLT vs SLTU differ on 0xFFFFFFFB vs 0",
    17: "ADDI max positive immediate (+2047)",
    18: "ADDI max negative immediate (-2048)",
    19: "XORI with -1 = bitwise NOT",
    20: "SLTI: neg < 0 = 1",
    21: "SLTIU seqz trick",
    22: "SLLI",
    23: "SRLI",
    24: "SRAI negative",
    25: "LUI basic (small imm)",
    26: "LUI bottom-12 bits must be zero",
    27: "LUI large imm — CRITICAL U-type rs1 bug test",
    28: "LUI all-ones immediate",
    29: "AUIPC: consecutive differ by 4",
    30: "AUIPC: result is non-zero (uses PC, not rs1)",
    31: "SW then LW basic round-trip",
    32: "SW/LW at positive offset",
    33: "SW/LW with negative offset",
    34: "Memory persistence check",
    35: "BEQ taken",
    36: "BNE taken",
    37: "BLT taken (signed)",
    38: "BGE taken",
    39: "BGE taken — equal case",
    40: "BLTU taken (unsigned)",
    41: "BGEU taken (unsigned)",
    42: "BGEU taken — equal case",
    43: "BEQ NOT taken",
    44: "BNE NOT taken",
    45: "BLT NOT taken",
    46: "BGE NOT taken",
    47: "BLTU NOT taken",
    48: "BGEU NOT taken",
    49: "Backward branch / loop (exactly 4 iterations)",
    50: "JAL forward jump",
    51: "JAL return address 4-byte aligned",
    52: "JALR basic jump",
    53: "JALR LSB cleared (RISC-V spec)",
    54: "x0 write-protection: ADDI",
    55: "x0 write-protection: ADD",
    56: "x0 write-protection: LUI",
}


def read_reg(dut, idx):
    """Read register idx from DUT regfile, always returns unsigned 32-bit int."""
    # Note: In pipe_top, the regfile instance might be named differently depending on how you instantiate it.
    # We assume it's still accessible via dut.regfile_inst.regs (adjust if you change instance names)
    try:
        return dut.regfile_inst.regs[idx].value.integer & 0xFFFFFFFF
    except AttributeError:
        dut._log.error("Could not find dut.regfile_inst.regs! Did you name the register file instance 'regfile_inst'?")
        raise


@cocotb.test()
async def test_full_pipe_rv32i(dut):
    """
    Run test_full.asm on BoseRV pipelined core and verify the final architectural state.
    """
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    dut.rst.value = 1
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0

    # Gave it 600 cycles for safety since pipelines and flushes might add overhead
    await ClockCycles(dut.clk, 600)

    x28 = read_reg(dut, 28)
    x31 = read_reg(dut, 31)

    passed   = []
    failures = []

    def check(label, actual, expected):
        a = actual   & 0xFFFFFFFF
        e = expected & 0xFFFFFFFF
        if a == e:
            passed.append(f"  PASS  {label}: {a:#010x}  ({a})")
        else:
            failures.append(
                f"  FAIL  {label}:\n"
                f"          expected {e:#010x}  ({e})\n"
                f"          got      {a:#010x}  ({a})"
            )

    if x28 == 0:
        passed.append(f"  PASS  x28 = 0  (all 56 tests passed)")
    else:
        name = ERROR_MAP.get(x28, f"unknown test #{x28}")
        failures.append(
            f"  FAIL  x28 = {x28}  →  test '{name}' is the first failure\n"
            f"          Check the branch-to-HALT trap that set x28={x28}"
        )

    check("x31  completion marker", x31, 1337)
    check("x0   hardwired zero",   read_reg(dut, 0),  0)
    check("x1   ADDI init = 15",   read_reg(dut, 1),  15)
    check("x2   ADDI init = 5",    read_reg(dut, 2),  5)
    check("x3   ADDI init = -5",   read_reg(dut, 3),  -5)   # 0xFFFFFFFB
    check("x4   JALR sentinel = 0",      read_reg(dut, 4),  0)
    check("x5   JALR_LAND addi = 99",    read_reg(dut, 5),  99)

    total = len(passed) + len(failures)
    sep   = "=" * 60
    dut._log.info(
        f"\n{sep}\n"
        f"BoseRV PIPELINED RV32I Test Results: {len(passed)}/{total} checks passed\n"
        f"{sep}\n"
        + "\n".join(passed)
    )

    if failures:
        raise AssertionError(
            f"\n\n{sep}\n"
            f"{len(failures)} CHECK(S) FAILED:\n"
            f"{sep}\n"
            + "\n".join(failures) + "\n"
        )


# =========================================================================
# Pytest Runner
# =========================================================================
def test_pipe_top_runner():
    proj_root  = Path(__file__).resolve().parent.parent
    tests_dir  = proj_root / "tests"
    src_dir    = proj_root / "src"

    hex_path = tests_dir / "instr_mem.hex"
    subprocess.run(
        [
            "python3",
            str(tests_dir / "gen_hex_2.py"),
            str(tests_dir / "full_testing.asm"),
            str(hex_path),
        ],
        check=True,
        cwd=str(proj_root),
    )

    sim_tests_dir = proj_root / "sim_build" / "tests"
    sim_tests_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy(str(hex_path), str(sim_tests_dir / "instr_mem.hex"))

    run(
        verilog_sources=[
            str(src_dir / "imem.v"),
            str(src_dir / "dmem.v"),
            str(src_dir / "regfile.v"),
            str(src_dir / "alu.v"),
            str(src_dir / "decoder.v"),
            str(src_dir / "fetch.v"),
            str(src_dir / "if_id.v"),
            str(src_dir / "id_ex.v"),
            str(src_dir / "ex_mem.v"),
            str(src_dir / "mem_wb.v"),
            str(src_dir / "pipe_top.v"),
        ],
        toplevel="pipe_top",
        module="test_pipe_top",
        simulator="verilator",
        extra_args=[
            "--trace",
            "-Wno-fatal",
            "-Wno-DECLFILENAME",
            "-Wno-UNUSEDSIGNAL",
            "-Wno-UNDRIVEN",
        ],
    )
