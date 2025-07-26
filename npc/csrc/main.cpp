#include "common.h"


int simend = 0;
//verilog中的函数
extern unsigned int get_reg(int index);

extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  	simend = 1;
}
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
	};
//遍历寄存器
void reg_display(){
	 for(int i=0;i<32;i+=4){
    for(int k =i;k<i+4;k++){
				uint32_t temp_reg = get_reg(k);
        printf("%-3s: 0x%08x\t",regs[k],temp_reg);
      }
    printf("\n");
  }
  printf("pc : 0x%08x\n",top->pc);
}

//找对应的寄存器的值
uint32_t reg_str2val(char* name ){
	uint32_t reg_num;
	for(int i = 0;i<32;i++){
  //对比寄存器的名字
    if(strcmp(name,regs[i]) == 0){
      uint32_t reg_num = get_reg(i);
			return reg_num;
      break;
    }
  }
  //加的pc
  if(strcmp(name,"pc") == 0){
    reg_num = top->pc;
  }
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











