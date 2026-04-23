// ============================================================
// BoseRV — MEM/WB Pipeline Register Testbench (Assignment C3)
// Run: verilator --binary --timing -Wall --top-module tb_mem_wb sim/tb_mem_wb.v src/mem_wb.v && ./obj_dir/Vtb_mem_wb
// ============================================================
`timescale 1ns/1ps

module tb_mem_wb;
    reg clk, rst;

    // Inputs
    reg [31:0] alu_result_in, mem_read_data_in, pc_plus4_in;
    reg [4:0]  rd_in;
    reg        reg_write_in;
    reg [1:0]  wb_sel_in;

    // Outputs
    wire [31:0] alu_result_out, mem_read_data_out, pc_plus4_out;
    wire [4:0]  rd_out;
    wire        reg_write_out;
    wire [1:0]  wb_sel_out;

    integer errors = 0;

    mem_wb dut (
        .clk(clk), .rst(rst),
        .alu_result_in(alu_result_in), .mem_read_data_in(mem_read_data_in),
        .pc_plus4_in(pc_plus4_in), .rd_in(rd_in),
        .reg_write_in(reg_write_in), .wb_sel_in(wb_sel_in),
        .alu_result_out(alu_result_out), .mem_read_data_out(mem_read_data_out),
        .pc_plus4_out(pc_plus4_out), .rd_out(rd_out),
        .reg_write_out(reg_write_out), .wb_sel_out(wb_sel_out)
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
        alu_result_in = 32'hFFFF_FFFF; mem_read_data_in = 32'hDEAD_BEEF;
        pc_plus4_in = 32'hAAAA_AAAA; rd_in = 5'h1F;
        reg_write_in = 1'b1; wb_sel_in = 2'b11;
        #12;

        // --- Test 1-3: Reset zeroes all outputs ---
        check32(alu_result_out,    32'h0, 1, "alu_result reset");
        check32(mem_read_data_out, 32'h0, 2, "mem_read_data reset");
        check1(reg_write_out,      1'b0,  3, "reg_write reset=0");

        // --- Test 4-9: R-type: wb_sel=00 (ALU result to rd) ---
        rst = 0;
        alu_result_in    = 32'h0000_0042; // result of ADD
        mem_read_data_in = 32'hDEAD_0000; // irrelevant for R-type
        pc_plus4_in      = 32'h0000_000C;
        rd_in            = 5'd15;
        reg_write_in     = 1'b1;
        wb_sel_in        = 2'b00; // select ALU result
        @(posedge clk); #1;

        check32(alu_result_out,    32'h42,        4, "alu_result latch R-type");
        check32(mem_read_data_out, 32'hDEAD_0000, 5, "mem_read_data passthru");
        check32(pc_plus4_out,      32'hC,         6, "pc_plus4 latch");
        check32({27'b0,rd_out},    32'd15,        7, "rd latch");
        check1(reg_write_out,      1'b1,          8, "reg_write latch");
        check32({30'b0,wb_sel_out},32'h0,         9, "wb_sel=00 ALU");

        // --- Test 10-12: Load (LW): wb_sel=01 (mem data to rd) ---
        alu_result_in    = 32'h0000_0200; // address used in MEM stage, not needed here
        mem_read_data_in = 32'hCAFE_BABE; // value read from dmem
        rd_in            = 5'd20;
        reg_write_in     = 1'b1;
        wb_sel_in        = 2'b01; // select mem read data
        @(posedge clk); #1;

        check32(mem_read_data_out, 32'hCAFE_BABE, 10, "mem_read_data latch LW");
        check32({27'b0,rd_out},    32'd20,        11, "rd latch LW");
        check32({30'b0,wb_sel_out},32'h1,         12, "wb_sel=01 mem");

        // --- Test 13-15: JAL/JALR: wb_sel=10 (PC+4 = return addr to rd) ---
        pc_plus4_in  = 32'h0000_0084; // return address
        rd_in        = 5'd1;           // ra
        reg_write_in = 1'b1;
        wb_sel_in    = 2'b10;
        @(posedge clk); #1;

        check32(pc_plus4_out,      32'h84, 13, "pc_plus4 latch JAL");
        check32({27'b0,rd_out},    32'd1,  14, "rd=ra latch JAL");
        check32({30'b0,wb_sel_out},32'h2,  15, "wb_sel=10 PC+4");

        // --- Test 16-17: No write (store/branch): reg_write=0 ---
        reg_write_in = 1'b0; wb_sel_in = 2'b00;
        @(posedge clk); #1;
        check1(reg_write_out, 1'b0, 16, "reg_write=0 for store");

        // --- Test 17: Async reset mid-pipeline ---
        rst = 1; #3;
        check1(reg_write_out, 1'b0, 17, "reg_write async rst");
        check32(alu_result_out, 32'h0, 18, "alu_result async rst");

        $display("=== MEM/WB: %0d error(s) ===", errors);
        $finish;
    end
endmodule
