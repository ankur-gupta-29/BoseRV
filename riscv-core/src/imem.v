`timescale 1ns / 1ps
`timescale 1ns / 1ps
/* verilator lint_off UNUSED */
module imem(
    input [31:0] addr,
    output [31:0] instr
);

reg [31:0] memory [0:255];
initial begin
 $readmemh("tests/instr_mem.hex", memory);
end

assign instr = memory[addr[9:2]]; // Assuming word-aligned addresses

endmodule
/* verilator lint_on UNUSED */
