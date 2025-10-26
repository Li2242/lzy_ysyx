module csr(
	input wire clk,
	input wire [31:0]pc,
	//csr读
	input  wire[11:0] craddr,
	output wire[31:0] crdata,
	//csr写
	input wire cwen,
	input wire [11:0] cwaddr,
	input wire [31:0] cwdata,
	//特殊处理 
	input wire is_ecall
);

// =================== CSR =========================
reg [31:0]mepc;
reg [31:0]mcause;
reg [31:0]mstatus;
reg [31:0]mtvec;

//csr_read
assign crdata = (craddr == 12'h300) ? mstatus  :
								(craddr == 12'h305) ? mtvec :
								(craddr == 12'h341) ? mepc  :
								(craddr == 12'h342) ? mcause:
								32'b0;

//csr_write
always @(posedge clk)begin
	if(cwen)begin
		case(cwaddr)
			12'h300: mstatus <= cwdata;
			12'h305: mtvec   <= cwdata;
			12'h341: mepc    <= cwdata;
			12'h342: mcause  <= cwdata;
			default: ;
		endcase
	end
	//ecall的特殊处理
	if(is_ecall)begin
		mepc   <= pc;
		mcause <= 32'hb;
	end
end
endmodule
