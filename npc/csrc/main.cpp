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
  return memory[(pc-IN_ADDRESS)/4];
}




int main(int argc,char** argv) {


    contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);
    Verilated::traceEverOn(true);
    top = new Vnpc;
    tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("waveform.vcd");


    for(int i = 0; i<3; i++){
    top->clk = 1;
    top->inst = pmem_read(top->pc);
    top->eval();
    contextp->timeInc(1);

    if(i>=3){
      break;
    }

    top->clk = 0;
    top->inst = pmem_read(top->pc);
    top->eval();
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
