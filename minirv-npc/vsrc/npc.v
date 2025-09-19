import "DPI-C" function void ebreak(input int unsigned pc);
import "DPI-C" function int v_pmem_read(input int raddr, int len);
import "DPI-C" function void v_pmem_write(input int unsigned waddr, input int wdata, input byte wmask);

module npc(
    input  wire clk,
    input  wire reset,
    output wire [31:0]  alu_result,
    output reg  [31:0]  pc,
		output reg inst_valid
);

// =========================== PC ==================================
wire [31:0] nextpc;
assign nextpc =  is_jalr ? (src1 + imm) & ~1 :
                 is_jal  ?  pc + imm :  //未来B型指令要加在这里因为他们都是 pc + 4;
                 pc + 32'h4;

wire [31:0]pc_next = inst_valid ? nextpc : pc;

always @(posedge clk or negedge reset) begin
    if (!reset) begin
        pc <= 32'h80000000;     // 复位时的初始值
		end else begin
        pc <= nextpc;         // 正常情况下更新为下一条指令地址
    end
end
// =========================  PC END ===================================

always @(*)begin
		if (inst_valid) begin
  		$display("EXEC PC=0x%08h inst=0x%08h nextPC=0x%08h", pc, inst, nextpc);
		end else begin
  		$display("WAIT PC=0x%08h inst=0x%08h", pc, inst);
end
end



// =========================== IFU ======================================
//两种状态
localparam IFU_IDLE = 1'b0,
					 IFU_WAIT = 1'b1;

reg ifu_state, ifu_next_state;

//在时钟沿时更新状态
always @(posedge clk or negedge reset)begin
	if(!reset)begin
		ifu_state <= IFU_IDLE;
	end
	else begin
		ifu_state <= ifu_next_state;
	end
end

//组合逻辑决定下一个状态
always @(*) begin
	case(ifu_state)
		IFU_IDLE: ifu_next_state = IFU_WAIT;
		IFU_WAIT:begin
			ifu_next_state =  IFU_IDLE;
		end
		default: ifu_next_state = IFU_IDLE;
	endcase
end


// 总线信号
reg [31:0] ifu_raddr;
reg [31:0] ifu_rdata;
// reg        inst_valid;
reg [31:0] inst_reg;
always @(posedge clk)begin 
	case (ifu_state)
			IFU_IDLE: begin
					ifu_raddr  <= pc; // 发出取指请求
					inst_valid <= 1'b0;  // 当前周期无有效指令
			end
			IFU_WAIT: begin
					inst_valid <= 1'b1;
					inst_reg   <= v_pmem_read(ifu_raddr, 4);
			end
  endcase
end
assign inst = inst_reg;
 
// 	//打印状态信息
// 	always @(posedge clk)begin
//         $display("[Cycle %0t] ifu_state=%b pc=0x%08h inst_valid=%b ifu_raddr=0x%08h ifu_rdata=0x%08h reset=%b",
//                   $time, ifu_state, pc, inst_valid, ifu_raddr, ifu_rdata,reset);
// 				// $display("%08h: %08h", ifu_raddr, ifu_rdata);
// end


// ========================= END IFU ====================================



// ========================= 解析指令 ===================================
wire[31:0]    inst;
//肢解inst
wire[6:0]    opcode;
wire[2:0]    funct3;
wire[4:0]    rs1;
wire[4:0] 	 rs2;
wire[4:0]    rd;
//使能信号
wire    reg_wen;
wire    reg_cwen;
wire    mem_ren;
wire    mem_wen;
wire    is_mem;
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

//指令大类型(个人感觉这是处理立即数所需要的)
wire is_R;
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
wire is_csrrw;
//S
wire is_sw;
wire is_sb;
//B

