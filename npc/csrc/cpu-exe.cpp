#include "common.h"

//开始
void sim_init(int argc,char** argv){
    contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);
    Verilated::traceEverOn(true);
    top = new Vnpc;
    tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("waveform.vcd");
    //写入内置程序
    memcpy(pmem,memory,sizeof(memory));
    // 1. 复位初始化
    top->clk = 0;
    top->rst = 0;
    top->pc = MBASE;
    //载入外部程序 这个返回值暂时用不上
    long img_size = load_img();
    top->eval();
    tfp->dump(contextp->time()); // 记录复位前状态
    contextp->timeInc(10);
}

void sim_exe(){
    for(int i = 0; (i < MSIZE) && simend != 1 ; i++){
    top->clk = 0;
    top->inst = pmem_read(top->pc,4);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);
        //结束
      if(simend == 1){
        printf("ebreak指令在地址 0x%X 处被执行\n", top->pc);

        break;
      }

    printf( "result = %d pc = %x\n",top->alu_result,top->pc);
  }
}


//结束
void sim_end(){
  tfp->close();
  delete top;
  delete tfp;
  delete contextp;
}
