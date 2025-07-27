#include "common.h"



VerilatedContext* contextp =NULL ;
VerilatedVcdC* tfp = NULL;
Vnpc* top;
//最大的执行数打印命令
#define MAX_INST_TO_PRINT 10;
//初始化内存
uint8_t pmem[MSIZE] = {};
//ITRACE
char logbuf[128];
//初始化状态
int npc_state = NPC_RUNNING;
//控制是否打印命令
static bool g_print_step =false;
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
		ftrace(logbuf);
		if(g_print_step){ printf("%s\n",logbuf);}
		log_write("%s\n",logbuf);
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
		//初始化反汇编
		init_disasm();
		//初始化日志文件
		init_log();
		//初始化elf文件
		init_elf();
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
void execute(uint32_t n){
	g_print_step = n < MAX_INST_TO_PRINT;
  for(int i = 0; (i < n) && npc_state == NPC_RUNNING ; i++){
		//pc值要正确,这是变化前的pc，后面经过执行就变成下一个pc了
		int pc = top->pc;
    top->clk = 0;
    top->inst = pmem_read(top->pc,4);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);
		//ITRACE
		char* p = logbuf;
		//先写入pc
		p += snprintf(p, sizeof(logbuf), "0x%08x:",pc);
		int ilen = 4;
		int k;
		uint8_t *inst = (uint8_t *)&top->inst;

		for(k = ilen - 1; k >= 0; k --){
			p += snprintf(p,4," %02x", inst[k]);
		}
		int space_len = 1;
		memset(p,' ',space_len);
		p += space_len;
		void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
		disassemble(p,logbuf + 128 - p,pc,(uint8_t *)&top->inst,ilen);
		//检查监视点是否改变 运行中检查
		trace_and_difftest();
  }
}

void sim_exe(uint32_t n){

	//看一下程序是否运行完成
	switch (npc_state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      green_printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state = NPC_RUNNING;
  }

	execute(n);

	//这边应该是对退出状态的检查
	switch (npc_state) {
			case NPC_RUNNING: npc_state = NPC_STOP; break;
			case NPC_END: case NPC_ABORT:
				green_printf("我现在并不知道它是否正确退出，反正是退出了\n");
				// fall through
			case NPC_QUIT: return ;
		}
}

//结束
void sim_end(){
  tfp->close();
  delete top;
  delete tfp;
  delete contextp;
}
