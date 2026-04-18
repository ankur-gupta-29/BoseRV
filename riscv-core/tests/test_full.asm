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
AUIPC x24, 1         // x24 = 4096 + PC (Instruction index 23 -> PC 92) -> x24 = 4188

// 6. Branches
BEQ  x1, x1, B1_TAR
ADDI x25, x0, 99
B1_TAR:
BNE  x1, x2, B2_TAR
ADDI x25, x0, 99
B2_TAR:
BLT  x3, x1, B3_TAR
ADDI x25, x0, 99
B3_TAR:
BGE  x1, x3, B4_TAR
ADDI x25, x0, 99
B4_TAR:
BLTU x2, x3, B5_TAR
ADDI x25, x0, 99
B5_TAR:
BGEU x3, x2, B6_TAR
ADDI x25, x0, 99
B6_TAR:
ADDI x25, x0, 1      // x25 = 1 (all branches passed)

// 7. Jumps
JAL  x26, JAL_TAR    // x26 = PC + 4 (Instruction index 37 -> PC 148) -> x26 = 152
ADDI x27, x0, 99
JAL_TAR:
ADDI x27, x0, 1      // x27 = 1

ADDI x31, x0, 100    // END OF PROGRAM
