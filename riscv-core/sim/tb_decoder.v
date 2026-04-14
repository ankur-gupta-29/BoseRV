// ============================================================
// BoseRV — Decoder Testbench
// Tests key instructions (ADDI, ADD, LW, SW, BEQ, LUI)
// ============================================================
`timescale 1ns/1ps

module tb_decoder;
    reg  [31:0] instr;
    
    wire [4:0]  rs1, rs2, rd;
    wire [31:0] imm;
    wire [3:0]  alu_op;
    wire        alu_src;
    wire        mem_read, mem_write;
    wire        reg_write;
    wire [1:0]  wb_sel;
    wire        branch, jump, jalr;

    integer errors = 0;

    decoder dut (
        .instr(instr),
        .rs1(rs1), .rs2(rs2), .rd(rd),
        .imm(imm),
        .alu_op(alu_op), .alu_src(alu_src),
        .mem_read(mem_read), .mem_write(mem_write),
        .reg_write(reg_write), .wb_sel(wb_sel),
        .branch(branch), .jump(jump), .jalr(jalr)
    );

    // Initial block to trace and run tests
    initial begin
        $dumpfile("decoder_sim.vcd");
        $dumpvars(0, tb_decoder);

        $display("=== BoseRV Decoder Test ===");

        // -----------------------------------------------------
        // Test 1: ADDI x1, x2, 5 (I-Type)
        // -----------------------------------------------------
        instr = 32'h00510093; #10;
        $display("Testing ADDI x1, x2, 5...");
        if (rs1 !== 2) begin $display("FAIL: rs1=%0d (expected 2)", rs1); errors++; end
        if (rd !== 1)  begin $display("FAIL: rd=%0d (expected 1)", rd); errors++; end
        if (imm !== 5) begin $display("FAIL: imm=%0d (expected 5). Check your imm_i slicing!", imm); errors++; end
        if (alu_src !== 1) begin $display("FAIL: alu_src=%b (expected 1 for immediate)", alu_src); errors++; end
        if (reg_write !== 1) begin $display("FAIL: reg_write=%b (expected 1, we save result)", reg_write); errors++; end
        if (wb_sel !== 0) begin $display("FAIL: wb_sel=%b (expected 0, ALU result -> reg)", wb_sel); errors++; end

        // -----------------------------------------------------
        // Test 2: ADD x3, x1, x2 (R-Type)
        // -----------------------------------------------------
        instr = 32'h002081b3; #10;
        $display("Testing ADD x3, x1, x2...");
        if (rs1 !== 1) begin $display("FAIL: rs1=%0d (expected 1)", rs1); errors++; end
        if (rs2 !== 2) begin $display("FAIL: rs2=%0d (expected 2)", rs2); errors++; end
        if (rd !== 3)  begin $display("FAIL: rd=%0d (expected 3)", rd); errors++; end
        if (alu_src !== 0) begin $display("FAIL: alu_src=%b (expected 0 for reg-reg)", alu_src); errors++; end
        if (reg_write !== 1) begin $display("FAIL: reg_write=%b (expected 1)", reg_write); errors++; end
        if (wb_sel !== 0) begin $display("FAIL: wb_sel=%b (expected 0, ALU result -> reg)", wb_sel); errors++; end

        // -----------------------------------------------------
        // Test 3: LW x5, -4(x4) (I-Type Load)
        // -----------------------------------------------------
        // 1111_1111_1100 = -4. rd=5, rs1=4. opcode=0000011 (OP_LOAD)
        instr = 32'hffc22283; #10;
        $display("Testing LW x5, -4(x4)...");
        if (rs1 !== 4) begin $display("FAIL: rs1=%0d (expected 4)", rs1); errors++; end
        if (rd !== 5)  begin $display("FAIL: rd=%0d (expected 5)", rd); errors++; end
        if ($signed(imm) !== -4) begin $display("FAIL: imm=%0d (expected -4). Did you sign-extend?", $signed(imm)); errors++; end
        if (mem_read !== 1) begin $display("FAIL: mem_read=%b (expected 1)", mem_read); errors++; end
        if (reg_write !== 1) begin $display("FAIL: reg_write=%b (expected 1)", reg_write); errors++; end
        if (wb_sel !== 1) begin $display("FAIL: wb_sel=%b (expected 1, MEM result -> reg)", wb_sel); errors++; end

        // -----------------------------------------------------
        // Test 4: SW x3, 8(x4) (S-Type Store)
        // -----------------------------------------------------
        // imm=8, rs1=4, rs2=3. opcode=0100011 (OP_STORE)
        instr = 32'h00322423; #10;
        $display("Testing SW x3, 8(x4)...");
        if (rs1 !== 4) begin $display("FAIL: rs1=%0d (expected 4)", rs1); errors++; end
        if (rs2 !== 3) begin $display("FAIL: rs2=%0d (expected 3)", rs2); errors++; end
        if (imm !== 8) begin $display("FAIL: imm=%0d (expected 8). Check your imm_s slicing!", imm); errors++; end
        if (mem_write !== 1) begin $display("FAIL: mem_write=%b (expected 1)", mem_write); errors++; end

        // -----------------------------------------------------
        // Test 5: BEQ x3, x5, +12 (B-Type Branch)
        // -----------------------------------------------------
        // imm=12, rs1=3, rs2=5. opcode=1100011 (OP_BRANCH)
        instr = 32'h00518663; #10;
        $display("Testing BEQ x3, x5, +12...");
        if (rs1 !== 3) begin $display("FAIL: rs1=%0d (expected 3)", rs1); errors++; end
        if (rs2 !== 5) begin $display("FAIL: rs2=%0d (expected 5)", rs2); errors++; end
        if (imm !== 12) begin $display("FAIL: imm=%0d (expected 12). Check your imm_b slicing! Remember bit 0 is implicit 0.", imm); errors++; end
        if (branch !== 1) begin $display("FAIL: branch=%b (expected 1)", branch); errors++; end

        // -----------------------------------------------------
        // Test 6: LUI x6, 0x12345 (U-Type)
        // -----------------------------------------------------
        // imm=0x12345000 (shifted by 12), rd=6. opcode=0110111 (OP_LUI)
        instr = 32'h12345337; #10;
        $display("Testing LUI x6, 0x12345...");
        if (rd !== 6) begin $display("FAIL: rd=%0d (expected 6)", rd); errors++; end
        if (imm !== 32'h12345000) begin $display("FAIL: imm=0x%08h (expected 0x12345000). Check imm_u slicing!", imm); errors++; end
        if (reg_write !== 1) begin $display("FAIL: reg_write=%b (expected 1)", reg_write); errors++; end

        $display("\n=== Results: %0d errors ===", errors);
        if (errors == 0) $display("ALL TESTS PASSED!");
        $finish;
    end
endmodule
