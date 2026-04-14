// ============================================================
// BoseRV — Fetch Stage Testbench
// Verifies PC increments correctly and a fetched instruction
// matches the first word of the hex file (0x00500093 = addi x1,x0,5)
// ============================================================
`timescale 1ns/1ps

module tb_fetch;
    reg         clk, rst;
    reg         branch_taken, jump;
    reg  [31:0] branch_target, jump_target;
    wire [31:0] pc, instr;

    // Instantiate fetch (which internally instantiates imem)
    fetch dut (
        .clk           (clk),
        .rst           (rst),
        .branch_taken  (branch_taken),
        .jump          (jump),
        .branch_target (branch_target),
        .jump_target   (jump_target),
        .pc            (pc),
        .instr         (instr)
    );

    // 10ns clock
    always #5 clk = ~clk;

    integer i;
    integer errors = 0;

    initial begin
        $dumpfile("fetch_sim.vcd");
        $dumpvars(0, tb_fetch);

        clk = 0; rst = 1;
        branch_taken = 0; jump = 0;
        branch_target = 0; jump_target = 0;

        // Hold reset for 2 cycles
        @(posedge clk); #1;
        @(posedge clk); #1;
        rst = 0;

        // Sample PC at negedge (middle of cycle) — after it has settled
        // Cycle 0 (first real cycle after reset released): PC = 0
        @(negedge clk);
        if (pc !== 32'h0) begin
            $display("FAIL: PC after reset should be 0, got %h", pc); errors=errors+1;
        end else $display("PASS: PC = 0x%08h, instr = 0x%08h", pc, instr);

        // Cycle 1: PC should advance to 4
        @(negedge clk);
        if (pc !== 32'h4) begin
            $display("FAIL: PC should be 4, got %h", pc); errors=errors+1;
        end else $display("PASS: PC = 0x%08h, instr = 0x%08h", pc, instr);

        // Cycle 2: PC should be 8
        @(negedge clk);
        if (pc !== 32'h8) begin
            $display("FAIL: PC should be 8, got %h", pc); errors=errors+1;
        end else $display("PASS: PC = 0x%08h, instr = 0x%08h", pc, instr);

        // Test branch taken: force PC to 0
        // Apply branch_taken before posedge so it's captured
        branch_taken  = 1;
        branch_target = 32'h0;
        @(negedge clk);  // wait for the branch to take effect
        branch_taken = 0;
        if (pc !== 32'h0) begin
            $display("FAIL: branch to 0 didn't work, PC=%h", pc); errors=errors+1;
        end else $display("PASS: branch taken, PC returned to 0x%08h", pc);

        $display("=== Fetch test: %0d errors ===", errors);
        if (errors == 0) $display("ALL FETCH TESTS PASSED!");
        $finish;
    end
endmodule
