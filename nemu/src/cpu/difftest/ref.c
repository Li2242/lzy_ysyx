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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n) {
  int inst_num = n/4;
	uint32_t* img = (uint32_t *)buf;
	Log("准备写了！\n");
	for(int i =0;i<inst_num;i++){
		paddr_write(addr,4,*img++);
	}
}

//返回值是pc
__EXPORT uint32_t difftest_regcpy(void *dut, uint32_t pc, bool direction) {
	if(direction == DIFFTEST_TO_DUT){
		uint32_t* arr = (uint32_t*)dut;
		for(int i =0;i<32;i++)
			arr[i] = cpu.gpr[i];
		}
		return cpu.pc;

	if(direction == DIFFTEST_TO_REF){
		uint32_t* arr = (uint32_t*)dut;
		for(int i =0; i<32; i++){
			cpu.gpr[i] = arr[i] ;
		}
		cpu.pc = pc;
		return 0;
	}
	Log("你的条件多半传错了，一个选型都没有");
	return 0;
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init() {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
