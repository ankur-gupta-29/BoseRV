// ============================================================
// BoseRV — IF/ID Pipeline Register Testbench (Assignment C1)
// Run: verilator --binary --timing -Wall --top-module tb_if_id sim/tb_if_id.v src/if_id.v && ./obj_dir/Vtb_if_id
// ============================================================
`timescale 1ns/1ps

module tb_if_id;
    reg        clk, rst;
    reg [31:0] pc_in, instr_in;
    wire [31:0] pc_out, instr_out;

    integer errors = 0;

    if_id dut (
        .clk(clk), .rst(rst),
        .pc_in(pc_in), .instr_in(instr_in),
        .pc_out(pc_out), .instr_out(instr_out)
    );

    always #5 clk = ~clk;

    task check32;
        input [31:0] got, expected;
        input [63:0] id;
        input [127:0] name;
        begin
            if (got !== expected) begin
                $display("FAIL test %0d (%s): got %h, expected %h", id, name, got, expected);
                errors = errors + 1;
            end else
                $display("PASS test %0d (%s): %h", id, name, got);
        end
    endtask

    initial begin
        clk = 0; rst = 1; pc_in = 32'hDEADBEEF; instr_in = 32'hCAFEBABE;
        #12;

        // --- Test 1: Reset zeroes both outputs ---
        check32(pc_out,    32'h0, 1, "pc_out reset");
        check32(instr_out, 32'h0, 2, "instr_out reset");

        // --- Test 2: Deassert reset, apply inputs, check after posedge ---
        rst = 0;
        pc_in = 32'h0000_0004; instr_in = 32'h0000_0013; // NOP (ADDI x0,x0,0)
        @(posedge clk); #1;
        check32(pc_out,    32'h0000_0004, 3, "pc_out latch");
        check32(instr_out, 32'h0000_0013, 4, "instr_out latch");

        // --- Test 3: Second clock advances to next instruction ---
        pc_in = 32'h0000_0008; instr_in = 32'hFFC4_A503; // LW x10,−4(x9)
        @(posedge clk); #1;
        check32(pc_out,    32'h0000_0008, 5, "pc_out latch2");
        check32(instr_out, 32'hFFC4_A503, 6, "instr_out latch2");

        // --- Test 4: Reassert reset mid-stream clears outputs ---
        rst = 1; #3;
        check32(pc_out,    32'h0, 7, "pc_out async rst");
        check32(instr_out, 32'h0, 8, "instr_out async rst");

        // --- Test 5: After rst deassert, previous pc_in/instr_in not spuriously latched ---
        rst = 0;
        pc_in = 32'h1234_5678; instr_in = 32'hABCD_EF01;
        // no clock yet — outputs should still be 0
        #1;
        check32(pc_out,    32'h0, 9,  "pc_out stable before clk");
        check32(instr_out, 32'h0, 10, "instr_out stable before clk");
        @(posedge clk); #1;
        check32(pc_out,    32'h1234_5678, 11, "pc_out latch after rst");
        check32(instr_out, 32'hABCD_EF01, 12, "instr_out latch after rst");

        $display("=== IF/ID: %0d error(s) ===", errors);
        $finish;
    end
endmodule
