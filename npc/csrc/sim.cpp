#include "common.h"

VerilatedContext* contextp =NULL ;
VerilatedVcdC* tfp = NULL;
Vnpc* top;
//初始化内存
uint8_t pmem[MSIZE] = {};
//初始化状态
	int npc_state = NPC_RUNNING;

//为传入文件时的指令
static const __uint32_t memory[] = {
  0x06400093,  // 1: addi x1, x0, 100    (x1 = 0 + 100 = 100)
  0x00108113,  // 2: addi x2, x1, 1      (x2 = 100 + 1 = 101)
  0x00210193,  // 3: addi x3, x2, 2      (x3 = 101 + 2 = 103)
  0x00318213,  // 4: addi x4, x3, 3      (x4 = 103 + 3 = 106)
  0x00100073,
  0x00420293,  // 5: addi x5, x4, 4      (x5 = 106 + 4 = 110)
  0x00528313,  // 6: addi x6, x5, 5      (x6 = 110 + 5 = 115)
  0x00630393,  // 7: addi x7, x6, 6      (x7 = 115 + 6 = 121)
  0x00738413,  // 8: addi x8, x7, 7      (x8 = 121 + 7 = 128)
  0x00840493,  // 9: addi x9, x8, 8      (x9 = 128 + 8 = 136)
  0x00948513   // 10: addi x10, x9, 9    (x10 = 136 + 9 = 145)
};

static void trace_and_difftest() {
  //在Kconfig中可以控制这个宏是否生成
  //扫描监视点
    bool success = false;
    scan_watchpoints(&success);
}


//开始
void sim_init(int argc,char** argv){
    contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);
    Verilated::traceEverOn(true);
    top = new Vnpc;
    tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("waveform.vcd");
		//编译正则表达式
		init_regex();
		//初始化监视点
		init_wp_pool();

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

//执行
void sim_exe(uint32_t n){

	switch (npc_state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state = NPC_RUNNING;
  }

  for(int i = 0; (i < n) && npc_state == NPC_RUNNING ; i++){
    top->clk = 0;
    top->inst = pmem_read(top->pc,4);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

		trace_and_difftest();

		if (npc_state != NPC_RUNNING){
        //判断是否正常退出
        int good = (npc_state == NPC_END && npc_state == 0) ||
                (npc_state == NPC_QUIT);
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

