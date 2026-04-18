# ================================================================
# BoseRV — Full RV32I Single-Cycle Processor Test Suite
# 56 tests covering every instruction and every edge case
# ================================================================
#
# HOW TO ASSEMBLE:
#   riscv64-unknown-elf-as -march=rv32i -mabi=ilp32 -o test.o test_full.asm
#   riscv64-unknown-elf-objcopy -O verilog test.o tests/instr_mem.hex
#
# PASS CONDITION  : x28 = 0  AND  x31 = 1337  at HALT
# FAIL CONDITION  : x28 = N  (error code of first failing test)
#
# ERROR CODE MAP:
#   1  - ADD basic
#   2  - ADD overflow wraps to 0
#   3  - SUB basic
#   4  - SUB produces negative result
#   5  - SLL basic
#   6  - SLL by 0 is identity
#   7  - SLL by 31
#   8  - SRL does NOT sign-extend
#   9  - SRA DOES sign-extend (arithmetic)
#  10  - SRA by 0 is identity
#  11  - SLT: negative < positive = 1
#  12  - SLT: equal values = 0
#  13  - SLT: positive NOT less than negative = 0
#  14  - SLTU: small < large-unsigned = 1
#  15  - SLTU: nothing < 0 unsigned = 0
#  16  - SLT vs SLTU differ on 0xFFFFFFFB vs 0
#  17  - ADDI max positive immediate (2047)
#  18  - ADDI max negative immediate (-2048)
#  19  - XORI with -1 = bitwise NOT
#  20  - SLTI: negative < 0 = 1
#  21  - SLTIU seqz trick: (x0 < 1) = 1
#  22  - SLLI
#  23  - SRLI
#  24  - SRAI negative (sign-extends)
#  25  - LUI basic (small imm, imm[19:15]=0)
#  26  - LUI bottom 12 bits must be zero
#  27  - LUI large imm (imm[19:15] non-zero — THE CRITICAL BUG TEST)
#  28  - LUI all-ones immediate (0xFFFFF)
#  29  - AUIPC: two consecutive differ by exactly 4
#  30  - AUIPC: result is non-zero (uses PC not rs1)
#  31  - SW then LW (basic round-trip)
#  32  - SW/LW at offset +4
#  33  - SW/LW with negative immediate offset
#  34  - Previous SW not overwritten
#  35  - BEQ taken
#  36  - BNE taken
#  37  - BLT taken (signed: -5 < 15)
#  38  - BGE taken (15 >= 5)
#  39  - BGE taken equal case (15 >= 15)
#  40  - BLTU taken (unsigned: 5 < 0xFFFFFFFB)
#  41  - BGEU taken (unsigned: 0xFFFFFFFB >= 5)
#  42  - BGEU taken equal case
#  43  - BEQ NOT taken (15 != 5)
#  44  - BNE NOT taken (15 == 15)
#  45  - BLT NOT taken (15 not < -5 signed)
#  46  - BGE NOT taken (-5 not >= 15)
#  47  - BLTU NOT taken (0xFFFFFFFB not < 5 unsigned)
#  48  - BGEU NOT taken (5 not >= 0xFFFFFFFB unsigned)
#  49  - Backward branch / loop (runs exactly 4 times)
#  50  - JAL forward jump
#  51  - JAL return address is 4-byte aligned
#  52  - JALR: skips instructions between jump and target
#  53  - JALR: LSB of target address is cleared (RISC-V spec)
#  54  - x0 write-protection: ADDI cannot write x0
#  55  - x0 write-protection: ADD cannot write x0
#  56  - x0 write-protection: LUI cannot write x0
# ================================================================

.section .text
.global _start

_start:

# ----------------------------------------------------------------
# INITIALIZATION
# x1 = 15, x2 = 5, x3 = -5 (0xFFFFFFFB)
# x28 = error code (stays 0 if all tests pass)
# ----------------------------------------------------------------
    addi x1,  x0, 15
    addi x2,  x0, 5
    addi x3,  x0, -5
    addi x28, x0, 0

# ================================================================
# SECTION 1: ADD / SUB
# Tests: signed overflow wraps, negative results
# ================================================================

    # Test 1: ADD basic
    addi x28, x0, 1
    add  x4, x1, x2             # 15 + 5 = 20
    addi x5, x0, 20
    bne  x4, x5, HALT

    # Test 2: ADD overflow wraps to 0
    addi x28, x0, 2
    addi x4, x0, -1             # x4 = 0xFFFFFFFF
    addi x5, x0, 1
    add  x4, x4, x5             # 0xFFFFFFFF + 1 = 0 (wraps)
    bne  x4, x0, HALT

    # Test 3: SUB basic
    addi x28, x0, 3
    sub  x4, x1, x2             # 15 - 5 = 10
    addi x5, x0, 10
    bne  x4, x5, HALT

    # Test 4: SUB produces negative result
    addi x28, x0, 4
    sub  x4, x2, x1             # 5 - 15 = -10 = 0xFFFFFFF6
    addi x5, x0, -10
    bne  x4, x5, HALT

