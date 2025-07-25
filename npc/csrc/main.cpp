#include "common.h"




int simend = 0;
//初始化内存
uint8_t pmem[MSIZE] = {};


//verilog中的函数
extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  simend = 1;
}





int main(int argc,char** argv) {
	//解析参数（现在的功能只有读入bin文件）
  parse_args(argc, argv);
	//初始化
  sim_init(argc,argv);
  //执行
  sim_exe();
	//结束
  sim_end();
  return 0;
}










//判断以什么形式读出
static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default:assert(0);
  }
}

//从物理地址 addr 处读取长度为 len 的数据。
static uint32_t pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host(addr),len);
  return ret;
}

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - MBASE; }
