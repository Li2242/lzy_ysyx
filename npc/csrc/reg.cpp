#include "common.h"

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
				uint32_t temp_reg = top->rootp->npc__DOT__u_regfile2__DOT__rf[k];
        printf("%-3s: 0x%08x\t",regs[k],temp_reg);
      }
    printf("\n");
  }
  printf("pc : 0x%08x\n",top->pc);
}

//找对应的寄存器的值
uint32_t reg_str2val(char* name){
	uint32_t reg_num;
	for(int i = 0;i<32;i++){
  //对比寄存器的名字
    if(strcmp(name,regs[i]) == 0){
      uint32_t reg_num = top->rootp->npc__DOT__u_regfile2__DOT__rf[i];
      break;
    }
  }
  //加的pc
  if(strcmp(name,"pc") == 0){
    reg_num = top->pc;
  }
	return reg_num;
}