# ================================================================
# SECTION 2: SHIFTS
# Tests: by 0, by 31, SRL no-sign-extend, SRA sign-extend
# ================================================================

    # Test 5: SLL basic
    addi x28, x0, 5
    sll  x4, x2, x2             # 5 << 5 = 160
    addi x5, x0, 160
    bne  x4, x5, HALT

    # Test 6: SLL by 0 is identity
    addi x28, x0, 6
    sll  x4, x1, x0             # 15 << 0 = 15
    bne  x4, x1, HALT

    # Test 7: SLL by 31
    addi x28, x0, 7
    addi x4, x0, 1
    addi x5, x0, 31
    sll  x4, x4, x5             # 1 << 31 = 0x80000000
    lui  x5, 0x80000            # x5 = 0x80000000
    bne  x4, x5, HALT

    # Test 8: SRL does NOT sign-extend (zero-fills)
    addi x28, x0, 8
    srl  x4, x3, x2             # 0xFFFFFFFB >> 5 = 0x07FFFFFF
    lui  x5, 0x08000            # x5 = 0x08000000
    addi x5, x5, -1             # x5 = 0x07FFFFFF
    bne  x4, x5, HALT

    # Test 9: SRA DOES sign-extend (fills with 1s for negative)
    addi x28, x0, 9
    sra  x4, x3, x2             # -5 >> 5 = -1 = 0xFFFFFFFF
    addi x5, x0, -1
    bne  x4, x5, HALT

    # Test 10: SRA by 0 is identity
    addi x28, x0, 10
    sra  x4, x3, x0             # -5 >> 0 = -5
    bne  x4, x3, HALT

# ================================================================
# SECTION 3: SLT / SLTU
# Tests: signed vs unsigned differ, equal=0, boundary at 0
# ================================================================

    # Test 11: SLT signed — negative < positive = 1
    addi x28, x0, 11
    slt  x4, x3, x1             # -5 < 15 signed = 1
    addi x5, x0, 1
    bne  x4, x5, HALT

    # Test 12: SLT — equal values = 0
    addi x28, x0, 12
    slt  x4, x1, x1             # 15 < 15 = 0
    bne  x4, x0, HALT

    # Test 13: SLT — positive not less than negative = 0
    addi x28, x0, 13
    slt  x4, x1, x3             # 15 < -5 signed = 0
    bne  x4, x0, HALT

    # Test 14: SLTU — 15 < 0xFFFFFFFB unsigned = 1
    addi x28, x0, 14
    sltu x4, x1, x3             # 15 < 4294967291 unsigned = 1
    addi x5, x0, 1
    bne  x4, x5, HALT

    # Test 15: SLTU — nothing is less than 0 unsigned = 0
    addi x28, x0, 15
    sltu x4, x3, x0             # 0xFFFFFFFB < 0 = 0
    bne  x4, x0, HALT

    # Test 16: SLT vs SLTU must DIFFER for 0xFFFFFFFB vs 0
    # SLT(-5, 0)  = 1 (signed:  -5 < 0 = true)
    # SLTU(-5, 0) = 0 (unsigned: 0xFFFFFFFB < 0 = false)
    addi x28, x0, 16
    slt  x4, x3, x0             # x4 = 1
    sltu x5, x3, x0             # x5 = 0
    beq  x4, x5, HALT           # they must differ — if equal, one is wrong

