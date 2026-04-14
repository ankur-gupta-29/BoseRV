// ============================================================
// BoseRV — Instruction Memory
// Single-port ROM, word-addressed
// ============================================================
module imem (
    input  [31:0] addr,
    output [31:0] instr
);

    reg [31:0] mem [0:255];   // 256 words = 1KB

    initial begin
        $readmemh("tests/instr_mem.hex", mem);
    end

    // Word-addressed: drop bottom 2 bits
    assign instr = mem[addr[9:2]];

endmodule
