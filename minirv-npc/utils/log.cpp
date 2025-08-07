#include "common.h"

FILE *log_fp = NULL;

void init_log() {
  //日志输出的目标设置为标准输出
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    if(log_file == NULL){
			red_printf("Can not open '%s'\n",log_file);
		}
    log_fp = fp;
  }
  green_printf("Log is written to %s\n", log_file ? log_file : "stdout");
}
