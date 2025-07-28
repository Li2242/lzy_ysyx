
module decoder3_8(
    input wire [2:0] in,
    output wire [7:0] out
);
  genvar i;
  generate
    for(i = 0;i<8;i++)begin : gen_for_dec_3_8
        assign out[i] = (in == i);
    end endgenerate

endmodule

module decoder7_128(
    input wire[6:0] in,
    output wire[127:0] out
);

    genvar i;
    generate
        for(i = 0;i<128;i++)begin:gen_dec_for_7_128
            assign out[i] = (i==in);
    end endgenerate
endmodule

