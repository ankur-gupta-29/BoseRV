`timescale 1ns / 1ps


module tb_fetch();
reg clk;
reg rst;
reg [31:0] pc_next;
wire [31:0] pc;
wire [31:0] instr;

fetch fetch_inst(
    .clk(clk),
    .rst(rst),
    .pc_next(pc_next),
    .pc(pc),
    .instr(instr)
);

initial begin
    clk = 0;
    /* verilator lint_off STMTDLY */
    /* verilator lint_off INFINITELOOP */
    forever #5 clk = ~clk; // 10 time units clock period
    /* verilator lint_on INFINITELOOP */
    /* verilator lint_on STMTDLY */
end 

/* verilator lint_off STMTDLY */
initial begin
    rst = 1;
    pc_next = 32'b0;
    #10
    rst = 0;
    #10
    repeat (6) begin
        pc_next = pc + 4;
        #10
        $display("%0t\t%h\t%h\taddi x1,x0,%0d", $time, pc, instr, $signed(instr[31:20]));
    end
     #10 $finish;

end
/* verilator lint_on STMTDLY */

initial begin
    $dumpfile("tb_fetch.vcd");
    $dumpvars(0, tb_fetch); 
end



endmodule
