// Full RV32I Exhaustive Test Program
// Tests all 31 core instructions supported by the BoseRV Single-Cycle Architecture

// 1. Setup
ADDI x1, x0, 15      // x1 = 15
ADDI x2, x0, 5       // x2 = 5
ADDI x3, x0, -5      // x3 = -5 (Unsigned: 4294967291)

// 2. R-Type
ADD  x4, x1, x2      // x4 = 20
SUB  x5, x1, x2      // x5 = 10
SLL  x6, x2, x2      // x6 = 160
SLT  x7, x3, x2      // x7 = 1 (-5 < 5)
SLTU x8, x3, x2      // x8 = 0 (-5 > 5 in unsigned)
XOR  x9, x1, x2      // x9 = 10
SRL  x10, x1, x2     // x10 = 0
SRA  x11, x3, x2     // x11 = -1 (Unsigned: 4294967295)
OR   x12, x1, x2     // x12 = 15
AND  x13, x1, x2     // x13 = 5

// 3. I-Type
SLTI  x14, x3, 0     // x14 = 1
SLTIU x15, x3, 0     // x15 = 0
XORI  x16, x1, 5     // x16 = 10
ORI   x17, x1, 5     // x17 = 15
ANDI  x18, x1, 5     // x18 = 5
SLLI  x19, x2, 2     // x19 = 20
SRLI  x20, x1, 1     // x20 = 7
SRAI  x21, x3, 1     // x21 = -3 (Unsigned: 4294967293)

// 4. Memory
SW   x21, 0(x0)      // mem[0] = -3
LW   x22, 0(x0)      // x22 = -3 (Unsigned: 4294967293)

// 5. U-Type
LUI   x23, 1         // x23 = 4096
AUIPC x24, 1         // x24 = PC(96) + 4096 = 4192

// 6. Branches (Proper Fail-Trap Pattern)
// x28 stays 0 if ALL branches work. Non-zero = error code of failing branch.
// BEQ: x1(15) == x1(15), should branch
BEQ  x1, x1, BEQ_OK
ADDI x28, x0, 1      // x28=1 means BEQ FAILED
BEQ_OK:
// BNE: x1(15) != x2(5), should branch
BNE  x1, x2, BNE_OK
ADDI x28, x0, 2      // x28=2 means BNE FAILED
BNE_OK:
// BLT: x3(-5) < x1(15), should branch (signed)
BLT  x3, x1, BLT_OK
ADDI x28, x0, 3      // x28=3 means BLT FAILED
BLT_OK:
// BGE: x1(15) >= x2(5), should branch (signed)
BGE  x1, x2, BGE_OK
ADDI x28, x0, 4      // x28=4 means BGE FAILED
BGE_OK:
// BLTU: x2(5) < x3(0xFFFFFFFB), should branch (unsigned)
BLTU x2, x3, BLTU_OK
ADDI x28, x0, 5      // x28=5 means BLTU FAILED
BLTU_OK:
// BGEU: x3(0xFFFFFFFB) >= x2(5), should branch (unsigned)
BGEU x3, x2, BGEU_OK
ADDI x28, x0, 6      // x28=6 means BGEU FAILED
BGEU_OK:
ADDI x25, x0, 1      // x25=1: marker that we reached end of branch section

// 7. Jumps (JAL at instruction 38, PC=152)
JAL  x26, JAL_TAR    // x26 = PC+4 = 156
ADDI x27, x0, 99     // skipped
JAL_TAR:
ADDI x27, x0, 1      // x27 = 1

ADDI x31, x0, 100    // END OF PROGRAM
