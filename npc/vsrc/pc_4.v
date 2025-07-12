module pc_4(
    input clk,
    output reg[31:0] pc
);

always @(posedge clk ) begin
    pc <= pc + 32'h4;  // 每个时钟周期PC+4
end

endmodule