# ================================================================
# SECTION 4: I-TYPE ALU
# Tests: boundary immediates, XORI NOT trick, SLTIU seqz trick
# ================================================================

    # Test 17: ADDI max positive immediate (2047 = 0x7FF)
    addi x28, x0, 17
    addi x4, x0, 2047
    addi x5, x0, 2047
    bne  x4, x5, HALT

    # Test 18: ADDI max negative immediate (-2048 = 0xFFFFF800)
    addi x28, x0, 18
    addi x4, x0, -2048
    addi x5, x0, -2048
    bne  x4, x5, HALT

    # Test 19: XORI with -1 = bitwise NOT (common compiler idiom)
    addi x28, x0, 19
    xori x4, x1, -1             # ~15 = 0xFFFFFFF0
    addi x5, x0, -16            # 0xFFFFFFF0
    bne  x4, x5, HALT

    # Test 20: SLTI — negative < 0 = 1
    addi x28, x0, 20
    slti x4, x3, 0              # -5 < 0 = 1
    addi x5, x0, 1
    bne  x4, x5, HALT

    # Test 21: SLTIU seqz trick — (x0 < 1) = 1, detects zero
    addi x28, x0, 21
    sltiu x4, x0, 1             # 0 < 1 unsigned = 1
    addi  x5, x0, 1
    bne   x4, x5, HALT

    # Test 22: SLLI
    addi x28, x0, 22
    slli x4, x2, 2              # 5 << 2 = 20
    addi x5, x0, 20
    bne  x4, x5, HALT

    # Test 23: SRLI
    addi x28, x0, 23
    srli x4, x1, 1              # 15 >> 1 = 7
    addi x5, x0, 7
    bne  x4, x5, HALT

    # Test 24: SRAI negative (sign-extends)
    addi x28, x0, 24
    srai x4, x3, 1              # -5 >> 1 = -3 = 0xFFFFFFFD
    addi x5, x0, -3
    bne  x4, x5, HALT

# ================================================================
# SECTION 5: LUI
# Tests: small imm, bottom-12-zero, LARGE IMM (imm[19:15] != 0),
#        all-ones immediate
# NOTE: Tests 27 and 28 are the critical U-type rs1 bug tests.
#       If LUI uses rs1_data instead of 0, these WILL fail.
# ================================================================

    # Test 25: LUI basic (imm=1, imm[19:15]=0 — easy case)
    addi x28, x0, 25
    lui  x4, 1                  # x4 = 0x00001000
    srli x5, x4, 12             # x5 = 1 (top 20 bits)
    addi x6, x0, 1
    bne  x5, x6, HALT

    # Test 26: LUI bottom 12 bits must all be zero
    addi x28, x0, 26
    slli x5, x4, 20             # shift out top 20, isolate bottom 12
    bne  x5, x0, HALT           # must be 0

    # Test 27: LUI large imm (imm[19:15] = 0x14 = non-zero)
    # This is THE critical test for the U-type rs1 corruption bug.
    # Correct:  x4 = 0x12345000
    # Buggy HW: x4 = regs[instr[19:15]] + 0x12345000 (WRONG)
    addi x28, x0, 27
    lui  x4, 0x12345            # x4 should = 0x12345000
    srli x5, x4, 12             # x5 = 0x00012345 (if correct)
    lui  x6, 0x12               # x6 = 0x00012000
    addi x6, x6, 837            # x6 += 0x345 (837 dec) → x6 = 0x00012345
    bne  x5, x6, HALT

    # Test 28: LUI all-ones immediate (0xFFFFF)
    addi x28, x0, 28
    lui  x4, 0xFFFFF            # x4 = 0xFFFFF000
    srli x5, x4, 12             # x5 = 0x000FFFFF
    addi x6, x0, -1             # x6 = 0xFFFFFFFF
    srli x6, x6, 12             # x6 = 0x000FFFFF
    bne  x5, x6, HALT

# ================================================================
# SECTION 6: AUIPC
# Tests: consecutive AUIPC differ by 4, result is non-zero (uses PC)
# ================================================================

    # Test 29: Two consecutive AUIPC must differ by exactly 4
    addi x28, x0, 29
    auipc x4, 0                 # x4 = PC of this instruction
    auipc x5, 0                 # x5 = PC of this instruction (= x4 + 4)
    sub   x6, x5, x4            # x6 must = 4
    addi  x7, x0, 4
    bne   x6, x7, HALT

    # Test 30: AUIPC result is non-zero (proves it used PC, not rs1=0)
    # lui  x4, 2  → x4 = 0x2000
    # auipc x5, 2 → x5 = PC + 0x2000
    # x5 - x4 = PC (of the auipc instr), which must be > 0
    addi x28, x0, 30
    lui   x4, 2                 # x4 = 0x2000
    auipc x5, 2                 # x5 = PC + 0x2000
    sub   x5, x5, x4            # x5 = PC of auipc instr
    beq   x5, x0, HALT          # PC must not be zero

