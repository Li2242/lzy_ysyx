module pc_reg(
    input  wire      clk,
    input  wire      rst,
    output  reg      wen,
    output reg[31:0] pc

);
    always @(posedge clk)begin
        if(rst) wen <= 0;
        else    wen <= 1;
    end

    always @(posedge clk)begin
        if(wen) pc <= pc + 32'h4;
        else    pc <= 32'h80000000;
    end
endmodule
