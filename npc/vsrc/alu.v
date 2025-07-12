
module alu(
    input clk,
    input[31:0] imm,
    input[4:0]  rd,
    output[31:0] src1,
    output[31:0] sum,
    output[31:0] src2
);
    assign sum = src1 + imm;
    RegisterFile u_RegisterFile2(
        .clk    	(clk     ),
        .wen    	(1     ),
        .raddr1 	(0  ),
        .raddr2 	(0  ),
        .waddr  	(rd   ),
        .wdata  	(sum   ),
        .rdata1 	(src1  ),
        .rdata2 	(src2  )
    );





endmodule
