#include <stdio.h>
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"


VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vnpc* top;

void sim_end();

#define IN_ADDRESS 0x80000000
__uint32_t memory[3] = {
  0x00A00093,
  0x01408113,
  0xFFB10193,
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
    top->eval();
    tfp->dump(contextp->time()); // 记录复位前状态
    contextp->timeInc(1);

    for(int i = 0; i<3; i++){
    top->clk = 1;
    top->inst = pmem_read(top->pc);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(1);

    top->clk = 0;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(1);
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
