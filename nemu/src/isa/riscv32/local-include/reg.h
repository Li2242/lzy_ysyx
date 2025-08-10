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

#ifndef __RISCV_REG_H__
#define __RISCV_REG_H__

#include <common.h>

//在运行时检查传入寄存器编号是否在合法范围内。
static inline int check_reg_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
  return idx;
}

static inline int check_csrs_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < 80));
  return idx;
}

//这都对外的gpr，那我之前cpu.gpr[i]岂不是特别小丑
#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])
#define csrs(idx) (cpu.csrs[check_csrs_idx((idx & 0xFFF) - 0x300)])
//这还有个传入编号返回名字的，我太小丑了
static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif
