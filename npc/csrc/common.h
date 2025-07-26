//初始化文件
#include <stdio.h>
#include <getopt.h>
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"
//访问寄存器
#include "Vnpc___024root.h"
#include <string.h>

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

//结束标志
extern int simend;

//函数
long load_img();
void sim_init(int argc,char** argv);
void sim_exe(uint32_t n);
void sim_end();
int parse_args(int argc, char *argv[]);
inline uint32_t host_read(void *addr, int len);
uint32_t pmem_read(uint32_t addr, int len);
uint8_t* guest_to_host(uint32_t paddr);
void sdb_mainloop();
void green_printf(const char *fmt, ...);
//表达式求值
int expr(char *e, bool *success);
//编译正则表达式
void init_regex();
//初始化监视点
void init_wp_pool();
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
