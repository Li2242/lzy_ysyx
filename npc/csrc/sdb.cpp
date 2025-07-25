#include "common.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

//批处理模式
static int is_batch_mode = false;

//使用 readline 函数从标准输入读取用户输入的一行命令，如果不为空,将其添加到历史记录中
//并返回给调用的参数
static char* rl_gets(){
	static char *line_read = NULL;

	if(line_read){
		free(line_read);
		line_read = NULL;
	}
	line_read = readline("(npc) ");
	if(line_read && *line_read){
		add_history(line_read);
	}
	return line_read;
}

static int cmd_c(char *args){
	sim_exe(-1);
	return 0;
}

static int cmd_q(char *args){
		return -1;
}

//help
static int cmd_help(char *args);

static struct{
	const char* name;
	const char* description;
	int(*handler)(char *);
}cmd_table[] = {
	{ "help", "Display information about all supported commands", cmd_help },
	{ "c", "Continue the execution of the program", cmd_c },
	{ "q", "Exit NPC", cmd_q }
};

#define NR_CMD ARRLEN(cmd_table)

//批处理模式
void sdb_set_batch_mode() {
  is_batch_mode = true;
}
//npc主循环
void sdb_mainloop(){
	if(is_batch_mode){
		cmd_c(NULL);
		return;
	}

	for(char *str;(str = rl_gets()) != NULL; ){
		char *str_end = str+strlen(str);

		char *cmd = strtok(str," ");
		if(cmd == NULL){continue;}

		char *args = cmd + strlen(cmd) + 1;

		if(args >= str_end){
			args = NULL;
		}
		int i;
		for(i =0; i < NR_CMD ;i++){
			if(strcmp(cmd,cmd_table[i].handler(args)) < 0){return;}
			break;
		}
		if(i == NR_CMD){printf("Unkonwn command '%s'\n",cmd);}
	}
}


