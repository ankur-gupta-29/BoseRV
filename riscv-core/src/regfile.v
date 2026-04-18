// ============================================================
// BoseRV — Register File
// 32 × 32-bit general-purpose registers (x0–x31)
//
// Design choices:
//   • Synchronous write  — data appears in rd one cycle after we rises
//   • Asynchronous read  — rdata1/rdata2 update combinationally with rs1/rs2
//   • x0 is hardwired to 0 per RISC-V spec (reads always 0, writes ignored)
// ============================================================
module regfile (
    input         clk,
    input         we,           // write enable (reg_write from decoder)
    input  [4:0]  rs1, rs2,    // source register addresses
    input  [4:0]  rd,           // destination register address
    input  [31:0] wdata,        // data to write (from writeback MUX in top.v)
    output [31:0] rdata1,       // read port 1 — rs1 value
    output [31:0] rdata2        // read port 2 — rs2 value
);

    reg [31:0] regs [0:31];     // 32 registers × 32 bits

    // Initialize all registers to 0 at simulation start
    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'h0;
    end

    // Synchronous write — guard on rd!=0 enforces x0 hardwiring
    always @(posedge clk) begin
        if (we && rd != 5'b0)
            regs[rd] <= wdata;
    end

    // Asynchronous reads — x0 always returns 0 regardless of what regs[0] holds.
    // Async reads mean the ALU sees the latest register values in the same cycle
    // the instruction is decoded (important for single-cycle correctness).
    assign rdata1 = (rs1 == 5'b0) ? 32'h0 : regs[rs1];
    assign rdata2 = (rs2 == 5'b0) ? 32'h0 : regs[rs2];

endmodule
