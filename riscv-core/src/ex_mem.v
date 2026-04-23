// ============================================================
// BoseRV — EX/MEM Pipeline Register (Assignment C3)
//
// Sits between Execute stage and Memory stage.
// EX stage computes the ALU result and branch decision;
// this register holds them for the Memory stage.
//
// Also carries the branch/jump target and PC+4 forward
// so the fetch stage can be redirected in the next cycle.
// ============================================================
module ex_mem (
    input         clk,
    input         rst,

    // ── Data inputs from EX stage ──────────────────────────
    input  [31:0] alu_result_in,   // address (loads/stores) or computed result
    input  [31:0] rs2_data_in,     // store write data (SW: mem[addr] = rs2)
    input  [31:0] pc_plus4_in,     // PC+4 of this instruction (JAL/JALR return addr)
    input  [31:0] branch_target_in,// PC + imm (branch/JAL target)
    input  [31:0] jump_target_in,  // (rs1+imm)&~1 (JALR target)
    input         branch_taken_in, // branch condition evaluated in EX
    input         alu_zero_in,     // alu_result == 0 (kept for debug/trace)
    input  [4:0]  rd_in,           // destination register

    // ── Control inputs from EX stage ───────────────────────
    input         mem_read_in,
    input         mem_write_in,
    input         reg_write_in,
    input  [1:0]  wb_sel_in,
    input         jump_in,

    // ── Data outputs to MEM stage ──────────────────────────
    output reg [31:0] alu_result_out,
    output reg [31:0] rs2_data_out,
    output reg [31:0] pc_plus4_out,
    output reg [31:0] branch_target_out,
    output reg [31:0] jump_target_out,
    output reg        branch_taken_out,
    output reg        alu_zero_out,
    output reg [4:0]  rd_out,

    // ── Control outputs to MEM stage ───────────────────────
    output reg        mem_read_out,
    output reg        mem_write_out,
    output reg        reg_write_out,
    output reg [1:0]  wb_sel_out,
    output reg        jump_out
);

    // TODO (C3 — part 1): Implement the pipeline register.
    //
    // Same pattern as IF/ID and ID/EX:
    //   - On rst:         zero ALL outputs (prevents ghost writes to memory)
    //   - On posedge clk: latch every _in to its _out
    //
    // Pay attention to mem_write_out — if it stays 1 during reset,
    // the data memory will perform a spurious write on the next cycle.

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // TODO: zero ALL outputs
        end else begin
            // TODO: latch all inputs to outputs
        end
    end

endmodule
