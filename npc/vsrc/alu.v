
module alu(
    input clk,
    input[31:0] imm,
    input[4:0]  rd,
    output[31:0] src1,
    output[31:0] src2
);
    wire[31:0] temp;
    assign temp = src1 + imm;
initial begin
    $display("temp = %d",temp);
end
    RegisterFile u_RegisterFile2(
        .clk    	(clk     ),
        .wen    	(1     ),
        .raddr1 	(0  ),
        .raddr2 	(0  ),
        .waddr  	(rd   ),
        .wdata  	(temp   ),
        .rdata1 	(src1  ),
        .rdata2 	(src2  )
    );





endmodule
