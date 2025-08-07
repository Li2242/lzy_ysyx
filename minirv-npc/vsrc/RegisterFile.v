
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

//READ 1
assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];

//READ 2
assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];

//WRITE
  always @(posedge clk) begin
    if(wen && waddr!=5'b0) rf[waddr] <= wdata;
  end


endmodule

