// ============================================================
// BoseRV — Single-Cycle Top-Level Core
//
// Classic 5-stage datapath collapsed into one cycle:
//   Fetch → Decode → Execute → Memory → Writeback
//
// Every stage combinationally feeds the next within a single clock period.
// The only sequential element is the PC register (inside fetch).
// ============================================================
module top (
    input clk,
    input rst
);

    // ── Wire declarations ──────────────────────────────────────
    wire [31:0] pc;            // current program counter
    wire [31:0] instr;         // raw 32-bit instruction from imem

    // Register addresses decoded from instruction bits
    wire [4:0]  rs1, rs2, rd;

    // Control signals from decoder
    wire [31:0] imm;           // sign-extended immediate
    wire [3:0]  alu_op;        // ALU operation selector
    wire        alu_src;       // 0=rs2, 1=imm as ALU B operand
    wire        mem_read;      // 1 = load instruction
    wire        mem_write;     // 1 = store instruction
    wire        reg_write;     // 1 = write result to rd
    wire [1:0]  wb_sel;        // writeback source: 00=ALU, 01=mem, 10=PC+4
    wire        branch;        // 1 = B-type instruction
    wire        jump;          // 1 = JAL or JALR
    wire        jalr;          // 1 = specifically JALR
    wire        auipc;         // 1 = AUIPC (ALU A = PC)
    wire        lui;           // 1 = LUI   (ALU A = 0)

    // Datapath wires
    wire [31:0] rs1_data, rs2_data;   // register file outputs
    wire [31:0] alu_b_in;             // ALU B operand after MUX
    wire [31:0] alu_result;           // ALU output
    wire        alu_zero;             // 1 when alu_result == 0
    wire [31:0] mem_read_data;        // data memory read output
    wire [31:0] writeback_data;       // final value written to rd

    // Branch / jump target wires
    wire        branch_taken;         // final branch decision
    wire [31:0] branch_target;        // PC + imm  (B-type and JAL)
    wire [31:0] jump_target;          // (rs1 + imm) & ~1  (JALR) or branch_target (JAL)

    // funct3 field of current instruction — needed for branch condition decode
    wire [2:0]  funct3 = instr[14:12];


    // ── Stage 1: FETCH ────────────────────────────────────────
    // PC advances each cycle; overridden on branches/jumps.
    fetch fetch_inst (
        .clk(clk),
        .rst(rst),
        .branch_taken(branch_taken),
        .jump(jump),
        .branch_target(branch_target),
        .jump_target(jump_target),
        .pc(pc),
        .instr(instr)
    );

    // ── Stage 2: DECODE ───────────────────────────────────────
    // Combinational: slices instruction bits, forms immediate, sets control signals.
    decoder decoder_inst (
        .instr(instr),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .imm(imm),
        .alu_op(alu_op),
        .alu_src(alu_src),
        .mem_read(mem_read),
        .mem_write(mem_write),
        .reg_write(reg_write),
        .wb_sel(wb_sel),
        .branch(branch),
        .jump(jump),
        .jalr(jalr),
        .auipc(auipc),
        .lui(lui)
    );

    // Register file: reads are combinational, write is clocked.
    regfile regfile_inst (
        .clk(clk),
        .we(reg_write),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .wdata(writeback_data),  // write data comes from writeback MUX below
        .rdata1(rs1_data),
        .rdata2(rs2_data)
    );

    // ── Stage 3: EXECUTE ──────────────────────────────────────
    // ALU A-operand MUX:
    //   auipc=1 → PC    (AUIPC: result = PC + imm_u)
    //   lui=1   → 0     (LUI:   result = 0  + imm_u = imm_u)
    //   default → rs1   (all other instructions)
    alu alu_inst (
        .a(auipc ? pc : lui ? 32'h0 : rs1_data),
        .b(alu_b_in),
        .op(alu_op),
        .result(alu_result),
        .zero(alu_zero)
    );

    // ALU B-operand MUX: immediate or register
    assign alu_b_in = alu_src ? imm : rs2_data;

    // ── Stage 4: MEMORY ───────────────────────────────────────
    // Address = ALU result (rs1 + imm for loads/stores).
    // Write data = rs2. Read is combinational; write is clocked.
    dmem dmem_inst (
        .clk(clk),
        .we(mem_write),
        .addr(alu_result),
        .wd(rs2_data),
        .rd(mem_read_data)
    );

    // ── Stage 5: WRITEBACK ────────────────────────────────────
    // Three possible sources for rd:
    //   00 → ALU result  (R-type, I-type ALU, LUI, AUIPC)
    //   01 → memory data (LW)
    //   10 → PC + 4      (JAL, JALR — saves return address)
    assign writeback_data = (wb_sel == 2'b00) ? alu_result   :
                            (wb_sel == 2'b01) ? mem_read_data :
                                                (pc + 4);

    // ── Branch / Jump target computation ─────────────────────
    // branch_target: PC-relative — used by B-type branches and JAL
    assign branch_target = pc + imm;

    // jump_target: JALR = (rs1 + imm) & ~1  (clear LSB per spec)
    //              JAL  = same as branch_target (top.v passes branch_target when jalr=0)
    assign jump_target = jalr ? ((rs1_data + imm) & ~32'h1) : branch_target;

    // ── Branch condition evaluation ───────────────────────────
    // branch=1 means it's a B-type instruction. The specific condition depends on funct3.
    // The ALU already computed the comparison (SUB for BEQ/BNE, SLT/SLTU for others).
    // We check ALU result bits — alu_result[0] is 1 when SLT/SLTU found "less-than".
    assign branch_taken = branch & (
        funct3 == 3'b000 ?  alu_zero       :   // BEQ:  branch if rs1 == rs2
        funct3 == 3'b001 ? !alu_zero       :   // BNE:  branch if rs1 != rs2
        funct3 == 3'b100 ?  alu_result[0]  :   // BLT:  branch if rs1 <  rs2 (signed)
        funct3 == 3'b101 ? !alu_result[0]  :   // BGE:  branch if rs1 >= rs2 (signed)
        funct3 == 3'b110 ?  alu_result[0]  :   // BLTU: branch if rs1 <  rs2 (unsigned)
                           !alu_result[0]  );   // BGEU: branch if rs1 >= rs2 (unsigned)

endmodule
