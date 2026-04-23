// ============================================================
// BoseRV — ID/EX Pipeline Register (Assignment C2)
//
// Sits between Decode stage and Execute stage.
// Latches ALL decoder outputs + register values on every clock.
//
// Why so many fields?
//   The Execute stage needs register values (rs1_data, rs2_data),
//   the immediate, and every control signal the decoder produced.
//   Once ID stage moves to the next instruction, this register
//   is the only place EX can get those values from.
// ============================================================
module id_ex (
    input         clk,
    input         rst,

    // ── Data inputs from ID stage ──────────────────────────
    input  [31:0] pc_in,        // PC of this instruction (for AUIPC, PC+4)
    input  [31:0] rs1_data_in,  // register file read port 1
    input  [31:0] rs2_data_in,  // register file read port 2
    input  [31:0] imm_in,       // sign-extended immediate

    // Register addresses — needed by forwarding unit (C4)
    input  [4:0]  rs1_in,       // source reg 1 address
    input  [4:0]  rs2_in,       // source reg 2 address
    input  [4:0]  rd_in,        // destination reg address

    // ── Control inputs from decoder ────────────────────────
    input  [3:0]  alu_op_in,
    input         alu_src_in,
    input         mem_read_in,
    input         mem_write_in,
    input         reg_write_in,
    input  [1:0]  wb_sel_in,
    input         branch_in,
    input         jump_in,
    input         jalr_in,
    input         auipc_in,
    input         lui_in,

    // ── Data outputs to EX stage ───────────────────────────
    output reg [31:0] pc_out,
    output reg [31:0] rs1_data_out,
    output reg [31:0] rs2_data_out,
    output reg [31:0] imm_out,
    output reg [4:0]  rs1_out,
    output reg [4:0]  rs2_out,
    output reg [4:0]  rd_out,

    // ── Control outputs to EX stage ────────────────────────
    output reg [3:0]  alu_op_out,
    output reg        alu_src_out,
    output reg        mem_read_out,
    output reg        mem_write_out,
    output reg        reg_write_out,
    output reg [1:0]  wb_sel_out,
    output reg        branch_out,
    output reg        jump_out,
    output reg        jalr_out,
    output reg        auipc_out,
    output reg        lui_out
);

    // TODO (C2): Implement the pipeline register.
    //
    // Rules:
    //   - On rst: ALL outputs = 0 (zeroing control signals = NOP in pipeline)
    //   - On posedge clk: latch every _in to its matching _out
    //
    // There are a lot of signals but the pattern is identical for each:
    //   rd_out <= rd_in;  alu_op_out <= alu_op_in;  etc.
    //
    // Zeroing control signals on reset is important — if reg_write_out=1
    // during reset, a garbage value could be written to the register file.

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // TODO: zero ALL outputs
            pc_out          <= 0;
            rs1_data_out    <= 0;
            rs2_data_out    <= 0;
            imm_out         <= 0;
            rs1_out         <= 0;
            rs2_out         <= 0;
            rd_out          <= 0;
            alu_op_out      <= 0;
            alu_src_out     <= 0;
            mem_read_out    <= 0;
            mem_write_out   <= 0;
            reg_write_out   <= 0;
            wb_sel_out      <= 0;
            branch_out      <= 0;
            jump_out        <= 0;
            jalr_out        <= 0;
            auipc_out       <= 0;
            lui_out         <= 0;
        end else begin
            // TODO: latch all inputs to outputs
            pc_out          <= pc_in;
            rs1_data_out    <= rs1_data_in;
            rs2_data_out    <= rs2_data_in;
            imm_out         <= imm_in;
            rs1_out         <= rs1_in;
            rs2_out         <= rs2_in;
            rd_out          <= rd_in;
            alu_op_out      <= alu_op_in;
            alu_src_out     <= alu_src_in;
            mem_read_out    <= mem_read_in;
            mem_write_out   <= mem_write_in;
            reg_write_out   <= reg_write_in;
            wb_sel_out      <= wb_sel_in;
            branch_out      <= branch_in;
            jump_out        <= jump_in;
            jalr_out        <= jalr_in;
            auipc_out       <= auipc_in;
            lui_out         <= lui_in;
        end
    end

endmodule
