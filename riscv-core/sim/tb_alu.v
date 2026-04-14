// ============================================================
// BoseRV — ALU Testbench
// Tests all 10 ALU operations with known inputs/expected outputs
// Run: iverilog -o sim_alu sim/tb_alu.v src/alu.v && ./sim_alu
// ============================================================
`timescale 1ns/1ps

module tb_alu;
    reg  [31:0] a, b;
    reg  [3:0]  op;
    wire [31:0] result;
    wire        zero;

    integer errors = 0;

    alu dut (.a(a), .b(b), .op(op), .result(result), .zero(zero));

    // Helper task to check one result
    task check;
        input [31:0] expected;
        input [63:0] test_id;
        begin
            if (result !== expected) begin
                $display("FAIL test %0d: op=%b a=%h b=%h => got %h, expected %h",
                          test_id, op, a, b, result, expected);
                errors = errors + 1;
            end else begin
                $display("PASS test %0d: op=%b a=%h b=%h => %h", test_id, op, a, b, result);
            end
        end
    endtask

    initial begin
        $display("=== BoseRV ALU Test ===");

        // --- ADD ---
        a = 32'd5;  b = 32'd20; op = 4'b0000; #10; check(32'd25, 1);
        a = 32'hFFFFFFFF; b = 32'd1; op = 4'b0000; #10; check(32'd0, 2); // overflow wraps

        // --- SUB ---
        a = 32'd20; b = 32'd5;  op = 4'b0001; #10; check(32'd15, 3);
        a = 32'd5;  b = 32'd10; op = 4'b0001; #10; check(32'hFFFFFFFB, 4); // negative result

        // --- AND ---
        a = 32'hFF00FF00; b = 32'hF0F0F0F0; op = 4'b0010; #10; check(32'hF000F000, 5);

        // --- OR ---
        a = 32'hFF00FF00; b = 32'h00FF00FF; op = 4'b0011; #10; check(32'hFFFFFFFF, 6);

        // --- XOR ---
        a = 32'hAAAAAAAA; b = 32'h55555555; op = 4'b0100; #10; check(32'hFFFFFFFF, 7);
        a = 32'hAAAAAAAA; b = 32'hAAAAAAAA; op = 4'b0100; #10; check(32'h0,         8);

        // --- SLL ---
        a = 32'h1;  b = 32'd4;  op = 4'b0101; #10; check(32'h10, 9);
        a = 32'h1;  b = 32'd31; op = 4'b0101; #10; check(32'h80000000, 10);

        // --- SRL ---
        a = 32'h80000000; b = 32'd1;  op = 4'b0110; #10; check(32'h40000000, 11);
        a = 32'hFFFFFFFF; b = 32'd4;  op = 4'b0110; #10; check(32'h0FFFFFFF, 12);

        // --- SRA (arithmetic, sign extends) ---
        a = 32'h80000000; b = 32'd1;  op = 4'b0111; #10; check(32'hC0000000, 13);
        a = 32'hFFFFFFFF; b = 32'd4;  op = 4'b0111; #10; check(32'hFFFFFFFF, 14);

        // --- SLT (signed) ---
        a = 32'hFFFFFFFF; b = 32'd1;  op = 4'b1000; #10; check(32'd1, 15); // -1 < 1
        a = 32'd10;       b = 32'd5;  op = 4'b1000; #10; check(32'd0, 16); // 10 is not < 5

        // --- SLTU (unsigned) ---
        a = 32'hFFFFFFFF; b = 32'd1;  op = 4'b1001; #10; check(32'd0, 17); // 0xFFFFFFFF > 1
        a = 32'd1;        b = 32'hFFFFFFFF; op = 4'b1001; #10; check(32'd1, 18); // 1 < big

        // --- Zero flag ---
        a = 32'd5; b = 32'd5; op = 4'b0001; #10; // SUB: 5-5 = 0
        if (zero !== 1'b1) begin
            $display("FAIL test 19: zero flag should be 1 when result=0"); errors=errors+1;
        end else $display("PASS test 19: zero flag correct");

        a = 32'd5; b = 32'd3; op = 4'b0001; #10; // SUB: 5-3 = 2 ≠ 0
        if (zero !== 1'b0) begin
            $display("FAIL test 20: zero flag should be 0 when result!=0"); errors=errors+1;
        end else $display("PASS test 20: zero flag correct");

        $display("=== Results: %0d errors ===", errors);
        if (errors == 0) $display("ALL TESTS PASSED!");
        $finish;
    end
endmodule
