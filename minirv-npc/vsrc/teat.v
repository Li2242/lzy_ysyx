module npc(
    input  wire clk,
    input  wire reset,
    output wire [31:0]  alu_result,
    output reg  [31:0]  pc
);

// =========================== PC ==================================
wire [31:0] nextpc;

assign nextpc =  is_jalr ? (src1+imm) & ~1 :
                 is_jal  ?  pc + imm :  //未来B型指令要加在这里因为他们都是 pc + 4;
                 pc + 32'h4 ;

//更新pc
always @(posedge clk) begin
    if (reset) begin
        pc <= 32'h80000000;     // 复位时的初始值
    end
    else begin
        pc <= nextpc;           // 正常情况下更新为下一条指令地址
    end
end
// =========================  PC END ===================================


// ========================= 解析指令 ===================================
reg[31:0]    inst;
//肢解inst
wire[6:0]    opcode;
wire[2:0]    funct3;
wire[4:0]    rs1;
wire[4:0] 	 rs2;
wire[4:0]    rd;
//使能信号
wire    reg_wen;
wire    mem_en;
wire    mem_wen;
wire reg_from_mem;
wire reg_from_pc_4;
wire reg_from_imm;
//立即数
wire [31:0]imm;
wire [31:0]imm_I;
wire [31:0]imm_U;
wire [31:0]imm_J;
wire [31:0]imm_S;

//指令大类型(个人感觉这是处理立即数所需要的)
wire is_I;
wire is_U;
wire is_J;
wire is_S;

//指令小类型
//U(end)
wire is_lui;
wire is_auipc;
//J(end)
wire is_jal;
//R
wire is_add;
//I
wire is_jalr;
wire is_addi;
wire is_lw;
wire is_lbu;
//S
wire is_sw;
wire is_sb;
//ebreak(end)
wire is_ebreak;


//取出inst
InstMem u_InstMem(
	.addr 	(pc  ),
	.inst 	(inst  )
);