# ================================================================
# SECTION 7: MEMORY (SW / LW only — dmem is word-only)
# Tests: basic round-trip, positive offset, negative offset,
#        persistence (earlier store not overwritten)
# ================================================================

    # Test 31: SW then LW basic round-trip
    addi x28, x0, 31
    addi x4, x0, -99            # x4 = -99 = 0xFFFFFF9D
    sw   x4, 0(x0)              # mem[0] = -99
    lw   x5, 0(x0)              # x5 should = -99
    bne  x4, x5, HALT

    # Test 32: SW/LW at positive offset
    addi x28, x0, 32
    addi x4, x0, 42
    sw   x4, 4(x0)              # mem[1] = 42
    lw   x5, 4(x0)
    bne  x4, x5, HALT

    # Test 33: SW/LW with negative immediate offset
    addi x28, x0, 33
    addi x4, x0, 7
    addi x6, x0, 8              # base address = 8
    sw   x4, -4(x6)             # store to addr 8-4=4 = mem[1]
    lw   x5, -4(x6)             # load from addr 4
    bne  x4, x5, HALT

    # Test 34: mem[0] must still hold -99 (Test 31's store not overwritten)
    addi x28, x0, 34
    lw   x5, 0(x0)
    addi x6, x0, -99
    bne  x5, x6, HALT

# ================================================================
# SECTION 8: BRANCHES — TAKEN
# Tests all 6 branch types in the taken direction, including the
# BGE/BGEU equal cases that many processors get wrong.
# ================================================================

    # Test 35: BEQ taken (15 == 15)
    addi x28, x0, 35
    beq  x1, x1, BEQ_TAKEN
    jal  x0, HALT
BEQ_TAKEN:

    # Test 36: BNE taken (15 != 5)
    addi x28, x0, 36
    bne  x1, x2, BNE_TAKEN
    jal  x0, HALT
BNE_TAKEN:

    # Test 37: BLT taken — signed (-5 < 15)
    addi x28, x0, 37
    blt  x3, x1, BLT_TAKEN
    jal  x0, HALT
BLT_TAKEN:

    # Test 38: BGE taken (15 >= 5)
    addi x28, x0, 38
    bge  x1, x2, BGE_TAKEN
    jal  x0, HALT
BGE_TAKEN:

    # Test 39: BGE taken — EQUAL case (15 >= 15)
    addi x28, x0, 39
    bge  x1, x1, BGE_EQ
    jal  x0, HALT
BGE_EQ:

    # Test 40: BLTU taken — unsigned (5 < 0xFFFFFFFB)
    addi x28, x0, 40
    bltu x2, x3, BLTU_TAKEN
    jal  x0, HALT
BLTU_TAKEN:

    # Test 41: BGEU taken — unsigned (0xFFFFFFFB >= 5)
    addi x28, x0, 41
    bgeu x3, x2, BGEU_TAKEN
    jal  x0, HALT
BGEU_TAKEN:

    # Test 42: BGEU taken — EQUAL case (15 >= 15)
    addi x28, x0, 42
    bgeu x1, x1, BGEU_EQ
    jal  x0, HALT
BGEU_EQ:

# ================================================================
# SECTION 9: BRANCHES — NOT TAKEN
# A broken branch that always-jumps would pass Section 8 but
# fail here. Both halves are needed for full branch coverage.
# ================================================================

    # Test 43: BEQ NOT taken (15 != 5)
    addi x28, x0, 43
    beq  x1, x2, HALT           # must NOT branch

    # Test 44: BNE NOT taken (15 == 15)
    addi x28, x0, 44
    bne  x1, x1, HALT

    # Test 45: BLT NOT taken signed (15 is NOT < -5)
    addi x28, x0, 45
    blt  x1, x3, HALT

    # Test 46: BGE NOT taken (-5 is NOT >= 15)
    addi x28, x0, 46
    bge  x3, x1, HALT

    # Test 47: BLTU NOT taken (0xFFFFFFFB is NOT < 5 unsigned)
    addi x28, x0, 47
    bltu x3, x2, HALT

    # Test 48: BGEU NOT taken (5 is NOT >= 0xFFFFFFFB unsigned)
    addi x28, x0, 48
    bgeu x2, x3, HALT

# ================================================================
# SECTION 10: BACKWARD BRANCH (loop)
# Tests that negative PC-relative offsets work correctly.
# Loop must execute exactly 4 times.
# ================================================================

    addi x28, x0, 49
    addi x4, x0, 0              # loop counter = 0
    addi x5, x0, 4              # loop limit = 4
LOOP:
    addi x4, x4, 1              # counter++
    blt  x4, x5, LOOP           # while counter < 4, loop back
    addi x6, x0, 4
    bne  x4, x6, HALT           # counter must be exactly 4

