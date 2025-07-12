
module decoder(
    input clk,
    input wen,
    input wire[31:0] inst,
 //从regfile输出的值
    output[31:0] src1,
    output[31:0] src2,
    output[4:0]  rd,
    output[31:0] imm
);
    wire[4:0] r1;
    wire I;
    assign I = ~inst[14]&~inst[13]&~inst[12]&~inst[6]&~inst[5]&inst[4]&~inst[3]&~inst[2]&inst[1]&inst[0];
    // 根据I型指令动态选择立即数格式
    assign imm = I ? {{20{inst[31]}}, inst[31:20]} : 32'h0; // 仅示例，需扩展其他类型
    assign r1 = inst[19:15];
    assign rd = inst[11:7];
    RegisterFile u_RegisterFile1(
        .clk    	(clk     ),
        .wen    	(wen     ),
        .raddr1 	(r1  ),
        .raddr2 	(0 ),
        .waddr  	(0   ),
        .wdata  	(0   ),
        .rdata1 	(src1  ),
        .rdata2 	(src2 )
    );


endmodule
