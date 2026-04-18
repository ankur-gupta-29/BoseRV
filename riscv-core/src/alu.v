// ============================================================
// BoseRV — ALU (Arithmetic Logic Unit)
// Assignment A1 — SKELETON
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
    input  [31:0] b,          // operand B (rs2 or immediate)
    input  [3:0]  op,         // ALU operation select
    output reg [31:0] result, // ALU result
    output        zero        // result == 0 ? (used for branches)
);

    // Hint: You might want to define signed versions of 'a' and 'b' 
    // for use in SRA and SLT operations.
    // wire signed [31:0] a_signed = a;

    always @(*) begin
        // TODO: Implement the case statement for all ALU operations
        case (op)
            // 4'b0000: result = ...
            4'b0000: result = a+b;
            4'b0001: result = a-b;
            4'b0010: result = a&b;
            4'b0011: result = a|b;
            4'b0100: result = a^b;
            4'b0101: result = a<<b[4:0];
            4'b0110: result = a>>b[4:0];
            4'b0111: result = $signed(a)>>>b[4:0];
            4'b1000: result = $signed(a) < $signed(b) ? 1'b1:1'b0;
            4'b1001: result = a<b ? 1'b1:1'b0;
            default: result = 32'h0;
        endcase
    end

    // TODO: Determine when the zero flag should be set 
    // (Hint: it's used by the BEQ instruction)
    assign zero = result == 32'b0;

endmodule
