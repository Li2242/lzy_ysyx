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
#include <string.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
//已经不知道自己为什么加上它了，好像删去也没事
// #include </home/lzy14/ysyx/ysyx-workbench/nemu/include/memory/host.h>
//为了读取客户端内存加的头文件
#include </home/lzy14/ysyx/ysyx-workbench/nemu/include/memory/vaddr.h>


static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
//使用 readline 函数从标准输入读取用户输入的一行命令，如果不为空,将其添加到历史记录中
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

//继续程序的执行c
static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

//退出调试器q
static int cmd_q(char *args) {
  return -1;
}

//单步执行si
static int cmd_si(char *args){

  char *arg = strtok(NULL, " ");

  //不给参数默认执行一次
  if(args==NULL){
    cpu_exec(1);
  }else{
    //执行几次
    uint32_t n;
    //用了刚刚讲过的sscanf
    sscanf(arg , "%u" , &n);
    //int n = atoi(arg);(这是问AI的不合适)
    if(n<=0){
        printf("ERROR!!!\n");
        return 1;
    }
    cpu_exec(n);
  }
    return 0;
  }

//x 扫描内存
static int cmd_x(char *args);
//help
static int cmd_help(char *args);
//info 打印
static int cmd_info(char *args);
//p 表达式的值
static int cmd_p(char *args);
//w 
static int cmd_w(char *args);
//d 删除间断点
static int cmd_d(char *args);
//表达式测试
static int  cmd_test();

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  {"si", "Step execution",cmd_si},
  {"info", "Print the program status",cmd_info},
  {"x", "Scan memory",cmd_x},
  {"p", "Expression evaluation",cmd_p},
  {"w", "Set watchpoint",cmd_w},
  {"d", "Delete watchpoint",cmd_d},
  {"t", "Expression testing",cmd_test}
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)


//t
static int cmd_test(){
  FILE *fp = fopen("/home/lzy14/ysyx/ysyx-workbench/nemu/tools/gen-expr/build/input","r");
  if(fp == NULL){
    perror("Failed to open file");
    return 1;
  }
  char line[512];
  int line_num = 0;
  while(fgets(line,512,fp) != NULL){
    line_num++;
    if(line[0] == '\n') continue;
    char *expression = strchr(line,' ');
    if(expression == NULL){
      printf("Invalid format in line %d:missing sapce separator\n",line_num);
    }
    uint32_t len = expression - line;
    if(len >= sizeof(line)){
      printf("Line %d: number part too long\n",line_num);
      continue;
    }
    char temp[len+1];
    strncpy(temp,line,len);
    temp[len] = '\0';
    uint32_t num;
    sscanf(temp,"%u",&num);

    expression = expression+1;

    //输出表达式
    printf("%s\n",expression);

    uint32_t str_len = strlen(expression);
    if(expression[str_len-1] == '\n'){
      expression[str_len - 1] = '\0';
    }
    if(str_len <= 0){
      continue;
    }

    bool r = true;
    uint32_t result =  expr(expression,&r);
    if(r == false){
      printf("Evaluation failed in the expression test!\n");
    }
    if(result == num){
      printf("The %d test is corrent!\n",line_num);
    }
  }
  fclose(fp);
  return 0;
}

//w
static int cmd_w(char *args){
  char* w_arg =  args;
  new_wp(w_arg);
  return 0;
}

//d
static int cmd_d(char *args){
  uint32_t num ;
  sscanf(args,"%u",&num);
  free_wp(num);
  return 0;
}


//p
static int cmd_p(char *args){
  //提取出参数；因为后面的表达式可能有空格所以直接使用，不用strtok进行分割
  char* arg =args;
  bool success = true;
  uint32_t result = expr(arg,&success);
   if (success) {
    printf("表达式结果：%u\n", result);
  } else {
    printf("表达式求值失败\n");
  }
  return 0;
}

                
//x 扫描内存
/*
  在客户程序运行的过程中, 总是使用`vaddr_read()`和`vaddr_write()` 
  (在`nemu/src/memory/vaddr.c`中定义)来访问模拟的内存. 
*/
static int cmd_x(char *args){
  char *arg[2];
  arg[0] = strtok(NULL," "); 
  arg[1] = strtok(NULL,""); 
  bool success = true;
  //计算表达式的结果作为起始地址
  uint32_t addr = expr(arg[1],&success);
  printf("addr:0x%08x\n",addr);
  //检验参数是否齐全
  if(arg[0] == NULL||arg[1] == NULL){
    printf("Usage:command arg1 arg2\n");
    return 1;
  }

  //次数
  uint32_t n;
  sscanf(arg[0],"%u",&n);

  //int n = atoi(arg[0]);
  //之前直接写地址的时候的值
  //addr = strtoul(arg[1],NULL,16);

  if(n<=0){
    printf("Length must be a positive integer.\n");
    return 1;
  }else{
    for(int i = 0; i<n;){
      printf("0x%08x: ",addr);
      for(int k=0;k<4;k++){
        printf("0x%08x ",vaddr_read(addr,4));
        addr += 4;
        i++;
        if(i>=n) break;
      }
      printf("\n");
    }
  }
  return 0;
}


//info r 打印程序状态
static int cmd_info(char* args){
  char *arg = strtok(NULL, " ");

  if (arg == NULL) {
    printf("Usage: info <subcommand>\n");
  }else if (*arg == 'r'){
    isa_reg_display();
  }else if (*arg == 'w'){
    scan();
  }else{
    printf("subcommand error!!!\n");
  }
  return 0;
}


//help
static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