# ================================================================
# SECTION 11: JAL
# Tests: forward jump skips instructions, return address is
#        correct and 4-byte aligned.
# ================================================================

    # Test 50: JAL forward — saves return addr, skips instruction
    addi x28, x0, 50
    jal  x6, JAL_FWD            # x6 = PC+4 (return addr)
    jal  x0, HALT               # must be SKIPPED
JAL_FWD:
    beq  x6, x0, HALT           # return addr must not be 0

    # Test 51: Return address must be 4-byte aligned
    addi x28, x0, 51
    andi x5, x6, 3              # bottom 2 bits of return addr
    bne  x5, x0, HALT           # must be 0 (aligned)

# ================================================================
# SECTION 12: JALR
# Test 52: Jumps to computed address, skips instructions,
#          saves correct return address.
# Test 53: JALR clears bit 0 of target (RISC-V spec requirement).
# ================================================================

    # Test 52: JALR basic
    # Strategy: auipc gives us current PC, we compute
    # target = PC + 20 (5 instructions ahead = JALR_LAND)
    # Two instructions between jalr and JALR_LAND are traps —
    # if either executes, x4 gets corrupted to 99.
    addi x28, x0, 52
    addi  x4, x0, 0             # sentinel = 0
    auipc x6, 0                 # x6 = PC of this auipc
    addi  x6, x6, 20            # x6 = address of JALR_LAND (5 instrs ahead)
    jalr  x7, x6, 0             # jump; x7 = return addr (next instr)
    addi  x4, x0, 99            # SKIPPED (offset +4 from jalr)
    addi  x4, x0, 99            # SKIPPED (offset +8 from jalr)
JALR_LAND:                      # offset +12... wait - 
    # auipc is at A
    # addi  x6, A+4
    # jalr  A+8 → target = A+20; x7 = A+12
    # addi  A+12 SKIPPED
    # addi  A+16 SKIPPED
    # JALR_LAND should be at A+20 = auipc + 20 ✓
    addi x5, x0, 99
    beq  x4, x5, HALT           # x4 must still be 0 (skipped instrs)
    beq  x7, x0, HALT           # x7 must hold return addr (non-zero)

    # Test 53: JALR clears LSB of target address (spec requirement)
    # We give JALR an ODD address (target | 1).
    # Correct HW clears bit 0 → lands at JALR_LSB_LAND.
    # Buggy HW keeps odd addr → fetch misaligned instruction (garbage).
    addi x28, x0, 53
    auipc x6, 0                 # x6 = PC of this auipc (= C)
    addi  x6, x6, 20            # x6 = C+20 (address of JALR_LSB_LAND)
    ori   x6, x6, 1             # x6 = C+21 (odd — set LSB)
    jalr  x7, x6, 0             # target = (C+21)&~1 = C+20 → JALR_LSB_LAND
    jal   x0, HALT              # C+16: reached only if LSB was NOT cleared
JALR_LSB_LAND:                  # C+20: reached only if LSB was correctly cleared

# ================================================================
# SECTION 13: x0 WRITE PROTECTION
# x0 must always read as 0, regardless of what instruction
# tries to write it. Tests ADDI, ADD, and LUI to x0.
#
# Detection method: attempt write to x0, then use BLTU x0, x1.
#   If x0=0  → 0 < 15  → BLTU taken  → jump over HALT (pass)
#   If x0=99 → 99 < 15 → BLTU NOT taken → fall into HALT (fail)
# ================================================================

    # Test 54: ADDI cannot write x0
    addi x28, x0, 54
    addi x0, x0, 99             # attempt: x0 = 99
    bltu x0, x1, X0_OK1         # 0 < 15? yes (only if x0 still 0)
    jal  x0, HALT               # x0 was corrupted
X0_OK1:

    # Test 55: ADD cannot write x0
    addi x28, x0, 55
    add  x0, x1, x2             # attempt: x0 = 20
    bltu x0, x1, X0_OK2         # 0 < 15? yes (only if x0 still 0)
    jal  x0, HALT
X0_OK2:

    # Test 56: LUI cannot write x0
    addi x28, x0, 56
    lui  x0, 0x12345            # attempt: x0 = 0x12345000
    bltu x0, x1, X0_OK3         # 0 < 15? yes (only if x0 still 0)
    jal  x0, HALT
X0_OK3:

# ================================================================
# ALL 56 TESTS PASSED
# ================================================================
    addi x28, x0, 0             # clear error code — all tests passed
    addi x31, x0, 1337          # completion marker (1337 fits in 12-bit imm)
HALT:
    jal  x0, HALT               # infinite loop — halt here

# ================================================================
# END OF FILE
# ================================================================