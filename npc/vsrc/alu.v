
module alu(
    input[31:0] imm,
    input[31:0] src1,
		input[31:0] src2,
    input[6:0] alu_op,
		input[31:0] rdata,
    input[31:0] pc,
    output[31:0]  next_pc,
    output[31:0] result
);

wire [31:0] result_auipc;
wire [31:0] result_lui;
wire [31:0] result_jal;
wire [31:0] result_jalr;
wire [31:0] result_addi;
wire [31:0] result_add;
wire [31:0] result_lw;
//jal jarl
assign next_pc = alu_op[2] ? pc+imm :
                 alu_op[3] ? (src1+imm)&~1 :
                 pc+4;


assign result_auipc = imm + pc;
assign result_lui   = imm;
assign result_jal   = pc + 4;
assign result_jalr  = pc + 4;
assign result_addi  = src1 + imm;
assign result_add  = src1 + src2;
assign result_lw  = rdata;

assign result = ({32{alu_op[0]}} & result_auipc)
              | ({32{alu_op[1]}} & result_lui)
			  			| ({32{alu_op[2]}} & result_jal)
			  			| ({32{alu_op[3]}} & result_jalr)
			  			| ({32{alu_op[4]}} & result_addi)
			  			| ({32{alu_op[5]}} & result_add)
			  			| ({32{alu_op[6]}} & result_lw);

endmodule
