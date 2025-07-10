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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_N, TYPE_J// none
};

//src1R()和src2R()两个辅助宏, 用于寄存器的读取结果记录到相应的操作数变量中
#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
//immI等辅助宏, 用于从指令中抽取出立即数
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do {        \
  *imm = SEXT(             \
    (BITS(i,31,31)<<20) |  \
    (BITS(i,19,12)<<12) |  \
    (BITS(i,20,20)<<11) |  \
    (BITS(i,30,21)<<1),    \
  21) ;                 \
} while(0)

//首先统一对目标操作数进行寄存器操作数的译码, 即调用*rd = BITS(i, 11, 7), 不同的指令类型可以视情况使用rd
static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  //译码，操作数和操作码
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_N: break;
    case TYPE_J:                   immJ(); break;
    default: panic("unsupported type = %d", type);
  }
}

//译码
static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;
//INSTPAT_INST获取当前指令
#define INSTPAT_INST(s) ((s)->isa.inst)
//根据指令找出对应的操作数
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}
  //INSTPAT定义一条模式匹配规则.
  //INSTPAT(模式字符串, 指令名称, 指令类型, 指令执行操作);
  //指令名称：当注释使用，不参与宏展开
  //指令类型：用于后续译码过程
  //指令执行操作：则是通过C代码来模拟指令执行的真正行为
  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = imm + src1);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->dnpc+4 ; s->dnpc += imm);

  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm ,32, BITS(src2,31,0)));

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

//译码结果将记录到函数参数rd, src1, src2和imm中, 它们分别代表 目的操作数的寄存器号码, 两个源操作数 和 立即数.

  R(0) = 0; // reset $zero to 0

  return 0;
}


int isa_exec_once(Decode *s) {
  //1.取指
  //函数inst_fetch()(在nemu/include/cpu/ifetch.h中定义)专门负责取指令的工作
  //inst_fetch()最后还会根据len来更新s->snpc, 从而让s->snpc指向下一条指令
  s->isa.inst = inst_fetch(&s->snpc, 4);
  //2.译码
  return decode_exec(s);
}
