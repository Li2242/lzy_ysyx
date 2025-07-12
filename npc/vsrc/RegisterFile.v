

//寄存器堆至少需要两个读端口和一个写端口
module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input wire clk,
  //写端口
  input wire wen,
  input wire [ADDR_WIDTH-1:0] waddr,
  input wire [DATA_WIDTH-1:0] wdata,
  //读端口1
  input  wire[ADDR_WIDTH-1:0] raddr1,
  output wire[DATA_WIDTH-1:0] rdata1,
  //读端口2
  input  wire[ADDR_WIDTH-1:0] raddr2,
  output wire[DATA_WIDTH-1:0] rdata2
);
//寄存器
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

  always @(posedge clk) begin
    if(wen) rf[waddr] <= wdata;
  end
//读1
  assign rdata1 = rf[raddr1];
//读2
  assign rdata2 = rf[raddr2];
endmodule
