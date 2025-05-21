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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  //表示监视点的序号
  int NO;
  //下一个监视点的地址
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

} WP;

WP* new_wp();
void free_wp(WP *wp);

static WP wp_pool[NR_WP] = {};
//head用于组织使用中的监视点结构
//free_用于组织空闲的监视点结构
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  if(free_ == NULL) return NULL;

  WP *p = free_;
  free_ = free_->next;
  //把p加在了整个使用链表的头部
  p->next = head;
  head = p;

  return p;
  
}

void free_wp(WP *wp){
  if(wp == NULL) return;
  //从head中删除
  WP** pp = &head;
  while(*pp != NULL){
    //找到目标地址
    if(*pp == wp){
      //跳过目标地址
      /*假设我们有一个链表：A -> B -> C，现在要删除节点 B。
        第一次匹配失败
        现在是第二次
        pp 是指向 A.next 的指针
        *pp 就是 pp 所指向的内容，也就是 A.next 本身。
        pp = wp->next 相当于把 C 的地址赋值给 A.next
      */
      *pp = wp->next;
      break;
    }
    //pp是结构体中next的指针
    pp = &((*pp)->next);
  }

  //加入free_中
  wp->next = free_;
  free_ = wp;
}
