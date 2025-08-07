//初始化文件
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
//解析elf文件需要的
#include <elf.h>
//仿真所需要的
#include <verilated.h>
#include "Vnpc.h"

#ifdef ENABLE_TRACE
	#include "verilated_vcd_c.h"
#endif

//访问寄存器
#include "Vnpc___024root.h"


//NPC状态
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };
//diff条件，准确来说是DUT和REF之间的传输方向
enum {DIFFTEST_TO_DUT, DIFFTEST_TO_REF};
//difftest函数
bool difftest_checkregs(uint32_t* ref , uint32_t pc);
void difftest_step(uint32_t pc);
//npc状态
extern int npc_state;

//仿真
extern VerilatedContext* contextp ;
#ifdef ENABLE_TRACE
	extern VerilatedVcdC* tfp ;
#endif
extern Vnpc* top;
//寄存器
extern const char *regs[];
//内存
#define MBASE 0x80000000
#define MSIZE 0x10000000
//内存
extern uint8_t pmem[MSIZE];

// calculate the length of an array
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

//写入日志功能
#define log_write(...) \
	do{ \
			extern FILE* log_fp;\
			if(log_fp != NULL){ \
				fprintf(log_fp,__VA_ARGS__); \
				fflush(log_fp); \
			} \
	} while(0)

// ================= FUNCTIONS =================
//解析参数
int parse_args(int argc, char *argv[]);
//加载镜像文件
long load_img();
//仿真三件套
void sim_init(int argc,char** argv);
void sim_exe(uint32_t n);
void sim_end();
//readline的主循环
void sdb_mainloop();
//表达式求值
int expr(char *e, bool *success);

//地址转换和从内存读出内容
uint32_t pmem_read(uint32_t addr, int len);
uint8_t* guest_to_host(uint32_t paddr);

//不同颜色的printf
void green_printf(const char *fmt, ...);
void red_printf(const char *fmt, ...);

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
//初始化difftest测试
void init_difftest(char *ref_so_file, long img_size);
//ftrace主逻辑
void ftrace(char* inst);
//批处理
void sdb_set_batch_mode();
//监视点
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
uint32_t reg_str2val_name(char* name);
uint32_t reg_str2val_num(int n);

// ============== 全局变量  ==============
//仿真记录
extern char *log_file;
//elf文件
extern char *elf_file;
//比对的镜像文件
extern char *diff_so_file;
//pc
extern uint32_t cpu_pc;

// ================= 这里是verilog中的DPI-C ====================
//停止指令
extern "C" void ebreak(uint32_t pc);
extern "C" int v_pmem_read(uint32_t raddr, int len);
extern "C" void v_pmem_write(int waddr, int wdata, char wmask);

// ==================  请在范围内添加    =========================

// device
extern uint8_t* new_space(int size);
extern void init_map();
extern void init_device();
//串口
extern void init_serial();
extern uint8_t *serial_base;
//时钟
extern void init_timer();
extern uint32_t *rtc_port_base;
extern uint64_t get_time();
extern void rtc_io_handler();
// //内存映射，寄存器的信息
// typedef struct {
// 	//名字
//   const char *name;
//   // we treat ioaddr_t as paddr_t here
// 	//起始地址
//   uint32_t low;
// 	//结束地址
//   uint32_t high;
// 	//映射的目标空间
//   void *space;
// 	//回调函数
// } IOMap;
