// ============================================================
// BoseRV — ID/EX Pipeline Register Testbench (Assignment C2)
// Run: verilator --binary --timing -Wall --top-module tb_id_ex sim/tb_id_ex.v src/id_ex.v && ./obj_dir/Vtb_id_ex
// ============================================================
`timescale 1ns/1ps

module tb_id_ex;
    reg clk, rst;

    // Data inputs
    reg [31:0] pc_in, rs1_data_in, rs2_data_in, imm_in;
    reg [4:0]  rs1_in, rs2_in, rd_in;

    // Control inputs
    reg [3:0]  alu_op_in;
    reg        alu_src_in, mem_read_in, mem_write_in, reg_write_in;
    reg [1:0]  wb_sel_in;
    reg        branch_in, jump_in, jalr_in, auipc_in, lui_in;

    // Outputs
    wire [31:0] pc_out, rs1_data_out, rs2_data_out, imm_out;
    wire [4:0]  rs1_out, rs2_out, rd_out;
    wire [3:0]  alu_op_out;
    wire        alu_src_out, mem_read_out, mem_write_out, reg_write_out;
    wire [1:0]  wb_sel_out;
    wire        branch_out, jump_out, jalr_out, auipc_out, lui_out;

    integer errors = 0;

    id_ex dut (
        .clk(clk), .rst(rst),
        .pc_in(pc_in), .rs1_data_in(rs1_data_in), .rs2_data_in(rs2_data_in), .imm_in(imm_in),
        .rs1_in(rs1_in), .rs2_in(rs2_in), .rd_in(rd_in),
        .alu_op_in(alu_op_in), .alu_src_in(alu_src_in),
        .mem_read_in(mem_read_in), .mem_write_in(mem_write_in), .reg_write_in(reg_write_in),
        .wb_sel_in(wb_sel_in), .branch_in(branch_in), .jump_in(jump_in),
        .jalr_in(jalr_in), .auipc_in(auipc_in), .lui_in(lui_in),
        .pc_out(pc_out), .rs1_data_out(rs1_data_out), .rs2_data_out(rs2_data_out), .imm_out(imm_out),
        .rs1_out(rs1_out), .rs2_out(rs2_out), .rd_out(rd_out),
        .alu_op_out(alu_op_out), .alu_src_out(alu_src_out),
        .mem_read_out(mem_read_out), .mem_write_out(mem_write_out), .reg_write_out(reg_write_out),
        .wb_sel_out(wb_sel_out), .branch_out(branch_out), .jump_out(jump_out),
        .jalr_out(jalr_out), .auipc_out(auipc_out), .lui_out(lui_out)
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

    // Drive all inputs to a known non-zero pattern
    task drive_pattern;
        begin
            pc_in       = 32'hDEAD_0004;
            rs1_data_in = 32'hAAAA_AAAA;
            rs2_data_in = 32'h5555_5555;
            imm_in      = 32'hFFFF_FFF0;
            rs1_in      = 5'd10; rs2_in = 5'd11; rd_in = 5'd12;
            alu_op_in   = 4'b1010;
            alu_src_in  = 1'b1; mem_read_in  = 1'b1; mem_write_in = 1'b0;
            reg_write_in= 1'b1; wb_sel_in    = 2'b01;
            branch_in   = 1'b0; jump_in = 1'b1; jalr_in = 1'b1;
            auipc_in    = 1'b0; lui_in  = 1'b0;
        end
    endtask

    initial begin
        clk = 0; rst = 1;
        // Garbage inputs during reset
        pc_in = 32'hFFFF_FFFF; rs1_data_in = 32'hFFFF_FFFF;
        rs2_data_in = 32'hFFFF_FFFF; imm_in = 32'hFFFF_FFFF;
        rs1_in = 5'h1F; rs2_in = 5'h1F; rd_in = 5'h1F;
        alu_op_in = 4'hF; alu_src_in=1; mem_read_in=1; mem_write_in=1;
        reg_write_in=1; wb_sel_in=2'b11; branch_in=1; jump_in=1;
        jalr_in=1; auipc_in=1; lui_in=1;
        #12;

        // --- Test 1-4: All outputs zero on reset (critical: no ghost writes) ---
        check32(pc_out,       32'h0, 1,  "pc_out reset");
        check32(rs1_data_out, 32'h0, 2,  "rs1_data reset");
        check1(mem_write_out,  1'b0, 3,  "mem_write reset=0");
        check1(reg_write_out,  1'b0, 4,  "reg_write reset=0");

        // --- Test 5-18: Latch on clock edge ---
        rst = 0;
        drive_pattern;
        @(posedge clk); #1;

        check32(pc_out,       32'hDEAD_0004, 5,  "pc latch");
        check32(rs1_data_out, 32'hAAAA_AAAA, 6,  "rs1_data latch");
        check32(rs2_data_out, 32'h5555_5555, 7,  "rs2_data latch");
        check32(imm_out,      32'hFFFF_FFF0, 8,  "imm latch");
        check32({27'b0,rd_out},  32'd12,     9,  "rd latch");
        check32({28'b0,alu_op_out}, 32'h0000_000A, 10, "alu_op latch");
        check1(alu_src_out,   1'b1, 11, "alu_src latch");
        check1(mem_read_out,  1'b1, 12, "mem_read latch");
        check1(mem_write_out, 1'b0, 13, "mem_write latch");
        check1(reg_write_out, 1'b1, 14, "reg_write latch");
        check32({30'b0,wb_sel_out}, 32'h1, 15, "wb_sel latch");
        check1(jump_out,  1'b1, 16, "jump latch");
        check1(jalr_out,  1'b1, 17, "jalr latch");
        check32({27'b0,rs1_out}, 32'd10, 18, "rs1 addr latch");
        check32({27'b0,rs2_out}, 32'd11, 19, "rs2 addr latch");

        // --- Test 20: Async reset clears mid-pipeline ---
        rst = 1; #3;
        check1(reg_write_out, 1'b0, 20, "reg_write async rst");
        check1(mem_write_out, 1'b0, 21, "mem_write async rst");
        check32(pc_out, 32'h0,      22, "pc async rst");

        $display("=== ID/EX: %0d error(s) ===", errors);
        $finish;
    end
endmodule
