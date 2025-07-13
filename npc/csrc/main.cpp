#include <stdio.h>
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"


VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vnpc* top;

void sim_end();
#define CYCKLE_NUM 10
#define IN_ADDRESS 0x80000000
__uint32_t memory[CYCKLE_NUM] = {
    0x00100093,  // 1: addi x1, x0, 1      (x1 = 0 + 1 = 1)
    0x06400113,  // 2: addi x2, x0, 100    (x2 = 0 + 100 = 100)
    0xFFB00193,  // 3: addi x3, x0, -5     (x3 = 0 - 5 = -5)
    0x0FF00213,  // 4: addi x4, x0, 255    (x4 = 0 + 255 = 255)
    0x00A08293,  // 5: addi x5, x1, 10     (x5 = 1 + 10 = 11)
    0xFFE14313,  // 6: addi x6, x5, -2     (x6 = 11 - 2 = 9)
    0x00000393,  // 7: addi x7, x0, 0      (x7 = 0 + 0 = 0)
    0x00140413,  // 8: addi x8, x8, 1      (x8 = x8 + 1 = 1)
    0x3FF00493,  // 9: addi x9, x0, 1023   (x9 = 0 + 1023 = 1023)
    0xFFF00513   // 10: addi x10, x0, -1   (x10 = 0 - 1 = -1)
};


__uint32_t pmem_read(__int32_t pc){

    __int32_t index = (pc - IN_ADDRESS) / 4;
    if (index < 0 || index >= 3) {
        printf("Error: PC 0x%X out of memory range!\n", pc);
        exit(1);
    }
  return memory[index];
}



int main(int argc,char** argv) {

    contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);
    Verilated::traceEverOn(true);
    top = new Vnpc;
    tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("waveform.vcd");


    // 1. 复位初始化
    top->clk = 0;
    top->rst = 0;
    top->eval();
    tfp->dump(contextp->time()); // 记录复位前状态
    contextp->timeInc(10);

    for(int i = 0; i < CYCKLE_NUM; i++){

    top->clk = 0;
    top->inst = pmem_read(top->pc);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);
    printf( "result = %d pc = %x\n",top->alu_result,top->pc);
  }
  sim_end();
  return 0;
}





void sim_end(){
  tfp->close();
  delete top;
  delete tfp;
  delete contextp;
}