//全部符号扩展，待会在处理
assign imm_S = {{20{inst[31]}},inst[31:25],inst[11:7]};
assign imm_I = {{20{inst[31]}},inst[31:20]};
assign imm_U = {inst[31:12],{12{1'b0}}};
assign imm_J = {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
//判断类型
assign opcode  = inst[6:0];
assign rs1     = inst[19:15];
assign rs2     = inst[24:20];
assign rd      = inst[11:7];
assign funct3  = inst[14:12];


//独热码
wire [127:0] opcode_d;
decoder7_128 u_decoder7_128(
	.in  	(opcode   ),
	.out 	(opcode_d  )
);

wire [7:0] funct3_d;
decoder3_8 u_decoder3_8(
	.in  	(funct3   ),
	.out 	(funct3_d  )
);
//大类
assign is_I = opcode_d[19] | opcode_d[3] | opcode_d[103] ; // 0010011 or 0000011 or 1100111 → I 型
assign is_U = opcode_d[55] | opcode_d[23] ;                // 0110111 or 0010111 → U 型
assign is_J = opcode_d[111] ;                              // 1101111 → J 型
assign is_R = opcode_d[51] ;                               // 0110011 → R 型
assign is_S = opcode_d[35] ;                            // 0100011 → S 型


//指令识别
//U
assign is_auipc =  opcode_d[23];
assign is_lui   =  opcode_d[55];
// //J
assign is_jal   =  opcode_d[111];
//R
assign is_add   =  opcode_d[51]  &  funct3_d[0];
//I
assign is_jalr  =  opcode_d[103] &  funct3_d[0];
assign is_addi  =  opcode_d[19]  &  funct3_d[0];
assign is_lw    =  opcode_d[3]   &  funct3_d[2];
assign is_lbu   =  opcode_d[3]   &  funct3_d[4];
assign is_sw    =  opcode_d[35]  &  funct3_d[2];
assign is_sb    =  opcode_d[35]  &  funct3_d[0];
//ebreak
assign is_ebreak = (inst == 32'h00100073);

//控制信号 3.加指令改
assign mem_en   = is_lw | is_lbu;
assign mem_wen  = is_sw | is_sb;
assign reg_wen  = is_auipc | is_lui | is_jal | is_jalr | is_addi | is_add | is_lw | is_lbu;

assign reg_from_mem  = is_lw  | is_lbu;
assign reg_from_pc_4 = is_jal | is_jalr;
assign reg_from_imm  = is_lui;

//立即数的选择
assign imm = ({32{is_I}} & imm_I)
				   | ({32{is_U}} & imm_U)
		       | ({32{is_J}} & imm_J)
				   | ({32{is_S}} & imm_S);

// ======================= 解析指令 END ===================================

// ======================= 寄存器堆 ============================
wire [31:0] final_result;

assign final_result = reg_from_mem  ?  rdata  :
									    reg_from_pc_4 ?  pc + 4 :
											reg_from_imm  ?  imm    :
											alu_result;

RegisterFile u_regfile2 (
    .clk(clk),
    .wen(reg_wen),
    .waddr(rd),
    .wdata(final_result),
    .raddr1(rs1),
    .rdata1(src1),
    .raddr2(rs2),
    .rdata2(src2)
);

// ================================= 寄存器END  ======================================

// =======================    ALU  ========================================
wire [0:0]  alu_op;           //1.加指令时需要改
wire        src1_is_pc;
wire        src2_is_imm;
wire [31:0]   src1;
wire [31:0]   src2;
wire [31:0] alu_src1;
wire [31:0] alu_src2;

//2.加指令时这里需要改
assign src1_is_pc = is_auipc;
assign src2_is_imm = is_addi | is_auipc;

assign alu_src1 = src1_is_pc ? pc : src1;
assign alu_src2 = src2_is_imm ? imm : src2;
//4.改
assign alu_op[0] = is_add | is_addi | is_auipc;


//alu
alu u_alu(
    .src1   	(alu_src1    ),
		.src2      (alu_src2),
    .alu_op 	(alu_op  ),
    .alu_result 	(alu_result  )
);

// ========================== ALU END ========================================


// ========================== 内存的读写 =====================================
//内存
reg  [31:0] rdata;
wire [31:0] raddr;
wire [31:0] waddr;
wire [31:0] wdata;
wire [3:0]  wmask;
//内存地址
assign raddr = mem_en  ? src1 + imm : 32'h80000000;
assign waddr = mem_wen ? src1 + imm : 32'h80000000;
assign wdata = src2;
//掩码
assign wmask = is_sb ? 4'b0001 :
							 4'b1111;

Memory u_mem (
    .clk(clk),
    .mem_en(mem_en),
    .mem_wen(mem_wen),
    .addr(mem_wen ? waddr[27:0] : raddr[27:0]),
    .wdata(wdata),
    .wmask(wmask[3:0]),   // 改成 4bit
    .rdata(rdata)
);

//ebreak 检测
always @(posedge clk) begin
	if(is_ebreak) begin
		// $finish;
	end;
end

endmodule
// ========================== 内存读写结束   =====================================



//=================================== 内存 ===========================================
module Memory(
    input  wire        clk,
    input  wire        mem_en,
    input  wire        mem_wen,
    input  wire [31:0] addr,
    input  wire [31:0] wdata,
    input  wire [3:0]  wmask,     // 注意这里用 4bit 而不是 8bit，表示字节掩码
    output reg  [31:0] rdata
);

    // 字节寻址内存（综合可用）
    reg [7:0] mem [0:268435455];

    // 读操作（组合逻辑）
    always @(*) begin
        if (mem_en) begin
            rdata = {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]};
        end else begin
            rdata = 32'b0;
        end
    end

    // 写操作（时序逻辑）
    always @(posedge clk) begin
        if (mem_wen) begin
            if (wmask[0]) mem[addr+0] <= wdata[7:0];
            if (wmask[1]) mem[addr+1] <= wdata[15:8];
            if (wmask[2]) mem[addr+2] <= wdata[23:16];
            if (wmask[3]) mem[addr+3] <= wdata[31:24];
        end
    end
endmodule
// ======================================== pc =============================================

module InstMem(
  input  [31:0] addr,
  output [31:0] inst
);
  reg [7:0] mem[0:268435455];

  assign inst = {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]};
endmodule

//======================================== END  ================================================



//==============================    寄存器 ======================================================================

module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input wire clk,
  //写端口
  input wire wen,
  input wire [ADDR_WIDTH-1:0] waddr,
  input wire [DATA_WIDTH-1:0] wdata,
  //读端口1
  input  wire[ADDR_WIDTH-1:0] raddr1,
  output wire[DATA_WIDTH-1:0] rdata1,
  //读端口2
  input  wire[ADDR_WIDTH-1:0] raddr2,
  output wire[DATA_WIDTH-1:0] rdata2
);
//寄存器
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

//READ 1
assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];

//READ 2
assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];

//WRITE
  always @(posedge clk) begin
    if(wen && waddr!=5'b0) rf[waddr] <= wdata;
  end
endmodule

// ====================================== 寄存器结束 ========================================================



// ====================================== ALU ===========================================================
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

assign alu_result = ({32{add}} & add_result);

endmodule

//========================================== ALU end ======================================================


// ========================================== DECODER =========================================================
module decoder3_8(
    input wire [2:0] in,
    output wire [7:0] out
);
  genvar i;
  generate
    for(i = 0;i<8;i++)begin : gen_for_dec_3_8
        assign out[i] = (in == i);
    end endgenerate

endmodule

module decoder7_128(
    input wire[6:0] in,
    output wire[127:0] out
);

    genvar i;
    generate
        for(i = 0;i<128;i++)begin:gen_dec_for_7_128
            assign out[i] = (i==in);
    end endgenerate
endmodule
// ================================== DECODER END=======================================
