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
//这个文件单独要用到的函数
static void trace_and_difftest();
static void execute(uint32_t n);

//开始
void sim_init(int argc,char** argv){

	contextp = new VerilatedContext;
	contextp->commandArgs(argc,argv);
	Verilated::traceEverOn(true);
	top = new Vnpc;
	tfp = new VerilatedVcdC;
	top->trace(tfp,99);
	tfp->open("waveform.vcd");





// =============== 这里是初始化 ===============
		//载入镜像文件 外部程序 or 内置指令
  long img_size = load_img();

		//初始化测试
	if(diff_so_file != NULL){
		init_difftest(diff_so_file , img_size);
	}
		//编译正则表达式
		init_regex();
		//初始化监视点
		init_wp_pool();
		//初始化反汇编
		init_disasm();
		//初始化日志文件
		init_log();
		//初始化elf文件
		if(elf_file != NULL){ init_elf(); }

		// 1. 复位初始化
		// 在仿真环境中
	top->clk = 0;
	top->reset = 1;
	top->eval();     // 应用复位状态

	top->clk = 1;
	top->eval();     // 应用复位状态


	top->reset = 0;
	top->clk = 0;
	top->eval();     // 应用复位状态
	green_printf("===========================================\n");

//====================  这里是初始化的结束  ===============
}



void sim_exe(uint32_t n){

	//检测程序是否结束
	switch (npc_state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      green_printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state = NPC_RUNNING;
  }
	top->reset = 0;
	execute(n);

	//我有了difftest如果不出大问题，这里的退出都是正常退出
	switch (npc_state) {
			case NPC_RUNNING: npc_state = NPC_STOP; break;
			case NPC_END: case NPC_ABORT:
				// green_printf("npc: HIT GOOD TRAP\n");
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

//执行
static void execute(uint32_t n){
	g_print_step = n < MAX_INST_TO_PRINT;
  for(int i = 0; (i < n) && npc_state == NPC_RUNNING ; i++){
		//pc值要正确,这是变化前的pc，后面经过执行就变成下一个pc了
		//执行命令前我先存一个pc
		cpu_pc = top->pc;
		// printf("0x%08x\n",cpu_pc);

//===============  一条命令的开始  ========================
    top->clk = 0;
    // top->inst = pmem_read(top->pc,4);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);
//===============  一条命令的结束  =========================

//正如函数名所说它就是TRACE和DIFFTEST的办公场所
		trace_and_difftest();
  }
}


static void trace_and_difftest() {
//===============  ITRACING BEGINS ========================
		//我在考虑是否可以把它放进trace_and_difftest里面
		//为什么我把它移进去，我的ftrace失效了，我需要慎重考虑一下

		char* p = logbuf;
		//写入pc
		p += snprintf(p, sizeof(logbuf), "0x%08x:",cpu_pc);
		int ilen = 4;
		int k;
		uint32_t inst = pmem_read(cpu_pc,4);
		uint8_t *s_inst = (uint8_t *)&inst;

		for(k = ilen - 1; k >= 0; k --){
			p += snprintf(p,4," %02x", s_inst[k]);
		}
		int space_len = 1;
		memset(p,' ',space_len);
		p += space_len;
		void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
		disassemble(p,logbuf + 128 - p,cpu_pc,(uint8_t *)&inst,ilen);
// ================== ITRACING ENDS ===========================

//difftest的关键
if(diff_so_file != NULL){
	difftest_step(cpu_pc);
}
//这里是ftrace的必要
		ftrace(logbuf);
//是否打印出反汇编的指令
		if(g_print_step){ printf("%s\n",logbuf);}
//反汇编写入日志文件
		log_write("%s\n",logbuf);
  //扫描监视点
    bool success = false;
    scan_watchpoints(&success);
}
