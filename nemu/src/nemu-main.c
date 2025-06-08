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
 
  //测试

  //打开文件
   FILE *fp = fopen("/home/lzy14/ysyx/ysyx-workbench/nemu/tools/gen-expr/build/input","r");
   //确定打开了文件
  if(fp == NULL){
    perror("Failed to open file");  // 输出更详细的错误信息
    return 1;
  }

  char line[512]; //每行内容
  int line_num = 0;//行数
  //开始读文章了
  while(fgets(line,512,fp)!= NULL){
    line_num++;

    if(line[0] == '\n') continue;  // 跳过仅有换行符的行
    
    char *expression = strchr(line,' '); // 查找第一个空格位置
    
    // 检查格式是否合法
  if (expression == NULL) {
    printf("Invalid format in line %d: missing space separator\n", line_num);
    continue;
  }

    size_t len = expression - line; // 计算空格前的字符数（预期数值长度）
    if (len >= sizeof(line)) {   // 防止缓冲区溢出（sizeof(line)=512）
      printf("Line %d: number part too long\n", line_num);
      continue;
  }
    char temp[len+1];   // 临时数组存储预期数值字符串
    strncpy(temp,line,len); // 复制数值部分（最多len字节）
    temp[len] = '\0';       // 手动添加空终止符
    uint32_t num ;  
    sscanf(temp , "%u" , &num);  // 转换为整数
    
    if(expression == NULL){
      printf("Invida format in %d lien\n",line_num);
      continue;
    }

    expression = expression + 1;

    uint32_t str_len = strlen(expression); // 计算表达式长度

    if(str_len > 0 && expression[str_len - 1]=='\n'){
      expression[str_len - 1] = '\0'; // 将换行符替换为空终止符
    }
    if(str_len == 0) continue; // 表达式为空（如`"42  "`），跳过

    bool r = false ;
    printf("%s\n",expression);
    uint32_t result = expr(expression,&r);
    printf("result= %u\n",result);
    if(num == result){
      printf("The %d test is corrent!\n\n",line_num);
    }
  }

  fclose(fp);

  /* Start engine. */

  engine_start();
  
  return is_exit_status_bad();
}
