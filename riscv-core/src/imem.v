module imem (
input [31:0] addr;
output [31:0] rd;
);

reg [31:0] mem [0:255];

initial begin
  $readmemh("tests/instr_mem.hex",memory);
end

assign instr = mem[addr[31:2]];

endmodule;

