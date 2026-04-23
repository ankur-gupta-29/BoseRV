// ============================================================
// BoseRV — IF/ID Pipeline Register (Assignment C1)
//
// Sits between Fetch stage and Decode stage.
// Latches PC and instruction on every rising clock edge.
//
// On reset: both outputs go to 0 (acts like a NOP in pipeline)
// On stall: (C4) you will add a stall/flush enable later
// ============================================================
module if_id (
    input         clk,
    input         rst,

    // Inputs from Fetch stage
    input  [31:0] pc_in,      // current PC (used by AUIPC, JAL/JALR return addr)
    input  [31:0] instr_in,   // raw 32-bit instruction from imem

    // Outputs to Decode stage
    output reg [31:0] pc_out,
    output reg [31:0] instr_out
);

    // TODO (C1): Implement the pipeline register.
    //
    // Rules:
    //   - On posedge clk: latch pc_in → pc_out, instr_in → instr_out
    //   - On rst:         both outputs = 0
    //
    // Hint: a single always @(posedge clk or posedge rst) block is enough.
    // This is the simplest pipeline register — no stall/flush yet (that's C4).

    always @(posedge clk or posedge rst) begin
        // TODO: fill me in
        if(rst) begin
            pc_out    <=0;
            instr_out <=0;
        end
        else begin
             pc_out <= pc_in;
             instr_out <= instr_in;
        end
    end

endmodule
