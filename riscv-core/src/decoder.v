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
    output reg        jalr,      // specifically JALR (target = rs1+imm)

    //AUIPC
    output reg        auipc
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
    wire [31:0] imm_b = {{19{instr[31]}},instr[31],instr[7],instr[30:25],instr[11:8],1'b0};
    wire [31:0] imm_u = {instr[31:12],12'b0};
    wire [31:0] imm_j = {{11{instr[31]}},instr[31],instr[19:12],instr[20],instr[30:21],1'b0};

    localparam OP_LOAD   = 7'b0000011; //lw
    localparam OP_STORE  = 7'b0100011; //sw
    localparam OP_IMM    = 7'b0010011; //addi
    localparam OP_REG    = 7'b0110011; //add, sub, and, or, xor, sll, srl, sra, slt, sltu
    localparam OP_BRANCH = 7'b1100011; //beq, bne, blt, bge, bltu, bgeu
    localparam OP_LUI    = 7'b0110111; //lui
    localparam OP_AUIPC  = 7'b0010111; //auipc
    localparam OP_JAL    = 7'b1101111; //jal
    localparam OP_JALR   = 7'b1100111; //jalr
    
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
        auipc     = 1'b0;

        case (opcode)
            // TODO: Decode specific opcodes like OP_IMM, OP_REG, OP_LOAD, OP_STORE, OP_BRANCH
            OP_IMM : begin
                imm       = imm_i;
                reg_write = 1'b1;
                alu_src   = 1'b1;
                wb_sel    = 2'b00;
                case(funct3)
                    3'b000:       alu_op = 4'b0000;
                    3'b111:       alu_op = 4'b0010;
                    3'b110:       alu_op = 4'b0011;
                    3'b100:       alu_op = 4'b0100;
                    3'b010:       alu_op = 4'b1000;
                    3'b011:       alu_op = 4'b1001;
                    3'b001:       alu_op = 4'b0101;
                    3'b101:       alu_op = funct7[5]? 4'b0111:4'b0110;
                    default:      alu_op = 4'b0000;
                endcase
            end
            OP_REG : begin
                imm       = 32'b0;
                reg_write = 1'b1;
                alu_src   = 1'b0;
                wb_sel    = 2'b00;
                case(funct3)
                    3'b000:       alu_op = funct7[5] ? 4'b0001 : 4'b0000; // SUB vs ADD uses funct7 bit 5!
                    3'b111:       alu_op = 4'b0010;
                    3'b110:       alu_op = 4'b0011;
                    3'b100:       alu_op = 4'b0100;
                    3'b001:       alu_op = 4'b0101;
                    3'b101:       alu_op = funct7[5]? 4'b0111:4'b0110;
                    3'b011:       alu_op = 4'b1001;
                    3'b010:       alu_op = 4'b1000;
                    default:      alu_op = 4'b0000;
                endcase
            end
            OP_LOAD : begin
                imm       = imm_i;
                reg_write = 1'b1;
                mem_read  = 1'b1;
                wb_sel    = 2'b01;
                alu_src   = 1'b1;
                alu_op    = 4'b0000;
            end
            OP_STORE : begin
                imm       = imm_s;
                reg_write = 1'b0;
                mem_write = 1'b1;
                wb_sel    = 2'b00;
                alu_src   = 1'b1;
                alu_op    = 4'b0000;
            end
            OP_BRANCH : begin
                imm       = imm_b;
                branch    = 1'b1;
                reg_write = 1'b0;
                alu_src   = 1'b0;
                case(funct3)
                    3'b000:       alu_op = 4'b0001; // BEQ uses subtraction
                    3'b001:       alu_op = 4'b0001; // BNE
                    3'b100:       alu_op = 4'b1001;
                    // TODO (Assignment B4): Add missing OP_BRANCH funct3 cases (BLT, BGE, etc.)
                    default:      alu_op = 4'b0001;
                endcase
                
            end
            OP_LUI: begin
                imm = imm_u;
                reg_write = 1'b1;
                wb_sel  = 2'b00;
                alu_src = 1'b1;
                // TODO (B4 - Fix 1): Change alu_op from SLL (4'b0101) to ADD (4'b0000)
                // LUI works by computing ADD(x0, imm_u). Since rs1=x0=0, result = 0 + imm_u = imm_u ✓
                alu_op = 4'b0000; // <-- WRONG! Change this to 4'b0000
            end
            OP_AUIPC : begin
                imm = imm_u;
                reg_write = 1'b1;
                wb_sel    = 2'b00;
                alu_src   = 1'b1;
                alu_op    = 4'b0000;
                auipc     = 1'b1;
            end
            OP_JAL: begin
                imm  = imm_j;
                jump = 1'b1;
                reg_write = 1'b1;
                wb_sel = 2'b10;
            end
            OP_JALR: begin
                imm  = imm_i;
                jalr = 1'b1;
                reg_write = 1'b1;
                wb_sel  = 2'b10;
                alu_src = 1'b0;
                jump    = 1'b0;
            end
            

            default: begin
                // Unknown opcode
            end

        endcase
    end

endmodule
