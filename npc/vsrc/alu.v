
module alu(
    input[31:0] src1,
		input[31:0] src2,
    input[2:0]  alu_op,
    output[31:0] alu_result
);

wire add;
wire sltu;
wire bne;

assign add  = alu_op[0];
assign sltu = alu_op[1];
assign bne  = alu_op[2];

wire [31:0] add_sub_result;
wire [31:0] sltu_result;
wire [31:0] bne_result;

//加减法
wire [31:0] adder_a;
wire [31:0] adder_b;
wire        adder_cin;
wire [31:0] adder_result;
wire        adder_cout;
assign adder_a   = src1;
assign adder_b   = (sltu) ? ~src2 : src2;
assign adder_cin = (sltu) ? 1'b1  : 1'b0;

assign {adder_cout , adder_result} = {1'b0,adder_a} + {1'b0,adder_b} + {32'b0,adder_cin};



//加减法
assign add_sub_result = adder_result;

//sltu
assign sltu_result[31:1] = 31'b0;
assign sltu_result[0] = ~adder_cout;

//bne
assign bne_result[31:1] = 31'b0;
assign bne_result[0]    = |add_sub_result;

assign alu_result = ({32{add}}  & add_sub_result)
                  | ({32{sltu}} & sltu_result)
			  			    | ({32{bne}}  & bne_result);
// 			  			| ({32{alu_op[3]}} & result_jalr)
// 			  			| ({32{alu_op[4]}} & result_addi)
// 			  			| ({32{alu_op[5]}} & result_add)
// 			  			| ({32{alu_op[6]}} & result_lw)
// 			  			| ({32{alu_op[7]}} & result_lbu);

endmodule
