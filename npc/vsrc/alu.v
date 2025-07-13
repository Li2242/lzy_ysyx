
module alu(
    input[31:0] imm,
    input[31:0] src1,
    input[31:0] src2,
    output[31:0] result
);

    assign result = src1 + imm + src2 - src2;

endmodule
