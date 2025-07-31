import "DPI-C" function void ebreak(input int unsigned pc);
import "DPI-C" function int v_pmem_read(input int raddr, int len);
import "DPI-C" function void v_pmem_write(input int unsigned waddr, input int wdata, input byte wmask);

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
wire [31:0]imm_R;
wire [31:0]imm_I;
wire [31:0]imm_U;
wire [31:0]imm_J;
wire [31:0]imm_S;
// wire [31:0]imm_B;

//指令大类型(个人感觉这是处理立即数所需要的)
wire is_R;
wire is_I;
wire is_U;
wire is_J;
wire is_S;
// wire is_B;

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
//B

//ebreak(end)
wire is_ebreak;



//取出inst
assign inst = v_pmem_read(pc,4);


//全部符号扩展，待会在处理
assign imm_S = {{20{inst[31]}},inst[31:25],inst[11:7]};
// assign imm_B = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],0};
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
// assign is_B = opcode_[99] ;                             // 1100011 → B 型
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
wire [7:0]  wmask;
//内存地址
assign raddr = src1 + imm ;
assign waddr = src1 + imm;
// assign raddr = mem_en ? src1 + imm : 32'h80000004;
// assign waddr = mem_wen ? src1 + imm : 32'h80000000;
assign wdata = src2;
//掩码
assign wmask = is_sb ? 8'b00000001 :
							 8'b00001111;

//读地址
always @(*) begin
	if(mem_en)begin
		$display("mem_en=%b, is_lbu=%b, raddr=0x%08x", mem_en, is_lbu, raddr);
		rdata =  is_lbu ? v_pmem_read(raddr , 1) & 32'hFF:
							// is_lhu ? v_pmem_read(raddr , 2) & 32'hFFFF:
					 						 v_pmem_read(raddr , 4);
	end else begin
		rdata = 0;
	end
end
//写地址
always @(posedge clk)begin
 if  (mem_wen) begin // 有写请求时
      v_pmem_write(waddr, wdata, wmask);
    end
end
// ========================== 内存读写结束   =====================================


//ebreak 检测
always @(posedge clk) begin
	if(is_ebreak) ebreak(pc);
end

// 调试显示
always @(posedge clk) begin
    if (reg_wen) begin
        $display("RegWrite: rd=%d,  final_result=0x%08x, mem_en=%b, rdata=0x%08x",
                 rd,  final_result, mem_en, rdata);
    end
		// $display("mem_en=%b,is_lw=%b ,is_lbu=%b",
    //               mem_en,is_lw,is_lbu);
end

always @(posedge clk) begin
    if (mem_wen) begin
        $display("MemWrite: waddr=0x%08x,  wdata=0x%08x, mem_wen=%b, wmask=0x%08x",
                 waddr,  wdata, mem_wen, wmask);
    end
end


endmodule



