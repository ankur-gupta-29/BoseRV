// ============================================================
// BoseRV — Data Memory
// Synchronous write, asynchronous read, word-addressed
// ============================================================
module dmem (
    input         clk,
    input         we,
    input  [31:0] addr,
    input  [31:0] wd,
    output [31:0] rd
);

    reg [31:0] mem [0:255];   // 256 words = 1KB

    // Synchronous write
    always @(posedge clk) begin
        if (we)
            mem[addr[9:2]] <= wd;
    end

    // Asynchronous read
    assign rd = mem[addr[9:2]];

endmodule
