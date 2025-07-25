#include "common.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

//批处理模式
static int is_batch_mode = false;
//函数
static int cmd_c  (char *args);
static int cmd_q  (char *args);
static int cmd_si (char *args);
static int cmd_x  (char *args);
static int cmd_info (char* args);
//help
static int cmd_help(char *args);


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




static struct{
	const char* name;
	const char* description;
	int(*handler)(char *);
}cmd_table[] = {
	{ "help", "Display information about all supported commands", cmd_help },
	{ "c", "Continue the execution of the program", cmd_c },
	{ "q", "Exit NPC", cmd_q },
	{ "si", "Step execution",cmd_si},
	{ "x", "Scan memory", cmd_x},
	{ "info", "Print the program status", cmd_info}
};

#define NR_CMD ARRLEN(cmd_table)

//批处理模式
void sdb_set_batch_mode() {
  is_batch_mode = true;
}

//npc主循环
void sdb_mainloop(){
	//批处理模式
	if(is_batch_mode){
		cmd_c(NULL);
		return;
	}
	//循环
	for(char *str;(str = rl_gets()) != NULL; ){
		char *str_end = str+strlen(str);
		//这里是首次发出对输入命令的切割
		char *cmd = strtok(str," ");
		if(cmd == NULL){continue;}

		char *args = cmd + strlen(cmd) + 1;

		if(args >= str_end){
			args = NULL;
		}
		int i;
		for(i =0; i < NR_CMD ;i++){
			if(strcmp(cmd,cmd_table[i].name) == 0){
				if(cmd_table[i].handler(args) < 0){return;}
				break;
			}
		}
		if(i == NR_CMD){printf("Unkonwn command '%s'\n",cmd);}
	}
}

static int cmd_help(char* str){
	char* arg = strtok(NULL," ");
	int i;
	if(arg == NULL){
		for(i = 0;i<NR_CMD;i++){
			printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
		}
	}else{
		for(i = 0; i<NR_CMD;i++){
			if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
		}
		printf("Unknown command '%s'\n", arg);
	}
	return 0;
}
//执行完程序
static int cmd_c(char *args){
	sim_exe(-1);
	return 0;
}

//退出
static int cmd_q(char *args){
		return -1;
}

//单步执行
static int cmd_si(char *args){
	char* arg = strtok(NULL," ");
	if(arg == NULL){
		sim_exe(1);
		return 0;
	}
	int n;
	sscanf(arg,"%d",&n);
	if(n<=0){
		printf("请输入大于0的执行次数\n");
		return 0;
	}
	sim_exe(n);
	return 0;
}
//扫描内存
static int cmd_x(char *args){
	char *arg[2];
	arg[0] = strtok(NULL," ");
	arg[1] = strtok(NULL," ");
	// printf("arg[0] = %s arg[1]=%s\n",arg[0],arg[1]);
	if(arg[0] == NULL || arg[1]==NULL){
		printf("请输入两个参数:长度 从哪里开始]\n");
		return 0;
	}
	int n ;
	sscanf(arg[0],"%d", &n);
	// printf("n = %d\n",n);
	if(n<=0){
		printf("请输入大于零的次数哦！\n");
	}
	uint32_t addr;
	sscanf(arg[1],"%x",&addr);
	// printf("addr = 0x%08x\n",addr);
	for(int i =0;i < n;i++){
		printf("addr = 0x%08x: 0x%08x\n",addr,pmem_read(addr,4));
		addr += 4;
	}
	return 0;
}

static int cmd_info(char* args){
	char *arg = strtok(NULL," ");
	if(arg == NULL){
		printf("请输入一个参数\n");
		return 0;
	}
	if(*arg == 'r'){
		top->info_r = 1;
		top->eval();
	}
	return 0;
}
