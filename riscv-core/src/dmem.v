// ============================================================
// BoseRV — Data Memory (RAM)
// Synchronous write, asynchronous read, word-addressed.
// ============================================================
module dmem (
    input         clk,
    input         we,       // write enable (mem_write from decoder)
    input  [31:0] addr,     // byte address (ALU result = rs1 + imm)
    input  [31:0] wd,       // write data   (rs2 value for SW)
    output [31:0] rd        // read data    (goes to writeback MUX for LW)
);

    reg [31:0] mem [0:255]; // 256 words = 1 KB of data space

    // Synchronous write: data is stored on the rising clock edge.
    // SW takes one full cycle — the value is visible on the NEXT cycle's read.
    always @(posedge clk) begin
        if (we)
            mem[addr[9:2]] <= wd;
    end

    // Asynchronous read: LW result is available combinationally in the same cycle.
    // addr[9:2]: same word-address trick as imem (drop 2 LSBs, keep 8 index bits).
    assign rd = mem[addr[9:2]];

endmodule
