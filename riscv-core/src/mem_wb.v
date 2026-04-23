// ============================================================
// BoseRV — MEM/WB Pipeline Register (Assignment C3)
//
// Sits between Memory stage and Writeback stage.
// The Memory stage either reads data memory (LW) or passes
// the ALU result through. This register carries both to WB
// so the writeback MUX can select the correct one.
// ============================================================
module mem_wb (
    input         clk,
    input         rst,

    // ── Data inputs from MEM stage ─────────────────────────
    input  [31:0] alu_result_in,    // ALU result (R-type, I-type, LUI, AUIPC)
    input  [31:0] mem_read_data_in, // data memory read output (LW)
    input  [31:0] pc_plus4_in,      // PC+4 (JAL/JALR return address)
    input  [4:0]  rd_in,            // destination register address

    // ── Control inputs from MEM stage ──────────────────────
    input         reg_write_in,     // 1 = write result to rd
    input  [1:0]  wb_sel_in,        // 00=ALU, 01=mem, 10=PC+4

    // ── Data outputs to WB stage ───────────────────────────
    output reg [31:0] alu_result_out,
    output reg [31:0] mem_read_data_out,
    output reg [31:0] pc_plus4_out,
    output reg [4:0]  rd_out,

    // ── Control outputs to WB stage ────────────────────────
    output reg        reg_write_out,
    output reg [1:0]  wb_sel_out
);

    // TODO (C3 — part 2): Implement the pipeline register.
    //
    // Same pattern as the others:
    //   - On rst:         zero ALL outputs
    //   - On posedge clk: latch every _in to its _out
    //
    // This is the last pipeline register. After WB, the result
    // goes back to the register file (regfile.v — already written!).
    // wb_sel chooses: ALU result / mem read data / PC+4.

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // TODO: zero ALL outputs
            alu_result_out      <= 0;
            mem_read_data_out   <= 0;
            pc_plus4_out        <= 0;
            rd_out              <= 0;
            reg_write_out       <= 0;
            wb_sel_out          <= 0;
        end else begin
            // TODO: latch all inputs to outputs
            alu_result_out      <= alu_result_in;
            mem_read_data_out   <= mem_read_data_in;
            pc_plus4_out        <= pc_plus4_in;
            rd_out              <= rd_in;
            reg_write_out       <= reg_write_in;
            wb_sel_out          <= wb_sel_in;
        end
    end

endmodule
