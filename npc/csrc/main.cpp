#include "common.h"


int simend = 0;
//verilog中的函数
extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  simend = 1;
}





int main(int argc,char** argv) {
	//解析参数（现在的功能只有读入bin文件）
  parse_args(argc, argv);
	//初始化
  sim_init(argc,argv);
  //执行
  sim_exe();
	//结束
  sim_end();
  return 0;
}











