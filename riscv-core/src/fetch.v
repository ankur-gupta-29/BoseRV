// ============================================================
// BoseRV — Fetch Stage (PC + Instruction Fetch)
//
// Holds the Program Counter and drives instruction memory each cycle.
// Priority (highest → lowest): rst > branch_taken > jump > PC+4
// ============================================================
module fetch (
    input         clk,
    input         rst,
    input         branch_taken,  // 1 when branch condition is true (from top.v)
    input         jump,          // 1 for JAL or JALR (from decoder)
    input  [31:0] branch_target, // PC + imm  — used by branches and JAL
    input  [31:0] jump_target,   // (rs1 + imm) & ~1 — used by JALR only
    output [31:0] pc,            // current PC value (visible to top.v for PC+4, AUIPC, etc.)
    output [31:0] instr          // instruction word from instruction memory
);

    reg [31:0] pc_reg;

    // PC update logic — registered on rising clock edge
    // Priority matters: branch check comes before jump so that a JAL/JALR
    // that also sets branch=1 (shouldn't happen in valid code) doesn't conflict.
    always @(posedge clk or posedge rst) begin
        if (rst)
            pc_reg <= 32'b0;          // reset to address 0 (entry point)
        else if (branch_taken)
            pc_reg <= branch_target;  // PC-relative branch (PC + imm_b)
        else if (jump)
            pc_reg <= jump_target;    // absolute jump target (JAL uses branch_target via top.v; JALR uses jump_target)
        else
            pc_reg <= pc_reg + 4;     // sequential execution: advance one word
    end

    assign pc = pc_reg;

    // Instruction memory: combinational read — always outputs instr at pc_reg
    imem u_imem(
        .addr(pc_reg),
        .instr(instr)
    );

endmodule
