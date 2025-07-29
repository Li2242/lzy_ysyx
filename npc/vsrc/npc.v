import "DPI-C" function void ebreak(input int unsigned pc);
import "DPI-C" function int v_pmem_read(input int raddr);
import "DPI-C" function void v_pmem_write(input int unsigned waddr, input int wdata, input byte wmask);
module npc(
    input  wire clk,
    input  wire rst,
    output wire [31:0]  alu_result,
    output reg  [31:0]  pc
);

//pc寄存器
Reg#(32,32'h80000000) pc_4(
    .clk 	 (clk  ),
    .rst     (rst),
    .din     (next_pc),
    .dout    (pc),
    .wen     (reg_wen)
);

//取值 必须是组合逻辑
reg[31:0]    inst;
always @(posedge clk)begin
		inst = v_pmem_read(pc);
end

//
reg [31:0] rdata;
wire [31:0] raddr;
wire mem_en;

always @(posedge clk) begin
	if(mem_en)begin
		rdata = v_pmem_read(raddr);
	end else begin
		rdata = 0;
	end
end



//ebreak 检测
always @(posedge clk) begin
	if(inst == 32'h00100073) ebreak(pc);
end




//内部信号定义

wire[6:0]    opcode;
wire[31:0]   next_pc;
wire[31:0]   imm;
wire[2:0]    funct3;
wire[31:0]   src1;
wire [31:0]  src2;
wire[4:0]    rs1;
wire [4:0] 	 rs2;
wire[4:0]    rd;
wire[6:0]    alu_op;
wire         reg_wen;
// wire         mem_wen;
//指令BIG类型
wire is_R;
wire is_I;
// wire is_S;
// wire is_B;
wire is_U;
wire is_J;

//立即数
wire [31:0]imm_R;
wire [31:0]imm_I;
// wire [31:0]imm_S;
// wire [31:0]imm_B;
wire [31:0]imm_U;
wire [31:0]imm_J;

//指令类型
wire is_auipc;
wire is_lui;
wire is_jal;
wire is_jalr;
wire is_addi;
wire is_add;
wire is_lw;


//判断类型
assign opcode  = inst[6:0];

//全部符号扩展，待会进alu在处理
assign imm_I = {{20{inst[31]}},inst[31:20]};
// assign imm_S = {{20{inst[31]}},inst[31:25],inst[11:7]};
// assign imm_B = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],0};
assign imm_U = {inst[31:12],{12{1'b0}}};
assign imm_J = {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
assign rs1    = inst[19:15];
assign rs2    = inst[24:20];
assign rd    = inst[11:7];
assign funct3 = inst[14:12];

// output declaration of module decoder7_128

wire [127:0] hot_opcode;
decoder7_128 u_decoder7_128(
	.in  	(opcode   ),
	.out 	(hot_opcode  )
);

// output declaration of module decoder3_8
wire [7:0] hot_funct3;
decoder3_8 u_decoder3_8(
	.in  	(funct3   ),
	.out 	(hot_funct3  )
);


/*
0110011 → R 型
0010011 → I 型
0000011 → I 型（load）
0100011 → S 型
1100011 → B 型
0110111 or 0010111 → U 型
1101111 → J 型
1100111 → I 型（jalr）
*/

assign is_I = (hot_opcode[19] | hot_opcode[3] | hot_opcode[103]) ? 1 : 0;
assign is_R = (hot_opcode[51]) ? 1 : 0;
// assign is_S = (hot_opcode[35]) ? 1 : 0;
assign is_U = (hot_opcode[55] | hot_opcode[23]) ? 1 : 0;
assign is_J = (hot_opcode[111]) ? 1 : 0;

//立即数的选择
assign imm = ({32{is_I}} & imm_I)
				   | ({32{is_U}} & imm_U)
		       | ({32{is_J}} & imm_J);
				// | ({32{is_S}} & imm_S);


//指令识别
assign is_auipc = is_U & hot_opcode[23];
assign is_lui   = is_U & hot_opcode[55];
assign is_jal   = is_J ;
assign is_jalr  = is_I & hot_funct3[0] & hot_opcode[103];
assign is_addi  = is_I & hot_funct3[0] & hot_opcode[19];
assign is_add   = is_R & hot_funct3[0];
assign is_lw    = is_I  & hot_funct3[2] & hot_opcode[3];

//控制信号
assign mem_en  = is_lw;
assign reg_wen = is_auipc | is_lui | is_jal | is_jalr | is_addi | is_add | is_lw;

//ALU操作码
assign alu_op[0] = is_auipc;
assign alu_op[1] = is_lui;
assign alu_op[2] = is_jal;
assign alu_op[3] = is_jalr;
assign alu_op[4] = is_addi;
assign alu_op[5] = is_add;
assign alu_op[6] = is_lw;
//读取数据
//符号扩

//内存地址
assign raddr = ({32{is_lw}} & (src1 + imm_I) );
//alu
// output declaration of module alu
alu u_alu(
    .imm    	(imm     ),
    .src1   	(src1    ),
		.src2      (src2),
    .alu_op 	(alu_op  ),
		.rdata    (rdata),
    .pc         (pc),
    .next_pc    (next_pc ),
    .result 	(alu_result  )
);



// 寄存器堆
RegisterFile u_regfile2 (
    .clk(clk),
    .wen(reg_wen),
    .waddr(rd),
    .wdata(alu_result),
    .raddr1(rs1),
    .rdata1(src1),
    .raddr2(rs2),
    .rdata2(src2)
);

endmodule



