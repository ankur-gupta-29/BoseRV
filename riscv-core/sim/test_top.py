import cocotb
import os
import shutil
import subprocess
from pathlib import Path
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles
from cocotb_test.simulator import run

# =========================================================================
# BoseRV — Full RV32I Cocotb Testbench
# Works with test_full.asm (56 tests, pass = x28==0 AND x31==1337)
#
# BUGS FIXED vs original testbench:
#
#   BUG 1 — Only 50 clock cycles
#            test_full.asm has ~240 instructions to reach HALT.
#            A single-cycle core needs 1 cycle per instruction.
#            50 cycles means the program never completes; all checks
#            read mid-execution garbage. Fixed: 400 cycles.
#
#   BUG 2 — check_reg expected values are from the OLD test program
#            (the previous simpler test), not test_full.asm.
#            e.g. x24=4192 (old AUIPC PC was 96), x31=100 (old marker),
#            x26=156 (old JAL), x27=1 (old JAL target). All wrong.
#            Fixed: use x28=0 and x31=1337 as primary pass condition.
#
#   BUG 3 — AUIPC expected value (4192) is PC-dependent and hardcoded.
#            It only worked for one specific instruction layout.
#            Fixed: don't hardcode PC-dependent values; let the test
#            program self-verify via the branch-to-HALT pattern.
#
#   BUG 4 — Signed value comparison inconsistency
#            val = dut.regfile_inst.regs[idx].value.integer
#            For a reg[31:0], .integer can return unsigned (0..2^32-1).
#            Comparing raw .integer against -5 (Python negative int) always fails.
#            Fixed: mask both sides to 32-bit unsigned before comparing.
# =========================================================================

# ── Error code → test name map (matches test_full.asm comments) ───────────
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
    return dut.regfile_inst.regs[idx].value.integer & 0xFFFFFFFF


@cocotb.test()
async def test_full_rv32i(dut):
    """
    Run test_full.asm on BoseRV and verify the final architectural state.

    Primary pass conditions from test_full.asm:
        x28 == 0     — all 56 instruction tests passed
                       (non-zero = error code of the FIRST failing test)
        x31 == 1337  — program reached the final HALT normally

    Secondary checks (deterministic register values after all tests pass):
        x0  == 0           — always (write-protection verified)
        x1  == 15          — set at init, never overwritten
        x2  == 5           — set at init, never overwritten
        x3  == 0xFFFFFFFB  — set at init (-5), never overwritten
        x4  == 0           — JALR test sentinel (skipped instructions never ran)
        x5  == 99          — last write is addi x5,x0,99 inside JALR_LAND
    """

    # ── 1. Start clock ────────────────────────────────────────────────────
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # ── 2. Reset sequence ─────────────────────────────────────────────────
    dut.rst.value = 1
    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0

    # ── 3. Run program ────────────────────────────────────────────────────
    # BUG 1 FIX: test_full.asm has ~240 instructions to HALT.
    # Single-cycle = 1 clock per instruction.  Use 400 for safe margin.
    await ClockCycles(dut.clk, 400)

    # ── 4. Collect final register state ───────────────────────────────────
    x28 = read_reg(dut, 28)
    x31 = read_reg(dut, 31)

    passed   = []
    failures = []

    def check(label, actual, expected):
        """Compare actual vs expected as unsigned 32-bit values."""
        a = actual   & 0xFFFFFFFF   # BUG 4 FIX: always mask both sides
        e = expected & 0xFFFFFFFF
        if a == e:
            passed.append(f"  PASS  {label}: {a:#010x}  ({a})")
        else:
            failures.append(
                f"  FAIL  {label}:\n"
                f"          expected {e:#010x}  ({e})\n"
                f"          got      {a:#010x}  ({a})"
            )

    # ── Primary: x28 (error code) ─────────────────────────────────────────
    # BUG 2 FIX: use the test program's own pass condition
    if x28 == 0:
        passed.append(f"  PASS  x28 = 0  (all 56 tests passed)")
    else:
        name = ERROR_MAP.get(x28, f"unknown test #{x28}")
        failures.append(
            f"  FAIL  x28 = {x28}  →  test '{name}' is the first failure\n"
            f"          Check the branch-to-HALT trap that set x28={x28}"
        )

    # ── Primary: x31 (completion marker) ─────────────────────────────────
    # BUG 2 FIX: test_full.asm sets x31=1337, not 100
    check("x31  completion marker", x31, 1337)

    # ── Sanity: init registers (set once at start, never overwritten) ─────
    check("x0   hardwired zero",   read_reg(dut, 0),  0)
    check("x1   ADDI init = 15",   read_reg(dut, 1),  15)
    check("x2   ADDI init = 5",    read_reg(dut, 2),  5)
    check("x3   ADDI init = -5",   read_reg(dut, 3),  -5)   # 0xFFFFFFFB

    # ── Deterministic post-execution values ───────────────────────────────
    # After Test 52 (JALR), the last writes before x0-protection section:
    #   addi x4, x0, 0   → x4 = 0  (JALR sentinel, skipped instrs never ran)
    #   addi x5, x0, 99  → x5 = 99 (inside JALR_LAND)
    check("x4   JALR sentinel = 0",      read_reg(dut, 4),  0)
    check("x5   JALR_LAND addi = 99",    read_reg(dut, 5),  99)

    # ── Report ─────────────────────────────────────────────────────────────
    total = len(passed) + len(failures)
    sep   = "=" * 60
    dut._log.info(
        f"\n{sep}\n"
        f"BoseRV RV32I Test Results: {len(passed)}/{total} checks passed\n"
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
def test_top_runner():
    # Resolve paths relative to this test file, not cwd
    proj_root  = Path(__file__).resolve().parent.parent   # riscv-core/
    tests_dir  = proj_root / "tests"                      # riscv-core/tests/
    src_dir    = proj_root / "src"

    # ── Step 1: Assemble test_full.asm → instr_mem.hex ────────────────────
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
    print(f"[runner] Assembled → {hex_path}")

    # ── Step 2: Copy hex into sim_build so $readmemh finds it ─────────────
    # Verilator runs from sim_build/, so "tests/instr_mem.hex" in Verilog
    # resolves to sim_build/tests/instr_mem.hex
    sim_tests_dir = proj_root / "sim_build" / "tests"
    sim_tests_dir.mkdir(parents=True, exist_ok=True)
    shutil.copy(str(hex_path), str(sim_tests_dir / "instr_mem.hex"))
    print(f"[runner] Copied hex → {sim_tests_dir / 'instr_mem.hex'}")

    # ── Step 3: Run Verilator simulation ──────────────────────────────────
    run(
        verilog_sources=[
            str(src_dir / "imem.v"),
            str(src_dir / "dmem.v"),
            str(src_dir / "regfile.v"),
            str(src_dir / "alu.v"),
            str(src_dir / "decoder.v"),
            str(src_dir / "fetch.v"),
            str(src_dir / "top.v"),
        ],
        toplevel="top",
        module="test_top",
        simulator="verilator",
        extra_args=[
            "--trace",          # generate VCD waveform for GTKWave debugging
            "-Wno-fatal",       # don't abort on warnings
            "-Wno-DECLFILENAME",# ignore filename/module name mismatch warning
        ],
    )
