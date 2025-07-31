
module alu(
    input[31:0] src1,
		input[31:0] src2,
    input[0:0]  alu_op,
    output[31:0] alu_result
);

wire[31:0] add_result;

wire add;




assign add = alu_op[0];

assign add_result = src1 + src2;

//各种指令的结果
// assign result_auipc = imm + pc;
// assign result_addi  = src1 + imm;
// assign result_add   = src1 + src2;
// assign result_lui   = imm;
// assign result_jal   = pc + 4;
// assign result_jalr  = pc + 4;
// assign result_lw    = rdata;
// assign result_lbu   = rdata;

assign alu_result = ({32{add}} & add_result);
//               | ({32{alu_op[1]}} & result_lui)
// 			  			| ({32{alu_op[2]}} & result_jal)
// 			  			| ({32{alu_op[3]}} & result_jalr)
// 			  			| ({32{alu_op[4]}} & result_addi)
// 			  			| ({32{alu_op[5]}} & result_add)
// 			  			| ({32{alu_op[6]}} & result_lw)
// 			  			| ({32{alu_op[7]}} & result_lbu);

endmodule
