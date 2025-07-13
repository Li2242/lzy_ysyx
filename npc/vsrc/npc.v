
module npc(
    input  wire clk,
    input  wire rst,
    input  wire [31:0]  inst,
    output wire [31:0]  alu_result,
    output reg  [31:0]  pc
);
initial begin
    pc = 32'h80000000;
end

//使用触发器处理pc
Reg#(32,32'h80000000) pc_4(
    .clk 	 (clk  ),
    .rst     (rst),
    .din     (pc+32'h4),
    .dout    (pc),
    .wen     (1)
);

//内部信号定义
wire [31:0]  src1;
wire [31:0]  imm;
wire [4:0]   rs1;
wire [4:0]   rd;
wire         reg_wen;

//取指令，在C语言中

//译码
decoder u_decoder(
    .wen  	(1'b1   ),
    .inst 	(inst  ),
    .rs1 	(rs1  ),
    .rd   	(rd    ),
    .imm  	(imm   ),
    .reg_wen(reg_wen)
);


//计算并写入寄存器

alu u_alu(
    .src1 	(src1  ),
    .imm  	(imm   ),
    .result    (alu_result)
);

    // 寄存器堆实例化
    RegisterFile u_regfile2 (
        .clk(clk),
        .wen(reg_wen),
        .waddr(rd),
        .wdata(alu_result),
        .raddr1(rs1),
        .rdata1(src1)
    );

endmodule



