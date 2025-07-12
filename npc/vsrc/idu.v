module idu(
    input wire clk,
    output reg[31:0] src1,
    output reg[31:0] imm,
    output reg[31:0] srd
);

    always @(posedge clk)begin
        srd <= src1 + imm;
    end


endmodule
