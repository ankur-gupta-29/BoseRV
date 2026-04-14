// ============================================================
// BoseRV — Instruction Decoder + Control Unit
// Assignment A2 — SKELETON
//
// Decodes a 32-bit RISC-V instruction and generates:
//   - Register addresses: rs1, rs2, rd
//   - Sign-extended immediate
//   - ALU operation code
//   - All control signals
// ============================================================
module decoder (
    input  [31:0] instr,       // 32-bit raw instruction

    // Register addresses
    output [4:0]  rs1,         // source register 1
    output [4:0]  rs2,         // source register 2
    output [4:0]  rd,          // destination register

    // Immediate (sign-extended to 32 bits)
    output reg [31:0] imm,

    // ALU control
    output reg [3:0]  alu_op,  // ALU operation (matches alu.v encoding)
    output reg        alu_src, // 0=register B, 1=immediate B

    // Memory control
    output reg        mem_read,  // load instruction
    output reg        mem_write, // store instruction

    // Writeback control
    output reg        reg_write, // write result back to regfile
    output reg [1:0]  wb_sel,    // 0=ALU result, 1=mem read, 2=PC+4

    // PC control
    output reg        branch,    // is this a branch instruction?
    output reg        jump,      // is this JAL/JALR?
    output reg        jalr       // specifically JALR (target = rs1+imm)
);

    // TODO: Extract rs1, rs2, and rd directly from the instruction bits
    assign rs1 = instr[19:15]; // change me
    assign rs2 = instr[24:20]; // change me
    assign rd  = instr[11:7]; // change me

    wire [6:0] opcode  = instr[6:0];
    wire [2:0] funct3  = instr[14:12];
    wire [6:0] funct7  = instr[31:25];

    // TODO: Generate the 5 immediate types (I, S, B, U, J) by slicing and sign-extending
    wire [31:0] imm_i = {{20{instr[31]}},instr[31:20]};
    wire [31:0] imm_s = {{20{instr[31]}},instr[31:25],instr[11:7]};
    wire [31:0] imm_b = {{19{instr[31]}},instr[31],instr[7],instr[11:8],1'b0};
    wire [31:0] imm_u = {{12{instr[31]}},instr[31:12],1'b0};
    wire [31:0] imm_j = {{11{instr[31]}},instr[31],instr[19:12],instr[20],instr[30:21],1'b0};

    localparam OP_LOAD   = 7'b0000011; //lw
    localparam OP_STORE  = 7'b0100011; //sw
    localparam OP_IMM    = 7'b0010011; //addi
    localparam OP_REG    = 7'b0110011; //add, sub, and, or, xor, sll, srl, sra, slt, sltu
    localparam OP_BRANCH = 7'b1100011; //beq, bne, blt, bge, bltu, bgeu
    
    always @(*) begin
        // Default values to prevent latches
        imm       = 32'h0;
        alu_op    = 4'b0000;
        alu_src   = 1'b0;
        mem_read  = 1'b0;
        mem_write = 1'b0;
        reg_write = 1'b0;
        wb_sel    = 2'b00;
        branch    = 1'b0;
        jump      = 1'b0;
        jalr      = 1'b0;

        case (opcode)
            // TODO: Decode specific opcodes like OP_IMM, OP_REG, OP_LOAD, OP_STORE, OP_BRANCH
            
            default: begin
                // Unknown opcode
            end
        endcase
    end

endmodule
