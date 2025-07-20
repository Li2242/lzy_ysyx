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

#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

typedef struct watchpoint {
  //表示监视点的序号
  int NO;
  //记录的表达式
  char* s;
  //字符串的结果
  uint32_t n;
  //下一个监视点的地址
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

} WP;


word_t expr(char *e, bool *success);
int new_wp(char *str);
void free_wp(int n);
void scan_watchpoints(bool* success);
void scan();

#endif
