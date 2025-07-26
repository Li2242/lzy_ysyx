#include "common.h"

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


int new_wp(char *str);
void free_wp(int n);
void scan_watchpoints(bool* success);
void scan();
