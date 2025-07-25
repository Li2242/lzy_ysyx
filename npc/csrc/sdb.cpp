#include "common.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

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
}


