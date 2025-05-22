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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include </home/lzy14/ysyx/ysyx-workbench/nemu/include/memory/host.h>
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

//单步si
static int cmd_si(char *args){
  char *arg = strtok(NULL, " ");
  
  if(args==NULL){
    cpu_exec(1);
  }else{
    int n = atoi(arg);
    if(n<=0){
        printf("ERROR!!!\n");
        return 1;
    }
    cpu_exec(n);
  }
    return 0;
  }

//x
static int cmd_x(char *args);
//help
static int cmd_help(char *args);
//info
static int cmd_info(char *args);
//p
static int cmd_p();

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
  //{"w", "Set watchpoint",},
  //{"d", "Delete watchpoint",}
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

//p
static int cmd_p(char *args){
  //提取出第一个参数；
  char* arg =strtok(NULL," ");
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
static int cmd_x(char *args){
  char *arg[2];
  arg[0] = strtok(NULL," "); 
  arg[1] = strtok(NULL," "); 
  uint32_t addr;
  //检验参数是否齐全
  if(arg[0] == NULL||arg[1] == NULL){
    printf("Usage:command arg1 arg2\n");
  }
  //次数
  int n = atoi(arg[0]);
  //将地址字符串转换为16进制的无符号数
  addr = strtoul(arg[1],NULL,16);

  if(n<=0){
    printf("Length must be a positive integer.\n");
    return 1;
  }else{
    for(int i = 0; i<n; i ++){
          printf("0x%08x\n",vaddr_read(addr,4));
          addr += 4;
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
