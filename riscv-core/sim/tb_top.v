// ============================================================
// BoseRV — Full Core Testbench (Single-Cycle)
// 
// Test program (in tests/instr_mem.hex):
//   ADDI x1, x0, 5        // x1 = 5
//   ADDI x2, x0, 20       // x2 = 20
//   ADD  x3, x1, x2       // x3 = 25
//   ADDI x4, x0, 100      // x4 = 100 (base addr)
//   SW   x3, 0(x4)        // mem[100] = 25
//   LW   x5, 0(x4)        // x5 = mem[100] = 25
//   BEQ  x3, x5, +12      // should branch (skip next 2 instr)
//   ADDI x6, x0, 0xFF     // should be SKIPPED
//   ADDI x7, x0, 0xFF     // should be SKIPPED  
//   ADDI x8, x0, 0xAA     // x8 = 0xAA (branch lands here)
// ============================================================
`timescale 1ns/1ps

module tb_top;
    reg clk, rst;

    top dut (.clk(clk), .rst(rst));

    // Access internals for checking
    // (needs to match hierarchy in top.v)
    wire [31:0] pc     = dut.pc;
    wire [31:0] instr  = dut.instr;
    wire [4:0]  rd     = dut.rd_addr;
    wire [31:0] wdata  = dut.wb_data;
    wire        we     = dut.reg_write;

    always #5 clk = ~clk;

    integer cycle;
    integer errors = 0;

    initial begin
        $dumpfile("top_sim.vcd");
        $dumpvars(0, tb_top);

        clk = 0; rst = 1; cycle = 0;

        @(posedge clk); #1;
        @(posedge clk); #1;
        rst = 0;

        // Run for 20 cycles, print each state
        repeat(20) begin
            @(posedge clk); #1;
            cycle = cycle + 1;
            $display("Cycle %2d: PC=0x%08h INSTR=0x%08h | rd=x%0d wdata=0x%08h we=%b",
                      cycle, pc, instr, rd, wdata, we);
        end

        // Check register values via hierarchical access
        $display("\n=== Register File Contents ===");
        $display("x1 = %0d (expected  5)", dut.u_regfile.regs[1]);
        $display("x2 = %0d (expected 20)", dut.u_regfile.regs[2]);
        $display("x3 = %0d (expected 25)", dut.u_regfile.regs[3]);
        $display("x5 = %0d (expected 25)", dut.u_regfile.regs[5]);
        $display("x6 = %0d (expected  0, branch skipped)", dut.u_regfile.regs[6]);
        $display("x7 = %0d (expected  0, branch skipped)", dut.u_regfile.regs[7]);

        // Automated checks
        if (dut.u_regfile.regs[1] !== 32'd5)  begin $display("FAIL: x1"); errors=errors+1; end
        if (dut.u_regfile.regs[2] !== 32'd20) begin $display("FAIL: x2"); errors=errors+1; end
        if (dut.u_regfile.regs[3] !== 32'd25) begin $display("FAIL: x3"); errors=errors+1; end
        if (dut.u_regfile.regs[5] !== 32'd25) begin $display("FAIL: x5"); errors=errors+1; end
        if (dut.u_regfile.regs[6] !== 32'd0)  begin $display("FAIL: x6 (branch not taken!)"); errors=errors+1; end
        if (dut.u_regfile.regs[7] !== 32'd0)  begin $display("FAIL: x7 (branch not taken!)"); errors=errors+1; end

        $display("\n=== Result: %0d errors ===", errors);
        if (errors == 0) $display("BoseRV SINGLE-CYCLE CORE: ALL TESTS PASSED!");
        else             $display("BoseRV SINGLE-CYCLE CORE: FAILURES DETECTED");
        $finish;
    end
endmodule
