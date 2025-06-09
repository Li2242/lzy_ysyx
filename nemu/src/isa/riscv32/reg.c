/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "local-include/reg.h"


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  for(int i=0;i<32;i+=4){
    //寄存器在cpu-exec.c中
    /*
      并在nemu/src/cpu/cpu-exec.c中定义一个全局变量cpu
      初始化寄存器的一个重要工作就是设置cpu.pc的初值
      PC和通用寄存器都在nemu/src/isa/$ISA/include/isa-def.h中的
      结构体中定义
    */
    for(int k =i;k<i+4;k++){
        printf("%-3s: 0x%08x\t",regs[k],cpu.gpr[k]);
      }
    printf("\n");
  }
  printf("pc=0x%08x\n",cpu.pc);
}

//获取寄存器的值
word_t isa_reg_str2val(const char *s, bool *success) {
  if(*s == '$'){
    s++;
  }
  for(int i = 0;i<32;i++){
    //对比寄存器的名字
    if(strcmp(s,regs[i]) == 0){
      *success = true;
      return cpu.gpr[i];
    }
  }
  return 0;
}
