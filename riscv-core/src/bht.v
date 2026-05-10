// ============================================================
// BoseRV — Branch History Table (Assignment D4 - Bonus)
//
// A 2-bit saturating counter branch predictor to reduce the
// 2-cycle penalty on taken branches.
// ============================================================
module bht (
    input        clk,
    input        rst,
    // predict side
    input [31:0] pc_in,
    output       prediction,
    // update side
    input         update_en,
    input [31:0]  update_pc,
    input         actual_taken

    
    // TODO: Add your ports here (e.g., PC in, prediction out, update signals)
);
    reg [1:0] counter_table [0:63];
    // TODO (D4): Implement the 2-bit branch predictor logic.
    assign prediction =  counter_table[pc_in[7:2]][1];
    integer i;
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i<64; i= i+1) 
                counter_table[i] <= 2'b01;
        end else if (update_en) begin
            if (actual_taken) begin
            counter_table[update_pc[7:2]] = 2'b11
            end
        end
        
    end

endmodule
