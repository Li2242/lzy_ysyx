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
#include <cpu/difftest.h>
#include "../local-include/reg.h"
/*
    把通用寄存器和PC与从DUT中读出的寄存器的值进行比较.
  	若对比结果一致, 函数返回true; 如果发现值不一样, 函数返回false

		特别地, isa_difftest_checkregs()对比结果不一致时,
		第二个参数pc应指向导致对比结果不一致的指令, 可用于打印提示信息
*/
bool is_same = true;
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
	for(int i = 0;i<32;i++){
		if(cpu.gpr[i] != ref_r->gpr[i]){
			Log("Mismatch in gpr[%d]: dut=0x%08x, ref=0x%08x\n", i, cpu.gpr[i], ref_r->gpr[i]);
			is_same = false;
		}
	}
	if(cpu.pc != ref_r->pc){
		Log("Mismatch in pc: dut=0x%08x, ref=0x%08x\n", cpu.pc, pc);
		is_same = false;
	}
  return is_same;
}

void isa_difftest_attach() {
}
