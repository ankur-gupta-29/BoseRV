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
    wire [31:0] pc_IF,pc_ID,PC_EX;            // current program counter
    wire [31:0] instr_IF,instr_ID;         // raw 32-bit instruction from imem

    // Register addresses decoded from instruction bits
    wire [4:0]  rs1_ID, rs2_ID, rd_ID;

    // Control signals from decoder
    wire [31:0] imm_ID,imm_EX;           // sign-extended immediate
    wire [3:0]  alu_op_ID,alu_op_EX;        // ALU operation selector
    wire        alu_src_ID,alu_src_EX;       // 0=rs2, 1=imm as ALU B operand
    wire        mem_read_ID,mem_read_EX;      // 1 = load instruction
    wire        mem_write_ID,mem_write_EX;     // 1 = store instruction
    wire        reg_write_ID,reg_write_EX;     // 1 = write result to rd
    wire [1:0]  wb_sel_ID,wb_sel_EX;        // writeback source: 00=ALU, 01=mem, 10=PC+4
    wire        branch_ID,branch_EX;        // 1 = B-type instruction
    wire        jump_ID,jump_EX;          // 1 = JAL or JALR
    wire        jalr_ID,jalr_EX;          // 1 = specifically JALR
    wire        auipc_ID,auipc_EX;         // 1 = AUIPC (ALU A = PC)
    wire        lui_ID,lui_EX;           // 1 = LUI   (ALU A = 0)

    // Datapath wires
    wire [31:0] rs1_data_ID,rs1_data_EX, rs2_data_ID,rs2_data_EX;   // register file outputs
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
    // TODO 2: Instantiate fetch module (driven by IF wires)
    
    fetch fetch_inst (
        .clk(clk),
        .rst(rst),
        .branch_taken(branch_taken),
        .jump(jump),
        .branch_target(branch_target),
        .jump_target(jump_target),
        .pc(pc_IF),
        .instr(instr_IF)
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
        .instr_out(instr_ID)
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
        .we(reg_write_ID),
        .rs1(rs1_ID),
        .rs2(rs2_ID),
        .rd(rd_ID),
        .wdata(writeback_data_ID),  // write data comes from writeback MUX below
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
        .lui_out(lui_EX)

    );
    
    // ── Stage 3: EXECUTE ──────────────────────────────────────
    // TODO 6: Instantiate alu module and branch/jump target logic (driven by EX wires)
    
    // ── EX/MEM Pipeline Register ───────────────────────────────
    // TODO 7: Instantiate ex_mem module
    ex_mem ex_mem_inst(
        .clk(clk),
        .rst(rst),
        .alu_result_in(),
        .rs2_data_in(),
        .pc_plus4_in(),
        .branch_target_in(),
        .jump_target_in(),
        .branch_taken_in(),
        .alu_zero_in(),
        .rd_in(),
        .mem_read_in(),
        .mem_write_in(),
        .reg_write_in(),
        .wb_sel_in(),
        .jump_in(),
        .alu_result_out(),
        .rs2_data_out(),
        .pc_plus4_out(),
        .branch_target_out(),
        .jump_target_out(),
        .branch_taken_out(),
        .alu_zero_out(),
        .rd_out(),
        .mem_read_out(),
        .mem_write_out(),
        .reg_write_out(),
        .wb_sel_out(),
        .jump_out()        
        

    );
    
    // ── Stage 4: MEMORY ───────────────────────────────────────
    // TODO 8: Instantiate dmem module (driven by MEM wires)
    dmem dmem_inst(
        .clk(clk),
        .we(),
        .addr(),
        .wd(),
        .rd()
    );

    
    // ── MEM/WB Pipeline Register ───────────────────────────────
    // TODO 9: Instantiate mem_wb module
    mem_wb mem_wb_inst(
        .clk(),
        .rst(),
        .alu_result_in(),
        .mem_read_data_in(),
        .pc_plus4_in(),
        .rd_in(),
        .reg_write_in(),
        .wb_sel_in(),
        .alu_result_out(),
        .mem_read_data_out(),
        .pc_plus4_out(),
        .rd_out(),
        .reg_write_out(),
        .wb_sel_out(),

    );

    
    // ── Stage 5: WRITEBACK ────────────────────────────────────
    // TODO 10: Implement the writeback MUX (wb_sel) to drive regfile write data (WB wires)
    
    // ── Hazard & Flush Logic (For Now) ────────────────────────
    // Note: When branch_taken_MEM is 1, you must flush the pipeline!
    // Connect a `flush` signal to the reset inputs of your IF/ID and ID/EX registers to insert NOPs.

endmodule
