// ============================================================
// BoseRV — Hazard Detection Unit (Assignment D2)
//
// Detects LOAD-USE hazards: when a LW instruction is immediately
// followed by an instruction that reads the loaded register.
//
// Even with forwarding, this can't be resolved without a stall
// because the memory read data isn't available until the END of
// the MEM stage — but the dependent instruction needs it at the
// START of its EX stage, which is the SAME cycle.
//
// Example:
//   LW   x1, 0(x0)   ← EX stage (mem_read_EX=1, rd_EX=x1)
//   ADD  x4, x1, x2  ← ID stage (rs1_ID=x1)  ← HAZARD!
//
// When stall=1, the controller must:
//   1. Freeze the PC (don't advance)
//   2. Freeze IF/ID register (don't latch new instruction)
//   3. Insert a NOP bubble into ID/EX (clear all control signals)
// ============================================================
module hazard (
    // From ID/EX register: the instruction currently in EX stage
    input        mem_read_EX,   // 1 = the EX-stage instruction is a LOAD
    input [4:0]  rd_EX,         // destination register of the EX-stage instruction

    // From IF/ID register: source registers of the instruction currently in ID stage
    input [4:0]  rs1_ID,
    input [4:0]  rs2_ID,

    // Output: 1 = stall the pipeline for one cycle
    output stall
);

    // TODO (D2): Implement load-use hazard detection.
    //
    // A hazard exists when ALL of the following are true:
    //   1. The EX-stage instruction is a load  (mem_read_EX == 1)
    //   2. The load has a real destination     (rd_EX != 0)
    //   3. The load's destination matches one of the ID-stage sources
    //      (rd_EX == rs1_ID  OR  rd_EX == rs2_ID)
    //
    // This can be a single combinational assign statement.

    assign stall = 1'b0; // TODO: replace with real hazard detection

endmodule
