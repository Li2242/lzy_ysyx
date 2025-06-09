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


WP* new_wp(char* s);
void free_wp(int n);

static WP wp_pool[NR_WP] = {};
//head用于组织使用中的监视点结构
//free_用于组织空闲的监视点结构
/*
  所以其实head和free都是链表的开头，他们根据next连成了一串
*/
static WP *head = NULL, *free_ = NULL;

//对两个链表进行初始化
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
WP* new_wp(char *str){
  //先看看以后没有空闲的了
  if(free_ == NULL) assert(0);

  WP *p = free_;
  //free往前挪动了一位
  free_ = free_->next;
  //把p加在了整个使用链表的头部
  //p往后挪动了一位
  p->next = head;
  //head改为新分配过来的
  head = p;
  //使用strup是为了防止被readline给free掉
  p->s = strdup(str);

  bool success = true;
  uint32_t a = expr(p->s,&success);
  if(success == false){
    printf("new_up中求值失败\n");
  }
  p->n = a;
  return p;
}

void free_wp(int n){
  if (n<0) {
    printf("请给出正确的消除序号\n");
    return;
  }

  //从head中删除
  WP** pp = &head;
  while(*pp != NULL){
    //找到目标地址
    if((*pp)->NO == n){
      //跳过目标地址
      /*假设我们有一个链表：A -> B -> C，现在要删除节点 B。
        第一次匹配失败
        现在是第二次
        pp 是指向 A.next 的指针
        *pp 就是 pp 所指向的内容，也就是 A.next 本身。
        pp = wp->next 相当于把 C 的地址赋值给 A.next
      */
        WP *wp = *pp;
        *pp = wp->next;
        //加入free_中
        wp->next = free_;
        free_ = wp;
        return;
    }
    //pp是结构体中next的指针
    pp = &((*pp)->next);
  }
  // 未找到对应监视点
    printf("错误：未找到序号为 %d 的监视点\n", n);
}

//扫描监视点
void scan_watchpoints(bool* success){
  WP *wp = head;
  while(wp!=NULL){
    bool success0 = true;
    uint32_t a = expr(wp->s,&success0);
    if(success0 == false){
      printf("在扫描监视点中 求值失败！\n");
      wp = wp->next;
      return;
    }
    if(a != wp->n){
      //这里的输出的值也修改了，从16进制到10 6.7
      printf("触发监视点 %d: %s 的值从 0x%08x 变为 0x%08x\n",wp->NO, wp->s, wp->n,a);
      wp->n = a;
      *success = true;
    }
    wp = wp->next;
  }
  if(*success){
      //你需要将nemu_state.state变量设置为NEMU_STOP来达到暂停的效果
      nemu_state.state = NEMU_STOP;
  }
}

void scan(){
  WP *wp = head;
    //是否有监视点被触发
    while(wp!=NULL){
      //这个值修改了6.7
        printf("监视点 %d: %s 的值 0x%08x\n",wp->NO, wp->s,wp->n );
        wp = wp->next;
    }
    if(wp == NULL){
      printf("The watchpoint was not scanned!\n");
    }
    
    return;
}