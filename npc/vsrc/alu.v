
module alu(
    input[31:0] imm,
    input[31:0] src1,
    output[31:0]  pc,
    input[31:0] alu_op,
    output[31:0] result
);

wire result_auipc[31:0];
wire result_lui[31:0];
wire result_jal[31:0];
wire result_jalr[31:0];
wire result_addi[31:0];
//jal
assign pc = alu_op[2] ? pc+imm : pc;
//jalr
assign pc = alu_op[3] ? (src1+imm)&~1 : pc ;

assign result_auipc = imm + pc;
assign result_lui   = imm;
assign result_jal   = pc + 4;
assign result_jalr  = pc + 4;
assign result_addi   = src1 + imm;

assign result = ({32{alu_op[0]}} & result_auipc)
              | ({32{alu_op[1]}} & result_lui)
			  | ({32{alu_op[2]}} & result_jal)
			  | ({32{alu_op[3]}} & result_jalr)
			  | ({32{alu_op[4]}} & result_addi);

endmodule
