#include "common.h"

//当前的pc,我需要他和top->pc区分开
uint32_t cpu_pc = 0;

extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  	npc_state = NPC_END;
}

int main(int argc,char** argv) {
	//解析参数(现在的功能只有读入bin文件)
  parse_args(argc, argv);
	//初始化
  sim_init(argc,argv);
  //执行
  sdb_mainloop();
	//结束
  sim_end();
  return 0;
}











