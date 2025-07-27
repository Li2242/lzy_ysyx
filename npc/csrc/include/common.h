//初始化文件
#include <stdio.h>
#include <getopt.h>
#include <string.h>
//仿真所需要的
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"
#include <assert.h>
//解析elf文件需要的
#include <elf.h>

//NPC状态
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };
//npc状态
extern int npc_state;

//仿真
extern VerilatedContext* contextp ;
extern VerilatedVcdC* tfp ;
extern Vnpc* top;
//寄存器
extern const char *regs[];
//内存
#define MBASE 0x80000000
#define MSIZE 0x10000000
// calculate the length of an array
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
//内存
extern uint8_t pmem[MSIZE];

//函数
long load_img();
//仿真三件套
void sim_init(int argc,char** argv);
void sim_exe(uint32_t n);
void sim_end();
//解析参数，并且
int parse_args(int argc, char *argv[]);
inline uint32_t host_read(void *addr, int len);
uint32_t pmem_read(uint32_t addr, int len);
uint8_t* guest_to_host(uint32_t paddr);
void sdb_mainloop();
//不同颜色的printf
void green_printf(const char *fmt, ...);
void red_printf(const char *fmt, ...);
//表达式求值
int expr(char *e, bool *success);
// ===========    这里是初始化哦    ============
//编译正则表达式
void init_regex();
//初始化监视点
void init_wp_pool();
//初始化反汇编
void init_disasm();
//初始化log文件
void init_log();
//初始化elf文件
void init_elf();
//ftrace主逻辑
void ftrace(char* inst);

int new_wp(char *str);
void free_wp(int n);
void scan_watchpoints(bool* success);
void scan();
//判断是否在peme中
static inline bool in_pmem(uint32_t addr) {
  return addr - MBASE < MSIZE;
}
//打印寄存器
void reg_display();
uint32_t reg_str2val(char* name);

//仿真记录
extern char *log_file;
//elf文件
extern char *elf_file;
//比对的镜像文件
extern char *diff_so_file;

//写入功能
#define log_write(...) \
	do{ \
			extern FILE* log_fp;\
			if(log_fp != NULL){ \
				fprintf(log_fp,__VA_ARGS__); \
				fflush(log_fp); \
			} \
	} while(0)
