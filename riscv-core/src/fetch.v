`timescale 1ns / 1ps

module fetch (
input  clk,
input  rst,
input [31:0] pc_next,
output [31:0] pc,
output  [31:0]  instr);

reg [31:0] pc_reg;
always @(posedge clk or posedge rst) begin
if(rst) 
    pc_reg <= 32'b0;
    else
    pc_reg <= pc_next;
end

 assign pc = pc_reg;

 imem imem_inst(
    .addr(pc_reg),
    .instr(instr)
 );
    

endmodule