//ebreak(end)
wire is_ebreak;



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
assign is_I = opcode_d[19] | opcode_d[3] | opcode_d[103] | opcode_d[115]; // 0010011 or 0000011 or 1100111 → I 型
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
assign is_csrrw = opcode_d[115] &  funct3_d[1];
//ebreak
assign is_ebreak = (inst == 32'h00100073);

//控制信号 3.加指令改
assign mem_ren   = is_lw | is_lbu;
assign mem_wen  = is_sw | is_sb ;
assign is_mem = mem_ren | mem_wen;
assign reg_wen  = (is_auipc | is_lui | is_jal | is_jalr | is_addi | is_add | is_lw | is_lbu | is_csrrw);
assign reg_cwen = is_csrrw ;

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
											is_csrrw      ?  csr_data :
											alu_result;

RegisterFile u_regfile2 (
    .clk(clk),
    .wen(reg_wen & inst_valid),
    .waddr(rd),
    .wdata(final_result),
    .raddr1(rs1),
    .rdata1(src1),
    .raddr2(rs2),
    .rdata2(src2)
);

// ================================= 寄存器END  ======================================

// ================================= CSR ================================
wire [31:0] csr_data;
csr u_csr(
	.clk(clk),
	.craddr(imm[11:0]),
	.crdata(csr_data),
	.cwaddr(imm[11:0]),
	.cwdata(src1),
	.cwen(reg_cwen)
);
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

// ==========================  LSU  =======================================
// localparam LSU_IDLE=2'b00,
// 					 LSU_BUSY=2'b01,
// 					 LSU_DONE=2'b10;

// reg[1:0] lsu_state,lsu_next_state;

// reg [31:0] lsu_addr;
// reg        lsu_wen;
// reg        lsu_ren;
// reg [31:0] lsu_wdata;
// reg [ 7:0] lsu_wmask;
// reg [31:0] lsu_rdata;
// reg[31:0] lsu_rdata_len;

// reg lsu_ready;


// // ============ 保存下来数据 ============
// always @(posedge clk)begin
// 	if(lsu_state == LSU_IDLE && (mem_wen | mem_ren))begin
// 		lsu_wen  <= mem_wen;
// 		lsu_ren  <= mem_ren;
// 		lsu_addr <= (mem_ren | mem_wen) ? src1 + imm : 32'h80000000;
// 		lsu_wdata <= src2;
// 		//掩码
// 		lsu_wmask <= is_sb ? 8'b00000001 : 8'b00001111;
// 		//读的长度
// 		lsu_rdata_len <=  is_lbu ?  1 : 4;
// 	end
// end


// //更新状态
// always @(posedge clk or negedge reset)begin
// 	if(!reset)
// 		lsu_state <= LSU_IDLE;
// 	else 
// 		lsu_state <= lsu_next_state; 
// end

// //下一个状态
// always @(*)begin
// 			case(lsu_state)
// 				LSU_IDLE:begin
// 					if(mem_wen | mem_ren)
// 						lsu_next_state = LSU_BUSY;
// 				end
// 				LSU_BUSY:begin
// 					lsu_next_state = LSU_DONE;
// 				end
// 				LSU_DONE:begin
// 					lsu_next_state = LSU_IDLE;
// 				end
// 				default: lsu_next_state = LSU_IDLE;
// 			endcase
// end

// //处理
// always @(posedge clk)begin
// 	lsu_ready <= 1'b0;
// 	case (lsu_state)
// 		LSU_IDLE:begin
// 			if (mem_ren | mem_wen)
// 					lsu_ready <= 1'b0;
// 			else
// 					lsu_ready <= 1'b1; // 没有访存指令，直接 ready
// 		end
// 		LSU_BUSY:begin
// 			if(lsu_ren)begin
// 				lsu_rdata <= v_pmem_read(lsu_addr,lsu_rdata_len);
// 			end
// 			if(lsu_wen)begin
// 				v_pmem_write(lsu_addr,lsu_wdata,lsu_wmask);
// 			end
// 		end
// 		LSU_DONE:begin
// 			lsu_ready <= 1'b1;
// 		end
// 		default: ;
// 	endcase
// end
// //调试打印
// always @(posedge clk) begin
//         $display("LSU_STATE: %b | lsu_ready: %b | lsu_wen: %b | addr: 0x%08h | wdata: 0x%08h | rdata: 0x%08h | wmask: %b", 
//                   lsu_state, lsu_ready, lsu_wen, lsu_addr, lsu_wdata, lsu_rdata, lsu_wmask);
// end



// ============================= LSU END =====================================

//ebreak 检测
always @(posedge clk) begin
	if(is_ebreak && inst_valid) ebreak(pc);
end



// ========================== 内存的读写 =====================================
//内存
reg  [31:0] rdata;
wire [31:0] raddr;
wire [31:0] waddr;
wire [31:0] wdata;
wire [7:0]  wmask;
//内存地址
assign raddr = mem_ren ? src1 + imm : 32'h80000000;
assign waddr = mem_wen ? src1 + imm : 32'h80000000;
assign wdata = src2;
//掩码
assign wmask = is_sb ? 8'b00000001 :
							 8'b00001111;


//读地址
always @(*) begin
	if(mem_ren)begin
		rdata =  is_lbu ? v_pmem_read(raddr , 1) & 32'h000000FF:
					 						v_pmem_read(raddr , 4);
	end else begin
		rdata = 0;
	end
end
//写地址
always @(posedge clk)begin
 if  (mem_wen ) begin // 有写请求时
      v_pmem_write(waddr, wdata, wmask);
    end
end
// // ========================== 内存读写结束   =====================================


endmodule



