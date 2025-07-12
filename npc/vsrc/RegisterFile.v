module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input wen,
  input [ADDR_WIDTH-1:0] waddr,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] raddr1,
  output reg[DATA_WIDTH-1:0] rdata1,
  input [ADDR_WIDTH-1:0] raddr2,
  output reg[DATA_WIDTH-1:0] rdata2,
  input [ADDR_WIDTH-1:0] rd,
  output reg[DATA_WIDTH-1:0] rrd
);
//寄存器
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

//初始化寄存器
  initial begin
      integer i;
      for (i = 0; i < 2**ADDR_WIDTH-1; i = i + 1) begin
        rf[i] = 'h0;
      end
  end
//写
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

//读
  always @(posedge clk) begin
    if (wen) rdata1 <= rf[raddr1];
  end

  always @(posedge clk) begin
    if (wen) rdata2 <= rf[raddr2];
  end

  always @(posedge clk) begin
    if (wen) rrd <= rf[rd];
  end


endmodule
