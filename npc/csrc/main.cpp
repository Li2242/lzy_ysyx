#include <stdio.h>
#include <getopt.h>
#include <verilated.h>
#include "Vnpc.h"
#include "verilated_vcd_c.h"


#define RESET_VECTOR 0x8000000
#define MSIZE 0x8000000

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static char *img_file = NULL;
static Vnpc* top;
int simend = 0;

static long load_img();
void sim_init(int argc,char** argv);
void sim_end();
void sim_exe();
__uint32_t pmem_read(__int32_t pc);
static int parse_args(int argc, char *argv[]);


extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  simend = 1;
}

//为传入文件时的指令
__uint32_t memory[MSIZE] = {
  0x06400093,  // 1: addi x1, x0, 100    (x1 = 0 + 100 = 100)
  0x00108113,  // 2: addi x2, x1, 1      (x2 = 100 + 1 = 101)
  0x00210193,  // 3: addi x3, x2, 2      (x3 = 101 + 2 = 103)
  0x00318213,  // 4: addi x4, x3, 3      (x4 = 103 + 3 = 106)
  0x00100073,
  0x00420293,  // 5: addi x5, x4, 4      (x5 = 106 + 4 = 110)
  0x00528313,  // 6: addi x6, x5, 5      (x6 = 110 + 5 = 115)
  0x00630393,  // 7: addi x7, x6, 6      (x7 = 115 + 6 = 121)
  0x00738413,  // 8: addi x8, x7, 7      (x8 = 121 + 7 = 128)
  0x00840493,  // 9: addi x9, x8, 8      (x9 = 128 + 8 = 136)
  0x00948513   // 10: addi x10, x9, 9    (x10 = 136 + 9 = 145)
};






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






//这个函数会将一个有意义的客户程序从镜像文件读入到内存, 覆盖刚才的内置客户程序.
static long load_img() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  assert(fp);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(memory, size, 1, fp);
  assert(ret == 1);
  fclose(fp);
  return size;
}

//读指令
__uint32_t pmem_read(__int32_t pc){
    __int32_t index = (pc - RESET_VECTOR) / 4;
    if (index < 0 || index >= MSIZE) {
        printf("Error: PC 0x%X out of memory range!\n", pc);
        exit(1);
    }
  return img_file[index];
}


//开始
void sim_init(int argc,char** argv){
    contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);
    Verilated::traceEverOn(true);
    top = new Vnpc;
    tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("waveform.vcd");
    // 1. 复位初始化
    top->clk = 0;
    top->rst = 0;
    top->pc = 0x80000000;
    long img_size = load_img();
    top->eval();
    tfp->dump(contextp->time()); // 记录复位前状态
    contextp->timeInc(10);
}

void sim_exe(){
    for(int i = 0; (i < RESET_VECTOR) && simend != 1 ; i++){
    top->clk = 0;
    top->inst = pmem_read(top->pc);
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

    top->clk = 1;
    top->eval();
    tfp->dump(contextp->time());    // 记录波形
    contextp->timeInc(5);

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


