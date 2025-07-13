
module decoder(
    input wire wen,
    input wire[31:0] inst,
 //从regfile输出的值
    output[4:0] rs1,
    output[4:0]  rd,
    output[31:0] imm,
    output wire  reg_wen
);

    wire[6:0] opcode;
    wire[2:0] funct3;

    //读取数据
    assign imm     = {{20{inst[31]}},inst[31:20]};
    assign opcode  = inst[6:0];
    assign rs1      = inst[19:15];
    assign rd      = inst[11:7];
    assign funct3  = inst[14:12];

    wire is_addi = (opcode == 7'b0010011) && (funct3 == 3'b000);
    assign reg_wen = wen && is_addi;


endmodule
