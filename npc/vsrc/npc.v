// `include "RegisterFile.v"
// `include "Selector.v"
// `include "Trigger.v"
// `include "pc_reg.v"
// `timescale 1ns/1ps


module npc(
    input  wire clk,
    input  wire rst,
    output reg  wen,
    output reg [31:0] rf [31:0],
    output reg[31:0]  pc,
    output reg[31:0]  inst,
    output reg[31:0]  src1,
    output reg[4:0]  rd,
    output reg[31:0]  imm
);
//初始化寄存器
  initial begin
      integer i;
      for (i = 0; i < 31; i = i + 1) begin
        rf[i] = 'h0;
      end
      inst = 0;
  end



//处理pc
    pc_reg pc_reg1(
        .clk 	(clk  ),
        .rst 	(rst  ),
        .pc  	(pc   ),
        .wen    (wen)
    );
//取指令，在C语言中

//译码
always@(clk)begin
    src1 <= rf[inst[19:15]];
    imm  <= {{20{inst[31]}},{inst[31:20]}};
    rd   <= inst[11:7];
end

//处理
// output declaration of module idu

idu u_idu(
    .clk  	(clk   ),
    .src1 	(src1  ),
    .imm  	(imm   ),
    .srd  	(rf[rd]   )
);

endmodule



//存储器用C语言实现，这里可以不写

