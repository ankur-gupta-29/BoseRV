// ============================================================
// BoseRV — Instruction Memory (ROM)
// Single-port, read-only, word-addressed.
// Loaded from a hex file at simulation start.
// ============================================================
module imem (
    input  [31:0] addr,   // byte address from PC
    output [31:0] instr   // 32-bit instruction word
);

    reg [31:0] mem [0:255]; // 256 words = 1 KB of instruction space

    initial begin
        // $readmemh loads a Verilog hex file; each line = one 32-bit word.
        // Path is relative to the simulation working directory (riscv-core/).
        $readmemh("tests/instr_mem.hex", mem);
    end

    // addr[9:2] converts byte address → word index:
    //   drop addr[1:0] (instructions are 4-byte aligned, low 2 bits always 0)
    //   keep addr[9:2] (8 bits → index 0-255)
    assign instr = mem[addr[9:2]];

endmodule
