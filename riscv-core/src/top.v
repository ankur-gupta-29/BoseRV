// ============================================================
// BoseRV — Single-Cycle Top-Level Core
// Assignment A4 — SKELETON
//
// Datapath: Fetch -> Decode -> Execute -> Memory -> Writeback
// ============================================================
module top (
    input clk,
    input rst
);

    // TODO: Define all the wires needed to connect your modules
    wire [31:0] pc;
    wire [31:0] instr;
    wire [4:0] rs1,rs2,rd;
    wire [31:0] imm;
    wire [3:0] alu_op;
    wire alu_src,mem_read,mem_write,reg_write,branch,jump,jalr;
    wire [1:0] wb_sel;
    wire [31:0] rs1_data,rs2_data;
    wire [31:0] alu_result;
    wire alu_zero;
    wire [31:0] mem_read_data;
    wire [31:0] alu_b_in;
    wire [31:0] writeback_data;
    wire branch_taken;
    wire [31:0] branch_target;
    wire [31:0] jump_target;  

    

    // TODO: Instantiate fetch
    fetch fetch_inst(
        .clk(clk),
        .rst(rst),
        .branch_taken(branch_taken), 
        .jump(jump),         
        .branch_target(branch_target),
        .jump_target(jump_target),  
        .pc(pc),           
        .instr(instr) 
    );
    
    // TODO: Instantiate decoder
    decoder decoder_inst(
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
        .jalr(jalr)       
    );
    // TODO: Instantiate regfile
    regfile regfile_inst(
        .clk(clk),
        .we(reg_write),           
        .rs1(rs1),
        .rs2(rs2),    
        .rd(rd),          
        .wdata(writeback_data),        
        .rdata1(rs1_data),      
        .rdata2(rs2_data)        
    );
    
    // TODO: Instantiate alu
    alu alu_inst(
        .a(rs1_data),
        .b(alu_b_in),
        .op(alu_op),
        .result(alu_result),
        .zero(alu_zero)
    );
    
    // TODO: Instantiate dmem
    dmem dmem_inst(
        .clk(clk),
        .we(mem_write),
        .addr(alu_result),
        .wd(rs2_data),
        .rd(mem_read_data)
    );
    
    // TODO: Implement Writeback MUX (select between ALU result, Mem Read Data, PC+4)
    assign writeback_data = wb_sel== 2'b00 ? alu_result : wb_sel == 2'b01 ? mem_read_data : (pc+4);
    // TODO: Implement Branch Target computation (PC + imm)
    assign alu_b_in = alu_src ? imm : rs2_data;
    // TODO: Implement Jump Target computation 
    assign branch_target = pc+imm;
    assign jump_target = jalr ? (rs1_data+imm):branch_target;
    // TODO: Evaluate branch conditions (is branch taken?)
    assign branch_taken = branch & alu_zero;

endmodule
