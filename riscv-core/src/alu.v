// ============================================================
// BoseRV — ALU (Arithmetic Logic Unit)
//
// op encoding (4-bit):
//   4'b0000 = ADD     4'b0001 = SUB
//   4'b0010 = AND     4'b0011 = OR
//   4'b0100 = XOR     4'b0101 = SLL (shift left logical)
//   4'b0110 = SRL     4'b0111 = SRA (shift right arithmetic)
//   4'b1000 = SLT     4'b1001 = SLTU
// ============================================================
module alu (
    input  [31:0] a,          // operand A (always from rs1)
    input  [31:0] b,          // operand B (rs2 or immediate — chosen by alu_src MUX in top.v)
    input  [3:0]  op,         // ALU operation select (from decoder)
    output reg [31:0] result, // ALU result (goes to writeback MUX or data memory address)
    output        zero        // 1 when result==0; used by BEQ/BNE branch logic in top.v
);

    always @(*) begin
        case (op)
            4'b0000: result = a + b;                        // ADD / ADDI
            4'b0001: result = a - b;                        // SUB (also used by branches: SUB then check zero/sign)
            4'b0010: result = a & b;                        // AND / ANDI
            4'b0011: result = a | b;                        // OR  / ORI
            4'b0100: result = a ^ b;                        // XOR / XORI
            4'b0101: result = a << b[4:0];                  // SLL: only low 5 bits of shift amount (RV32I spec §2.6)
            4'b0110: result = a >> b[4:0];                  // SRL: logical right shift — fills with 0s
            4'b0111: result = $signed(a) >>> b[4:0];        // SRA: arithmetic right shift — fills with sign bit
            4'b1000: result = $signed(a) < $signed(b) ? 32'd1 : 32'd0; // SLT: treats both as signed 2's complement
            4'b1001: result = a < b             ? 32'd1 : 32'd0;        // SLTU: treats both as unsigned
            default: result = 32'h0;
        endcase
    end

    // zero flag: branch logic in top.v uses this for BEQ (branch if zero) and BNE (branch if not zero)
    assign zero = (result == 32'b0);

endmodule
