#include "common.h"





int simend = 0;
//初始化内存




//verilog中的函数
extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  simend = 1;
}

extern "C" void halt(){
	top->inst = 0x00100073;
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



//解析参数
static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    //{长选项名称，是否需要参数，NULL，短选项名称}
    //长选项表的结束标志
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-", table, NULL)) != -1) {
    switch (o) {
      case 1: img_file = optarg; return 0;
      default:
        printf("\n");
        exit(0);
    }
  }
  return 0;
}







void sim_exe(){
    for(int i = 0; (i < MSIZE) && simend != 1 ; i++){
    top->clk = 0;
    top->inst = pmem_read(top->pc,4);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);
        //结束
      if(simend == 1){
        printf("ebreak指令在地址 0x%X 处被执行\n", top->pc);

        break;
      }

    printf( "result = %d pc = %x\n",top->alu_result,top->pc);
  }
}


//结束
void sim_end(){
  tfp->close();
  delete top;
  delete tfp;
  delete contextp;
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
