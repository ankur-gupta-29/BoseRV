// ============================================================
// BoseRV — EX/MEM Pipeline Register Testbench (Assignment C3)
// Run: verilator --binary --timing -Wall --top-module tb_ex_mem sim/tb_ex_mem.v src/ex_mem.v && ./obj_dir/Vtb_ex_mem
// ============================================================
`timescale 1ns/1ps

module tb_ex_mem;
    reg clk, rst;

    // Inputs
    reg [31:0] alu_result_in, rs2_data_in, pc_plus4_in;
    reg [31:0] branch_target_in, jump_target_in;
    reg        branch_taken_in, alu_zero_in;
    reg [4:0]  rd_in;
    reg        mem_read_in, mem_write_in, reg_write_in;
    reg [1:0]  wb_sel_in;
    reg        jump_in;

    // Outputs
    wire [31:0] alu_result_out, rs2_data_out, pc_plus4_out;
    wire [31:0] branch_target_out, jump_target_out;
    wire        branch_taken_out, alu_zero_out;
    wire [4:0]  rd_out;
    wire        mem_read_out, mem_write_out, reg_write_out;
    wire [1:0]  wb_sel_out;
    wire        jump_out;

    integer errors = 0;

    ex_mem dut (
        .clk(clk), .rst(rst),
        .alu_result_in(alu_result_in), .rs2_data_in(rs2_data_in),
        .pc_plus4_in(pc_plus4_in), .branch_target_in(branch_target_in),
        .jump_target_in(jump_target_in), .branch_taken_in(branch_taken_in),
        .alu_zero_in(alu_zero_in), .rd_in(rd_in),
        .mem_read_in(mem_read_in), .mem_write_in(mem_write_in),
        .reg_write_in(reg_write_in), .wb_sel_in(wb_sel_in), .jump_in(jump_in),
        .alu_result_out(alu_result_out), .rs2_data_out(rs2_data_out),
        .pc_plus4_out(pc_plus4_out), .branch_target_out(branch_target_out),
        .jump_target_out(jump_target_out), .branch_taken_out(branch_taken_out),
        .alu_zero_out(alu_zero_out), .rd_out(rd_out),
        .mem_read_out(mem_read_out), .mem_write_out(mem_write_out),
        .reg_write_out(reg_write_out), .wb_sel_out(wb_sel_out), .jump_out(jump_out)
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

    task check1;
        input got, expected;
        input [63:0] id;
        input [127:0] name;
        begin
            if (got !== expected) begin
                $display("FAIL test %0d (%s): got %b, expected %b", id, name, got, expected);
                errors = errors + 1;
            end else
                $display("PASS test %0d (%s): %b", id, name, got);
        end
    endtask

    initial begin
        clk = 0; rst = 1;
        // Garbage during reset — critical that mem_write_out does NOT become 1
        alu_result_in = 32'hDEAD_BEEF; rs2_data_in = 32'hCAFE_BABE;
        pc_plus4_in = 32'hFFFF_FFFF; branch_target_in = 32'hABCD_1234;
        jump_target_in = 32'h1234_ABCD; branch_taken_in = 1; alu_zero_in = 1;
        rd_in = 5'h1F; mem_read_in = 1; mem_write_in = 1;
        reg_write_in = 1; wb_sel_in = 2'b11; jump_in = 1;
        #12;

        // --- Test 1-4: Reset zeroes all — especially mem_write (ghost store prevention) ---
        check1(mem_write_out,  1'b0,  1, "mem_write reset=0 CRITICAL");
        check1(reg_write_out,  1'b0,  2, "reg_write reset=0");
        check1(branch_taken_out, 1'b0, 3, "branch_taken reset=0");
        check32(alu_result_out, 32'h0, 4, "alu_result reset");

        // --- Test 5-17: Latch normal ALU/store instruction ---
        rst = 0;
        alu_result_in   = 32'h0000_0100; // computed address
        rs2_data_in     = 32'hDEAD_BEEF; // store data (SW)
        pc_plus4_in     = 32'h0000_0008;
        branch_target_in= 32'h0000_0020;
        jump_target_in  = 32'h0000_0040;
        branch_taken_in = 1'b0;
        alu_zero_in     = 1'b0;
        rd_in           = 5'd5;
        mem_read_in     = 1'b0; mem_write_in = 1'b1;
        reg_write_in    = 1'b0; wb_sel_in = 2'b00; jump_in = 1'b0;
        @(posedge clk); #1;

        check32(alu_result_out,    32'h0000_0100, 5,  "alu_result latch");
        check32(rs2_data_out,      32'hDEAD_BEEF, 6,  "rs2_data latch");
        check32(pc_plus4_out,      32'h0000_0008, 7,  "pc_plus4 latch");
        check32(branch_target_out, 32'h0000_0020, 8,  "branch_target latch");
        check32(jump_target_out,   32'h0000_0040, 9,  "jump_target latch");
        check1(branch_taken_out,   1'b0,          10, "branch_taken latch");
        check1(mem_write_out,      1'b1,          11, "mem_write latch");
        check1(reg_write_out,      1'b0,          12, "reg_write latch");
        check32({27'b0,rd_out},    32'd5,         13, "rd latch");

        // --- Test 14-16: Branch taken path ---
        alu_result_in = 32'h0; branch_taken_in = 1'b1; alu_zero_in = 1'b1;
        mem_write_in = 1'b0; reg_write_in = 1'b0;
        @(posedge clk); #1;
        check1(branch_taken_out, 1'b1, 14, "branch_taken latch");
        check1(alu_zero_out,     1'b1, 15, "alu_zero latch");
        check1(mem_write_out,    1'b0, 16, "mem_write=0 for branch");

        // --- Test 17-19: JAL path (jump, wb_sel=PC+4) ---
        reg_write_in = 1'b1; jump_in = 1'b1; wb_sel_in = 2'b10;
        pc_plus4_in = 32'h0000_0084; rd_in = 5'd1; // ra
        branch_taken_in = 1'b0;
        @(posedge clk); #1;
        check1(jump_out,             1'b1,       17, "jump latch");
        check32({30'b0,wb_sel_out},  32'h2,      18, "wb_sel=PC+4");
        check32(pc_plus4_out,        32'h84,     19, "pc_plus4 latch JAL");

        // --- Test 20: Async reset during pipeline clears mem_write ---
        rst = 1; #3;
        check1(mem_write_out, 1'b0, 20, "mem_write async rst");
        check1(reg_write_out, 1'b0, 21, "reg_write async rst");

        $display("=== EX/MEM: %0d error(s) ===", errors);
        $finish;
    end
endmodule
