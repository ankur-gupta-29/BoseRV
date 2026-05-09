module pipe_top (
    input clk,
    input rst
);

    // =========================================================================
    // BoseRV: 5-Stage Pipelined Top Level (Module 3 - Assignment C4)
    // =========================================================================

    // ── Wire Declarations ──────────────────────────────────────
    // TODO 1: Declare wires for all pipeline stages. 
    // It helps to name wires with their stage suffix, e.g., `pc_IF`, `pc_ID`, `pc_EX`.
// ── Wire declarations ──────────────────────────────────────
    wire [31:0] pc_IF,pc_ID,pc_EX,pc_plus4_MEM,pc_plus4_WB;            // current program counter
    wire [31:0] instr_IF,instr_ID;         // raw 32-bit instruction from imem

    // Register addresses decoded from instruction bits
    wire [4:0]  rs1_ID, rs2_ID, rd_ID,rs1_EX, rs2_EX, rd_EX,rd_MEM,rd_WB;

    // Control signals from decoder
    wire [31:0] imm_ID,imm_EX;           // sign-extended immediate
    wire [3:0]  alu_op_ID,alu_op_EX;        // ALU operation selector
    wire        alu_src_ID,alu_src_EX;       // 0=rs2, 1=imm as ALU B operand
    wire        mem_read_ID,mem_read_EX,mem_read_MEM;      // 1 = load instruction
    wire        mem_write_ID,mem_write_EX,mem_write_MEM;     // 1 = store instruction
    wire        reg_write_ID,reg_write_EX,reg_write_MEM,reg_write_WB;     // 1 = write result to rd
    wire [1:0]  wb_sel_ID,wb_sel_EX,wb_sel_MEM,wb_sel_WB;        // writeback source: 00=ALU, 01=mem, 10=PC+4
    wire        branch_ID,branch_EX;        // 1 = B-type instruction
    wire        jump_ID,jump_EX,jump_MEM;          // 1 = JAL or JALR
    wire        jalr_ID,jalr_EX;          // 1 = specifically JALR
    wire        auipc_ID,auipc_EX;         // 1 = AUIPC (ALU A = PC)
    wire        lui_ID,lui_EX;           // 1 = LUI   (ALU A = 0)

    // Datapath wires
    wire [31:0] rs1_data_ID,rs1_data_EX, rs2_data_ID,rs2_data_EX,rs2_data_MEM;   // register file outputs
    wire [31:0] alu_b_EX;             // ALU B operand after MUX
    wire [31:0] alu_result_EX,alu_result_MEM,alu_result_WB;           // ALU output
    wire        alu_zero_EX,alu_zero_MEM;             // 1 when alu_result == 0
    wire [31:0] mem_read_data,mem_read_data_WB;        // data memory read output
    wire [31:0] writeback_data;       // final value written to rd
    

    // Branch / jump target wires
    wire        branch_taken_EX,branch_taken_MEM;         // final branch decision
    wire [31:0] branch_target_EX,branch_target_MEM;        // PC + imm  (B-type and JAL)
    wire [31:0] jump_target_EX,jump_target_MEM;          // (rs1 + imm) & ~1  (JALR) or branch_target (JAL)

    // funct3 field of current instruction — needed for branch condition decode
    wire [2:0]  funct3_EX;

    // forwarding
    wire [1:0] forward_A,forward_B;
    wire [31:0] fwd_rs1,fwd_rs2;
    // hazard
    wire stall,flush;


    // ── Stage 1: FETCH ────────────────────────────────────────
    // TODO 2: Instantiate fetch module (driven by IF wires)
    
    fetch fetch_inst (
        .clk(clk),
        .rst(rst),
        .branch_taken(branch_taken_EX),
        .jump(jump_EX),
        .branch_target(branch_target_EX),
        .jump_target(jump_target_EX),
        .pc(pc_IF),
        .instr(instr_IF),
        .stall(stall)
    );
    

    // ── IF/ID Pipeline Register ───────────────────────────────
    // TODO 3: Instantiate if_id module
    // This sits between Fetch and Decode!
    
    if_id if_id_inst (
        .clk(clk),
        .rst(rst),
        .pc_in(pc_IF),
        .pc_out(pc_ID),
        .instr_in(instr_IF),
        .instr_out(instr_ID),
        .stall(stall),
        .flush(flush)
    );
    

    // ── Stage 2: DECODE ───────────────────────────────────────
    // TODO 4: Instantiate decoder and regfile modules (driven by ID wires)
    decoder decoder_inst (
        .instr(instr_ID),
        .rs1(rs1_ID),
        .rs2(rs2_ID),
        .rd(rd_ID),
        .imm(imm_ID),
        .alu_op(alu_op_ID),
        .alu_src(alu_src_ID),
        .mem_read(mem_read_ID),
        .mem_write(mem_write_ID),
        .reg_write(reg_write_ID),
        .wb_sel(wb_sel_ID),
        .branch(branch_ID),
        .jump(jump_ID),
        .jalr(jalr_ID),
        .auipc(auipc_ID),
        .lui(lui_ID)
    );

    // Register file: reads are combinational, write is clocked.
    regfile regfile_inst (
        .clk(clk),
        .we(reg_write_WB),
        .rs1(rs1_ID),
        .rs2(rs2_ID),
        .rd(rd_WB),
        .wdata(writeback_data),  // write data comes from writeback MUX below
        .rdata1(rs1_data_ID),
        .rdata2(rs2_data_ID)
    );
    
    // ── ID/EX Pipeline Register ───────────────────────────────
    // TODO 5: Instantiate id_ex module
    id_ex id_ex_inst (
        .clk(clk),
        .rst(rst),
        .pc_in(pc_ID),       
        .rs1_data_in(rs1_data_ID), 
        .rs2_data_in(rs2_data_ID),  
        .imm_in(imm_ID),      
        .rs1_in(rs1_ID),       
        .rs2_in(rs2_ID),       
        .rd_in(rd_ID),        
        .alu_op_in(alu_op_ID),
        .alu_src_in(alu_src_ID),
        .mem_read_in(mem_read_ID),
        .mem_write_in(mem_write_ID),
        .reg_write_in(reg_write_ID),
        .wb_sel_in(wb_sel_ID),
        .branch_in(branch_ID),
        .jump_in(jump_ID),
        .jalr_in(jalr_ID),
        .auipc_in(auipc_ID),
        .funct3_in(instr_ID[14:12]),
        .lui_in(lui_ID),
        .pc_out(pc_EX),
        .rs1_data_out(rs1_data_EX),
        .rs2_data_out(rs2_data_EX),
        .imm_out(imm_EX),
        .rs1_out(rs1_EX),
        .rs2_out(rs2_EX),
        .rd_out(rd_EX),
        .alu_op_out(alu_op_EX),
        .alu_src_out(alu_src_EX),
        .mem_read_out(mem_read_EX),
        .mem_write_out(mem_write_EX),
        .reg_write_out(reg_write_EX),
        .wb_sel_out(wb_sel_EX),
        .branch_out(branch_EX),
        .jump_out(jump_EX),
        .jalr_out(jalr_EX),
        .auipc_out(auipc_EX),
        .funct3_out(funct3_EX),
        .lui_out(lui_EX),
        .stall(stall),
        .flush(flush)

    );
    
    // ── Stage 3: EXECUTE ──────────────────────────────────────
    // TODO 6: Instantiate alu module and branch/jump target logic (driven by EX wires)
    
    assign fwd_rs1 = (forward_A == 2'b10) ? alu_result_MEM :
                     (forward_A == 2'b01) ? writeback_data : rs1_data_EX;
    assign fwd_rs2 = (forward_B == 2'b10) ? alu_result_MEM :
                     (forward_B == 2'b01) ? writeback_data : rs2_data_EX;
    assign alu_b_EX = alu_src_EX ? imm_EX : fwd_rs2;

    alu alu_inst(
        .a(auipc_EX ? pc_EX : lui_EX ? 32'h0 : fwd_rs1),
        .b(alu_b_EX),
        .op(alu_op_EX),
        .result(alu_result_EX),
        .zero(alu_zero_EX)
    );

    assign branch_target_EX = pc_EX + imm_EX;
    assign jump_target_EX = jalr_EX ? ((fwd_rs1 + imm_EX) & ~32'h1) : branch_target_EX;
    assign branch_taken_EX = branch_EX & (
        funct3_EX == 3'b000 ?  alu_zero_EX       :   // BEQ:  branch if rs1 == rs2
        funct3_EX == 3'b001 ? !alu_zero_EX       :   // BNE:  branch if rs1 != rs2
        funct3_EX == 3'b100 ?  alu_result_EX[0]  :   // BLT:  branch if rs1 <  rs2 (signed)
        funct3_EX == 3'b101 ? !alu_result_EX[0]  :   // BGE:  branch if rs1 >= rs2 (signed)
        funct3_EX == 3'b110 ?  alu_result_EX[0]  :   // BLTU: branch if rs1 <  rs2 (unsigned)
                           !alu_result_EX[0]  );   // BGEU: branch if rs1 >= rs2 (unsigned)


    
    // ── EX/MEM Pipeline Register ───────────────────────────────
    // TODO 7: Instantiate ex_mem module
    ex_mem ex_mem_inst(
        .clk(clk),
        .rst(rst),
        .alu_result_in(alu_result_EX),
        .rs2_data_in(fwd_rs2),
        .pc_plus4_in(pc_EX+4),
        .branch_target_in(branch_target_EX),
        .jump_target_in(jump_target_EX),
        .branch_taken_in(branch_taken_EX),
        .alu_zero_in(alu_zero_EX),
        .rd_in(rd_EX),
        .mem_read_in(mem_read_EX),
        .mem_write_in(mem_write_EX),
        .reg_write_in(reg_write_EX),
        .wb_sel_in(wb_sel_EX),
        .jump_in(jump_EX),
        .alu_result_out(alu_result_MEM),
        .rs2_data_out(rs2_data_MEM),
        .pc_plus4_out(pc_plus4_MEM),
        .branch_target_out(branch_target_MEM),
        .jump_target_out(jump_target_MEM),
        .branch_taken_out(branch_taken_MEM),
        .alu_zero_out(alu_zero_MEM),
        .rd_out(rd_MEM),
        .mem_read_out(mem_read_MEM),
        .mem_write_out(mem_write_MEM),
        .reg_write_out(reg_write_MEM),
        .wb_sel_out(wb_sel_MEM),
        .jump_out(jump_MEM)        
        

    );
    
    // ── Stage 4: MEMORY ───────────────────────────────────────
    // TODO 8: Instantiate dmem module (driven by MEM wires)
    dmem dmem_inst(
        .clk(clk),
        .we(mem_write_MEM),
        .addr(alu_result_MEM),
        .wd(rs2_data_MEM),
        .rd(mem_read_data)
    );

    
    // ── MEM/WB Pipeline Register ───────────────────────────────
    // TODO 9: Instantiate mem_wb module
    mem_wb mem_wb_inst(
        .clk(clk),
        .rst(rst),
        .alu_result_in(alu_result_MEM),
        .mem_read_data_in(mem_read_data),
        .pc_plus4_in(pc_plus4_MEM),
        .rd_in(rd_MEM),
        .reg_write_in(reg_write_MEM),
        .wb_sel_in(wb_sel_MEM),
        .alu_result_out(alu_result_WB),
        .mem_read_data_out(mem_read_data_WB),
        .pc_plus4_out(pc_plus4_WB),
        .rd_out(rd_WB),
        .reg_write_out(reg_write_WB),
        .wb_sel_out(wb_sel_WB)

    );

    
    // ── Stage 5: WRITEBACK ────────────────────────────────────
    // TODO 10: Implement the writeback MUX (wb_sel) to drive regfile write data (WB wires)
    assign writeback_data = (wb_sel_WB == 2'b00) ? alu_result_WB   :
                            (wb_sel_WB == 2'b01) ? mem_read_data_WB:
                                                    pc_plus4_WB;
    
    // ── Hazard & Flush Logic (For Now) ────────────────────────
    // Note: When branch_taken_MEM is 1, you must flush the pipeline!
    // Connect a `flush` signal to the reset inputs of your IF/ID and ID/EX registers to insert NOPs.
    forwarding forwarding_inst(
        .rs1_EX(rs1_EX),
        .rs2_EX(rs2_EX),
        .rd_MEM(rd_MEM),
        .reg_write_MEM(reg_write_MEM),
        .rd_WB(rd_WB),
        .reg_write_WB(reg_write_WB),
        .forward_A(forward_A),
        .forward_B(forward_B)

    );
    
    hazard hazard_inst(
        .mem_read_EX(mem_read_EX),
        .rd_EX(rd_EX),
        .rs1_ID(rs1_ID),
        .rs2_ID(rs2_ID),
        .stall(stall)
    );

    assign flush = (branch_taken_EX | jump_EX);
endmodule
