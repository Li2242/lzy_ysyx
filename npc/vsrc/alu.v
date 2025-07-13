
module alu(
    input[31:0] imm,
    input[31:0] src1,
    output[31:0] result
);

    assign result = src1 + imm;

endmodule
