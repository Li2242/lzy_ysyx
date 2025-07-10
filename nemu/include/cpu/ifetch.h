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

#ifndef __CPU_IFETCH_H__

#include <memory/vaddr.h>

//取指操作的本质只不过就是一次内存的访问
static inline uint32_t inst_fetch(vaddr_t *pc, int len) {
  //inst_fetch()最终会根据参数len来调用vaddr_ifetch()(在nemu/src/memory/vaddr.c中定义)
  //而目前vaddr_ifetch()又会通过paddr_read()来访问物理内存中的内容
  uint32_t inst = vaddr_ifetch(*pc, len);
  (*pc) += len;//根据len来更新s->snpc, 从而让s->snpc指向下一条指令
  return inst;
}

#endif
