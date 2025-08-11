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

/*
	CSR				编号				作用
	mstatus		0x300				保存处理器状态
	mtvec			0x305				异常/中断入口地址
	mepc			0x341				触发异常的 PC
	mcause		0x342				异常/中断原因
	*/

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
  //  */
	cpu.csrs[0x41] = epc;
	cpu.csrs[0x42] = NO;
	// printf("mtvec = 0x%08x\n",cpu.csrs[5]);
  return cpu.csrs[0x5];
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
