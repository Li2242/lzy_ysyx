


module npc(
    input  wire clk,
    output reg[31:0]  pc,
    output [31:0]  inst,
    output [31:0]  src1,
    output [31:0]  src2,
    output [4:0]   rd,
    output [31:0]  imm,
    output [31:0]  sum
);
// initial begin
//     inst = 32'h00A00093;
// end
//处理pc
pc_4 u_pc_4(
    .clk 	(clk  ),
    .pc     (pc)
);


//取指令，在C语言中

//译码
decoder u_decoder(
    .clk  	(clk   ),
    .wen  	(1   ),
    .inst 	(inst  ),
    .src1 	(src1  ),
    .src2 	(src2  ),
    .rd   	(rd    ),
    .imm  	(imm   )
);

//计算并写入寄存器

alu u_alu(
    .clk  	(clk   ),
    .src1 	(src1  ),
    .src2 	(src2  ),
    .rd   	(rd    ),
    .imm  	(imm   ),
    .sum    (sum)
);

endmodule



