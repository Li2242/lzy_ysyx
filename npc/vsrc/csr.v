module csr(
	input wire clk,
	//csr读
	input  wire[11:0] craddr,
	output wire[31:0] crdata,
	//csr写
	input wire cwen,
	input wire [11:0] cwaddr,
	input wire [31:0] cwdata 
);

// =================== CSR =========================
reg [31:0] mcycle;
reg [31:0] mcycleh;

localparam [31:0] mvendorid = 32'h79737978;
localparam [31:0] marchid   = 32'h17E634B;

always @(posedge clk)begin
	{mcycleh,mcycle} <= { mcycleh,mcycle } + 1;
end
//csr_read
assign crdata = (craddr == 12'hB00) ? mcycle  :
								(craddr == 12'hB02) ? mcycleh :
								(craddr == 12'hF11) ? mvendorid:
								(craddr == 12'hF12) ? marchid:
								32'b0;
//csr_write
always @(posedge clk)begin
	if(cwen)begin
		// $display("mcycle: %d, mcycleh: %d", mcycle, mcycleh);
		case(cwaddr)
			12'hB00:mcycle  <= cwdata;
			12'hB02:mcycleh <= cwdata;
			default: ;
		endcase
	end
end

// always @(posedge clk) begin
//   if (cwen) begin
//       $display("CSR read: craddr = %h, mcycle = %d, mcycleh = %d", craddr, mcycle, mcycleh);
//   end
// end

endmodule
