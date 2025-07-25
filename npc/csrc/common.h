//初始化文件
#include <stdio.h>
#include <getopt.h>
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"


#define MBASE 0x80000000
#define MSIZE 0x10000000

extern uint8_t pmem[MSIZE] = {};

//函数
static long load_img();
void sim_init(int argc,char** argv);
void sim_exe();
void sim_end();
__uint32_t pmem_read(__int32_t pc);
static int parse_args(int argc, char *argv[]);
static inline uint32_t host_read(void *addr, int len);
static uint32_t pmem_read(uint32_t addr, int len);
uint8_t* guest_to_host(uint32_t paddr);
