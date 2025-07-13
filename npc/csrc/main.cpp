#include <stdio.h>
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"


VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vnpc* top;
int simend = 0;

extern "C" void ebreak(){
  simend = 1;
}



void sim_end();
#define CYCKLE_NUM 10
#define IN_ADDRESS 0x80000000
__uint32_t memory[CYCKLE_NUM] = {
  0x06400093,  // 1: addi x1, x0, 100    (x1 = 0 + 100 = 100)
  0x00108113,  // 2: addi x2, x1, 1      (x2 = 100 + 1 = 101)
  0x00100073,
  0x00210193,  // 3: addi x3, x2, 2      (x3 = 101 + 2 = 103)
  0x00318213,  // 4: addi x4, x3, 3      (x4 = 103 + 3 = 106)
  0x00420293,  // 5: addi x5, x4, 4      (x5 = 106 + 4 = 110)
  0x00528313,  // 6: addi x6, x5, 5      (x6 = 110 + 5 = 115)
  0x00630393,  // 7: addi x7, x6, 6      (x7 = 115 + 6 = 121)
  0x00738413,  // 8: addi x8, x7, 7      (x8 = 121 + 7 = 128)

  0x00840493,  // 9: addi x9, x8, 8      (x9 = 128 + 8 = 136)
  // 0x00948513   // 10: addi x10, x9, 9    (x10 = 136 + 9 = 145)
};


__uint32_t pmem_read(__int32_t pc){

    __int32_t index = (pc - IN_ADDRESS) / 4;
    if (index < 0 || index >= CYCKLE_NUM) {
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

    for(int i = 0; (i < CYCKLE_NUM) && simend != 1 ; i++){

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
      if(simend == 1){
        printf("ebreak指令在地址 0x%X 处被执行\n", top->pc);
        break;
      }

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
