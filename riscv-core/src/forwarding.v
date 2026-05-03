// ============================================================
// BoseRV — Data Forwarding Unit (Assignment D1)
//
// Detects RAW (Read-After-Write) hazards and selects which
// value to feed into the ALU — the stale register file output,
// or a fresher result being forwarded from a later pipeline stage.
//
// Two forwarding paths exist:
//   EX-EX:  instruction in MEM stage → current EX stage  (1 cycle old)
//   MEM-EX: instruction in WB stage  → current EX stage  (2 cycles old)
//
// forward_A / forward_B encoding:
//   2'b00 = use register file output (no hazard)
//   2'b10 = forward from EX/MEM register (alu_result_MEM)
//   2'b01 = forward from MEM/WB register (writeback_data / alu_result_WB)
// ============================================================
module forwarding (
    // Source register addresses of the instruction currently in EX stage
    input [4:0]  rs1_EX,
    input [4:0]  rs2_EX,

    // Destination register + write-enable of instruction in MEM stage (EX/MEM reg outputs)
    input [4:0]  rd_MEM,
    input        reg_write_MEM,

    // Destination register + write-enable of instruction in WB stage (MEM/WB reg outputs)
    input [4:0]  rd_WB,
    input        reg_write_WB,

    // MUX select outputs
    output reg [1:0] forward_A,   // selects ALU A input (rs1 path)
    output reg [1:0] forward_B    // selects ALU B input (rs2 path)
);

    // TODO (D1): Implement forwarding logic.
    //
    // Use an always @(*) combinational block.
    //
    // Default (no hazard): forward_A = 2'b00, forward_B = 2'b00
    //
    // EX-EX forwarding (highest priority — more recent result wins):
    //   if (reg_write_MEM && rd_MEM != 0 && rd_MEM == rs1_EX) → forward_A = 2'b10
    //   if (reg_write_MEM && rd_MEM != 0 && rd_MEM == rs2_EX) → forward_B = 2'b10
    //
    // MEM-WB forwarding (lower priority — only if EX-EX didn't match):
    //   if (reg_write_WB  && rd_WB  != 0 && rd_WB  == rs1_EX
    //       && !(reg_write_MEM && rd_MEM != 0 && rd_MEM == rs1_EX))
    //     → forward_A = 2'b01
    //   (same logic for rs2_EX / forward_B)
    //
    // Hint: Set defaults first, then override with EX-EX, then MEM-WB.
    //       Since EX-EX comes after MEM-WB in an if/else-if chain, EX-EX wins.

    always @(*) begin
        // TODO: fill me in
        forward_A = 2'b00;
        forward_B = 2'b00;

        if(reg_write_MEM && rd_MEM !=0 && rd_MEM == rs1_EX) begin
            forward_A = 2'b10;
        end
        else if((reg_write_WB && rd_WB !=0 && rd_WB == rs1_EX) 
                && !(reg_write_MEM && rd_MEM !=0 && rd_MEM == rs1_EX)) begin
            forward_A = 2'b01;
        end
        

        if(reg_write_MEM && rd_MEM !=0 && rd_MEM == rs2_EX) begin
            forward_B = 2'b10;
        end
        else if((reg_write_WB && rd_WB !=0 && rd_WB == rs2_EX) 
                && !(reg_write_MEM && rd_MEM !=0 && rd_MEM == rs2_EX)) begin
            forward_B = 2'b01;
        end
        
    end

endmodule
