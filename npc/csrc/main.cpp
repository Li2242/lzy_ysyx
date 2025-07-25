#include "common.h"


int simend = 0;
//verilog中的函数
extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  	simend = 1;
}
//遍历寄存器
extern "C" void isa_reg_display(const svLogicVecVal *rf_data){
	const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
	};
	 for(int i=0;i<32;i+=4){
    for(int k =i;k<i+4;k++){
        printf("%-3s: 0x%08x\t",regs[k],rf_data[k].aval);
      }
    printf("\n");
  }
  printf("pc : 0x%08x\n",top->pc);
	top->info_r = 0;
}

//找对应的寄存器的值
extern "C" void isa_reg_str2val(const svLogicVecVal *rf_data){
	const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
	};

	for(int i = 0;i<32;i++){
  //对比寄存器的名字
    if(strcmp(reg_name,regs[i]) == 0){
			printf("找到了！！\n");
      reg_num = rf_data[i].aval;
      break;
    }
  }
  //加的pc
  if(strcmp(reg_name,"pc") == 0){
    reg_num = top->pc;
  }
	top->info_r = 0;
}



int main(int argc,char** argv) {
	//解析参数（现在的功能只有读入bin文件）
  parse_args(argc, argv);
	//初始化
  sim_init(argc,argv);
  //执行
  sdb_mainloop();
	//结束
  sim_end();
  return 0;
}











