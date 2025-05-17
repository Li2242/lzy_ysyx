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

#include <common.h>
#include "/home/lzy14/ysyx/ysyx-workbench/nemu/src/monitor/sdb/sdb.h"

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {


   
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
 
  /* Start engine. */
  
  //测试
   printf("GO!开始了哦！！！\n");
   FILE *fp = fopen("/home/lzy14/ysyx/ysyx-workbench/nemu/tools/gen-expr/build/input","r");
  if(fp == NULL){
    printf("ERROR!");
    return 1;
  }
  printf("打开文件了\n");
  char line[32];
  while(fgets(line,32,fp)!=NULL){
    char *expression = strchr(line,' ');
    if(expression == NULL){
      printf("Invida format!");
      return 1;
    }
    expression = expression + 1;
    uint32_t str_len = strlen(expression);
    if(str_len > 0&&expression[str_len - 1]=='\n'){
      expression[str_len - 1] = '\0';
    }
    bool *r = false;
    printf("进入expr前\n");
    uint32_t result = expr(expression,r);
    printf("%d\n result=%u",*r,result);
  }
  fclose(fp);

  engine_start();
  
  
  return is_exit_status_bad();
}
