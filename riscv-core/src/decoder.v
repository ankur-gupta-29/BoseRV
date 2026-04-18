// ============================================================
// BoseRV — Instruction Decoder + Control Unit
//
// Takes a raw 32-bit RISC-V instruction and produces:
//   • Register addresses (rs1, rs2, rd)
//   • Sign-extended immediate in the right format (I/S/B/U/J)
//   • ALU operation code matching alu.v encoding
//   • All datapath control signals
//
// All outputs are purely combinational — no clock needed.
// ============================================================
module decoder (
    input  [31:0] instr,       // 32-bit raw instruction from fetch stage

    // Register addresses — fixed bit positions in every RV32I instruction
    output [4:0]  rs1,         // source register 1  (bits 19:15)
    output [4:0]  rs2,         // source register 2  (bits 24:20)
    output [4:0]  rd,          // destination register (bits 11:7)

    // Immediate — sign-extended to 32 bits, format chosen by opcode
    output reg [31:0] imm,

    // ALU control
    output reg [3:0]  alu_op,  // which operation the ALU should perform
    output reg        alu_src, // 0 = B operand comes from rs2, 1 = comes from imm

    // Memory control
    output reg        mem_read,  // 1 for load instructions (LW)
    output reg        mem_write, // 1 for store instructions (SW)

    // Writeback control
    output reg        reg_write, // 1 when result should be written back to rd
    output reg [1:0]  wb_sel,   // selects writeback source: 0=ALU, 1=mem, 2=PC+4

    // PC control
    output reg        branch,   // 1 for B-type instructions (BEQ, BNE, BLT, …)
    output reg        jump,     // 1 for JAL or JALR
    output reg        jalr,     // 1 specifically for JALR (so top.v uses rs1+imm target)

    // Upper-immediate flags (need special A-operand routing in top.v)
    output reg        auipc,    // 1 for AUIPC: ALU computes PC + imm_u
    output reg        lui       // 1 for LUI:   ALU computes 0  + imm_u
);

    // Register addresses are at the same bit positions in ALL RV32I formats
    assign rs1 = instr[19:15];
    assign rs2 = instr[24:20];
    assign rd  = instr[11:7];

    // Instruction sub-fields used to distinguish operations within an opcode group
    wire [6:0] opcode = instr[6:0];
    wire [2:0] funct3 = instr[14:12]; // selects variant within opcode group (e.g. ADD vs SUB)
    wire [6:0] funct7 = instr[31:25]; // upper bits; bit 5 distinguishes SUB/SRA from ADD/SRL

    // ----------------------------------------------------------------
    // Immediate encodings — RV32I has 5 formats; bits are scrambled to
    // keep rs1/rs2/rd at the same positions across all formats.
    //
    // bit 31 is always the sign bit; we replicate it to fill the upper bits.
    // ----------------------------------------------------------------

    // I-type: loads, ALU-immediate, JALR  (12-bit signed imm)
    wire [31:0] imm_i = {{20{instr[31]}}, instr[31:20]};

    // S-type: stores  (imm split across bits 31:25 and 11:7 to free up rs2 field)
    wire [31:0] imm_s = {{20{instr[31]}}, instr[31:25], instr[11:7]};

    // B-type: branches  (13-bit signed, bit 0 always 0 — targets must be 2-byte aligned)
    // Bit positions are scrambled so rd field can stay in place for other formats.
    wire [31:0] imm_b = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};

    // U-type: LUI / AUIPC  (20-bit upper immediate; lower 12 bits zeroed)
    wire [31:0] imm_u = {instr[31:12], 12'b0};

    // J-type: JAL  (21-bit signed, bit 0 always 0)
    // Bits are scrambled similarly to B-type.
    wire [31:0] imm_j = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};

    // Opcode constants from RV32I spec Table 24.1
    localparam OP_LOAD   = 7'b0000011; // LW
    localparam OP_STORE  = 7'b0100011; // SW
    localparam OP_IMM    = 7'b0010011; // ADDI, SLTI, XORI, ORI, ANDI, SLLI, SRLI, SRAI
    localparam OP_REG    = 7'b0110011; // ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
    localparam OP_BRANCH = 7'b1100011; // BEQ, BNE, BLT, BGE, BLTU, BGEU
    localparam OP_LUI    = 7'b0110111; // LUI
    localparam OP_AUIPC  = 7'b0010111; // AUIPC
    localparam OP_JAL    = 7'b1101111; // JAL
    localparam OP_JALR   = 7'b1100111; // JALR

    always @(*) begin
        // Safe defaults: NOP-like — no writes, no branches, ADD as placeholder op.
        // Without defaults every signal would need to be set in every branch,
        // and omissions would cause latches in synthesis.
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
        lui       = 1'b0;

        case (opcode)

            // ----------------------------------------------------------
            // I-type ALU: ADDI SLTI SLTIU XORI ORI ANDI SLLI SRLI SRAI
            // B operand = sign-extended 12-bit immediate (alu_src=1)
            // ----------------------------------------------------------
            OP_IMM: begin
                imm       = imm_i;
                reg_write = 1'b1;
                alu_src   = 1'b1;   // use immediate as ALU B operand
                wb_sel    = 2'b00;  // write ALU result to rd
                case (funct3)
                    3'b000: alu_op = 4'b0000; // ADDI
                    3'b111: alu_op = 4'b0010; // ANDI
                    3'b110: alu_op = 4'b0011; // ORI
                    3'b100: alu_op = 4'b0100; // XORI
                    3'b010: alu_op = 4'b1000; // SLTI  (signed compare)
                    3'b011: alu_op = 4'b1001; // SLTIU (unsigned compare)
                    3'b001: alu_op = 4'b0101; // SLLI
                    // SRLI vs SRAI: funct7[5]=0 → logical, funct7[5]=1 → arithmetic
                    3'b101: alu_op = funct7[5] ? 4'b0111 : 4'b0110;
                    default: alu_op = 4'b0000;
                endcase
            end

            // ----------------------------------------------------------
            // R-type: ADD SUB SLL SLT SLTU XOR SRL SRA OR AND
            // Both operands from registers (alu_src=0)
            // ADD vs SUB distinguished by funct7[5]
            // ----------------------------------------------------------
            OP_REG: begin
                reg_write = 1'b1;
                alu_src   = 1'b0;   // use rs2 as ALU B operand
                wb_sel    = 2'b00;
                case (funct3)
                    // funct7[5]=0 → ADD, funct7[5]=1 → SUB
                    3'b000: alu_op = funct7[5] ? 4'b0001 : 4'b0000;
                    3'b111: alu_op = 4'b0010; // AND
                    3'b110: alu_op = 4'b0011; // OR
                    3'b100: alu_op = 4'b0100; // XOR
                    3'b001: alu_op = 4'b0101; // SLL
                    // SRL vs SRA: same funct7[5] trick as SRLI/SRAI
                    3'b101: alu_op = funct7[5] ? 4'b0111 : 4'b0110;
                    3'b011: alu_op = 4'b1001; // SLTU
                    3'b010: alu_op = 4'b1000; // SLT
                    default: alu_op = 4'b0000;
                endcase
            end

            // ----------------------------------------------------------
            // Load: LW
            // ALU computes address = rs1 + imm_i; result goes to dmem,
            // dmem output is written back to rd (wb_sel=1).
            // ----------------------------------------------------------
            OP_LOAD: begin
                imm       = imm_i;
                reg_write = 1'b1;
                mem_read  = 1'b1;
                wb_sel    = 2'b01;  // write memory read data to rd
                alu_src   = 1'b1;   // address = rs1 + imm
                alu_op    = 4'b0000; // ADD
            end

            // ----------------------------------------------------------
            // Store: SW
            // ALU computes address = rs1 + imm_s; rs2 written to that address.
            // No rd write (reg_write=0).
            // ----------------------------------------------------------
            OP_STORE: begin
                imm       = imm_s;
                reg_write = 1'b0;
                mem_write = 1'b1;
                alu_src   = 1'b1;   // address = rs1 + imm
                alu_op    = 4'b0000; // ADD
            end

            // ----------------------------------------------------------
            // Branches: BEQ BNE BLT BGE BLTU BGEU
            // ALU computes comparison; top.v reads ALU result + funct3
            // to decide branch_taken. No register write.
            // ----------------------------------------------------------
            OP_BRANCH: begin
                imm       = imm_b;  // PC-relative offset (already *2, bit0 forced 0)
                branch    = 1'b1;
                reg_write = 1'b0;
                alu_src   = 1'b0;   // compare rs1 vs rs2
                case (funct3)
                    3'b000: alu_op = 4'b0001; // BEQ  — SUB; branch if zero
                    3'b001: alu_op = 4'b0001; // BNE  — SUB; branch if NOT zero
                    3'b100: alu_op = 4'b1000; // BLT  — SLT;  branch if result==1
                    3'b101: alu_op = 4'b1000; // BGE  — SLT;  branch if result==0
                    3'b110: alu_op = 4'b1001; // BLTU — SLTU; branch if result==1
                    3'b111: alu_op = 4'b1001; // BGEU — SLTU; branch if result==0
                    default: alu_op = 4'b0001;
                endcase
            end

            // ----------------------------------------------------------
            // LUI: Load Upper Immediate
            // rd = imm_u  (upper 20 bits, lower 12 zeroed by imm_u encoding)
            // Achieved by: ALU ADD(0, imm_u). top.v forces A=0 when lui=1.
            // ----------------------------------------------------------
            OP_LUI: begin
                imm       = imm_u;
                reg_write = 1'b1;
                wb_sel    = 2'b00;
                alu_src   = 1'b1;
                lui       = 1'b1;   // signals top.v to route 0 as ALU A input
                alu_op    = 4'b0000; // ADD(0, imm_u) = imm_u
            end

            // ----------------------------------------------------------
            // AUIPC: Add Upper Immediate to PC
            // rd = PC + imm_u
            // top.v routes PC as ALU A input when auipc=1.
            // ----------------------------------------------------------
            OP_AUIPC: begin
                imm       = imm_u;
                reg_write = 1'b1;
                wb_sel    = 2'b00;
                alu_src   = 1'b1;
                alu_op    = 4'b0000; // ADD(PC, imm_u)
                auipc     = 1'b1;   // signals top.v to route PC as ALU A input
            end

            // ----------------------------------------------------------
            // JAL: Jump And Link
            // PC = PC + imm_j  (unconditional jump, PC-relative)
            // rd = PC + 4      (return address saved, wb_sel=2)
            // ----------------------------------------------------------
            OP_JAL: begin
                imm       = imm_j;
                jump      = 1'b1;
                reg_write = 1'b1;
                wb_sel    = 2'b10;  // write PC+4 (return address) to rd
            end

            // ----------------------------------------------------------
            // JALR: Jump And Link Register
            // PC = (rs1 + imm_i) & ~1  (absolute jump; LSB cleared per spec)
            // rd = PC + 4
            // jalr=1 tells top.v to use jump_target (rs1+imm) not branch_target (PC+imm)
            // ----------------------------------------------------------
            OP_JALR: begin
                imm       = imm_i;
                jalr      = 1'b1;   // use rs1-relative target, not PC-relative
                jump      = 1'b1;
                reg_write = 1'b1;
                wb_sel    = 2'b10;  // write PC+4 to rd
                alu_src   = 1'b0;
            end

            default: begin
                // Unknown/unsupported opcode — all defaults apply (NOP)
            end

        endcase
    end

endmodule
