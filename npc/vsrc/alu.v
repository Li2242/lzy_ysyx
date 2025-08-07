
module alu(
    input[31:0] src1,
		input[31:0] src2,
    input[11:0]  alu_op,
    output[31:0] alu_result
);

wire add;
wire sltu;
wire bne;
wire xor0;
wire or0;
wire sub;
wire sra;
wire sll;
wire and0;
wire bge;
wire beq;
wire srl;

assign add  = alu_op[0];
assign sltu = alu_op[1];
assign bne  = alu_op[2];
assign xor0  = alu_op[3];
assign or0  = alu_op[4];
assign sub = alu_op[5];
assign sra = alu_op[6];
assign sll = alu_op[7];
assign and0 = alu_op[8];
assign bge = alu_op[9];
assign beq = alu_op[10];
assign srl = alu_op[11];

wire [31:0] add_sub_result;
wire [31:0] sltu_result;
wire [31:0] bne_result;
wire [31:0] xor_result;
wire [31:0] or_result;
wire [31:0] sra_result;
wire [31:0] sll_result;
wire [31:0] and_result;
wire [31:0] bge_result;
wire [31:0] beq_result;
wire [31:0] srl_result;

//加减法
wire [31:0] adder_a;
wire [31:0] adder_b;
wire        adder_cin;
wire [31:0] adder_result;
wire        adder_cout;
assign adder_a   = src1;
assign adder_b   = (sltu | bne | sub | bge | beq) ? ~src2 : src2;
assign adder_cin = (sltu | bne | sub | bge | beq) ? 1'b1  : 1'b0;

assign {adder_cout , adder_result} = {1'b0,adder_a} + {1'b0,adder_b} + {32'b0,adder_cin};



//加减法
assign add_sub_result = adder_result;

//sltu(无符号比较)a<b
assign sltu_result[31:1] = 31'b0;
assign sltu_result[0] = ~adder_cout;

//bge(补码比较)
assign bge_result[31:1] = 31'b0;
assign bge_result[0]    = ~((src1[31] != src2[31]) ? src1[31] : adder_result[31]);

//bne
assign bne_result[31:1] = 31'b0;
assign bne_result[0]    = |add_sub_result;
//beq
assign beq_result[31:1] = 31'b0;
assign beq_result[0] = ~(|add_sub_result);

//xor
assign xor_result = src1 ^ src2;
//or
assign or_result  = src1 | src2;
//and
assign and_result = src1 & src2;

//sra
assign sra_result = src1 >>> src2[4:0];
//sll
assign sll_result = src1 << src2[4:0];
//srl
assign srl_result = src1 >> src2[4:0];

assign alu_result = ({32{add | sub}}  & add_sub_result)
                  | ({32{sltu}} & sltu_result)
			  			    | ({32{bne}}  & bne_result)
			  			    | ({32{xor0}} & xor_result)
			  			    | ({32{or0}}  & or_result)
			  			    | ({32{sra}}  & sra_result)
			  			    | ({32{sll}}  & sll_result)
			  			    | ({32{and0}} & and_result)
			  			    | ({32{bge}}  & bge_result)
			  			    | ({32{beq}}  & beq_result)
			  			    | ({32{srl}}  & srl_result);
// 			  			| ({32{alu_op[4]}} & result_addi)
// 			  			| ({32{alu_op[5]}} & result_add)
// 			  			| ({32{alu_op[6]}} & result_lw)
// 			  			| ({32{alu_op[7]}} & result_lbu);

endmodule
