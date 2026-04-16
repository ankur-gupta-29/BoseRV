// ============================================================
// BoseRV — Fetch Stage (PC + Instruction Fetch)
// Assignment A3 — SKELETON
//
// Holds the Program Counter and fetches the instruction
// from instruction memory each cycle.
// ============================================================
module fetch (
    input         clk,
    input         rst,
    input         branch_taken, // from EX stage: branch condition true
    input         jump,         // from decoder: JAL or JALR
    input  [31:0] branch_target,// PC + imm (for branches and JAL)
    input  [31:0] jump_target,  // rs1 + imm (for JALR)
    output [31:0] pc,           // current PC (to decoder, also PC+4 calc)
    output [31:0] instr         // fetched instruction
);

    reg [31:0] pc_reg;

    // TODO: Implement PC register logic
    // On rst -> PC = 0
    // On branch_taken -> PC = branch_target
    // On jump -> PC = jump_target
    // Otherwise -> PC = PC + 4
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc_reg <= 32'b0;
        end
        else if(branch_taken) begin
            pc_reg <= branch_target;
        end
        else if(jump) begin
            pc_reg <= jump_target;
        end
        else begin
            pc_reg<=pc_reg+4;
        end
    end

    assign pc = pc_reg;

    // TODO: Instantiate the 'imem' module here and connect pc_reg to its address port
    imem u_imem( 
                .addr(pc_reg),
                .instr(instr)
               );

endmodule
