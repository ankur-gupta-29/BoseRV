// ============================================================
// BoseRV — Register File
// 32 x 32-bit registers
// x0 is hardwired to 0 (RISC-V spec)
// Synchronous write, asynchronous reads
// ============================================================
module regfile (
    input         clk,
    input         we,           // write enable
    input  [4:0]  rs1, rs2,    // source register addresses
    input  [4:0]  rd,           // destination register address
    input  [31:0] wdata,        // write data
    output [31:0] rdata1,       // read data port 1
    output [31:0] rdata2        // read data port 2
);

    reg [31:0] regs [0:31];

    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'h0;
    end

    // Synchronous write — x0 is always 0
    always @(posedge clk) begin
        if (we && rd != 5'b0)
            regs[rd] <= wdata;
    end

    // Asynchronous reads — x0 always reads 0
    assign rdata1 = (rs1 == 5'b0) ? 32'h0 : regs[rs1];
    assign rdata2 = (rs2 == 5'b0) ? 32'h0 : regs[rs2];

endmodule
