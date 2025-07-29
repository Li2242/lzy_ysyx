#include "common.h"
//镜像文件
static char *img_file = NULL;
//日志文件
char *log_file = NULL;
//elf文件
char *elf_file = NULL;
//difftest的镜像文件
char *diff_so_file = NULL;
//越界处理
static void out_of_bound(uint32_t addr);

//内置指令，为传入文件时的指令
static const __uint32_t memory[] = {
	0x00000413, //初始化
	0x0040a103, // lw x2, 4(x1)
	0x0000a083, // lw x1, 0(x1)
	0x0080a183, // lw x3, 8(x1)
	0x00c0a203, // lw x4, 12(x1)
	0x0100a283, // lw x5, 16(x1)
  0x06400093,  // 1: addi x1, x0, 100    (x1 = 0 + 100 = 100)
  0x00108113,  // 2: addi x2, x1, 1      (x2 = 100 + 1 = 101)
  0x00210193,  // 3: addi x3, x2, 2      (x3 = 101 + 2 = 103)
  0x00318213,  // 4: addi x4, x3, 3      (x4 = 103 + 3 = 106)
  0x00420293,  // 5: addi x5, x4, 4      (x5 = 106 + 4 = 110)
	0x00528333,  // 6: add x6, x5, x5      (x6 = 110 + 110 = 220)
	0x004303B3,  // 7: add x7, x6, x4      (x7 = 220 + 106 = 326)
	0x00338433,  // 8: add x8, x7, x3      (x8 = 326 + 103 = 429)
	0x002404B3,  // 9: add x9, x8, x2      (x9 = 429 + 101 = 530)
	0x00148533,  //10: add x10, x9, x1     (x10 = 530 + 100 = 630)
  0x00100073,
  0x00528313,  // 6: addi x6, x5, 5      (x6 = 110 + 5 = 115)
  0x00630393,  // 7: addi x7, x6, 6      (x7 = 115 + 6 = 121)
  0x00738413,  // 8: addi x8, x7, 7      (x8 = 121 + 7 = 128)
  0x00840493,  // 9: addi x9, x8, 8      (x9 = 128 + 8 = 136)
  0x00948513   // 10: addi x10, x9, 9    (x10 = 136 + 9 = 145)
};

//地址转换
uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - MBASE; }
//判断以什么形式读出
static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: red_printf("host_read中并不能读出这个长度\n"); assert(0);
  }
}

static inline void host_write(void *addr,int len, uint32_t data) {
	switch(len){
		case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
		default: red_printf("host_write中并不能写入这个长度\n"); assert(0);
	}
}

//从物理地址 addr 处读取长度为 len 的数据。
uint32_t pmem_read(uint32_t addr, int len) {
   if (in_pmem(addr) == 1){
		uint32_t ret = host_read(guest_to_host(addr),len);
		return ret;
	}
	out_of_bound(addr);
	return 0;
}

void pmem_write(uint32_t addr, int len, uint32_t data){
	if(in_pmem(addr) == 1){
		host_write(guest_to_host(addr), len, data);
	}
}

//越界处理
static void out_of_bound(uint32_t addr) {
  printf("\033[31mERROR = address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc =  0x%08x\033[0m\n",addr, MBASE, MBASE+MSIZE, top->pc);
	assert(0);
}

//解析参数
int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    //{长选项名称，是否需要参数，NULL，短选项名称}
    //长选项表的结束标志
		{"diff"     , required_argument, NULL, 'd'},
		{"elf"      , required_argument, NULL, 'e'},
		{"log"      , required_argument, NULL, 'l'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-l:e:d:", table, NULL)) != -1) {
    switch (o) {
			case 'd':diff_so_file = optarg;break;
			case 'e':elf_file = optarg;break;
			case 'l':log_file = optarg;break;
      case 1: img_file = optarg; return 0;
      default:
				printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
			 	printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
				printf("\t-e,--elf=FILE           Open the elf FILE\n");
				printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

//这个函数会将一个有意义的客户程序从镜像文件读入到内存, 覆盖刚才的内置客户程序.
long load_img() {
  if (img_file == NULL) {
		//写入内置程序


    memcpy(pmem,memory,sizeof(memory));
		uint32_t addr = MBASE;
		// for(int i =0;i<32;i++){
		// 	printf("pmem[%d] = 0x%08x\n",i,pmem_read(addr,4));
		// 	addr+=4;
		// }
    green_printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  assert(fp);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(pmem, size, 1, fp);
  assert(ret == 1);
  fclose(fp);
  return size;
}


//检查DUT和REF的寄存器是否相同（可以说是核心了）
bool difftest_checkregs(uint32_t *ref_r, uint32_t diff_pc) {
	bool is_same = true;
	for(int i = 0;i<32;i++){
		uint32_t temp = top->rootp->npc__DOT__u_regfile2__DOT__rf[i];
		if( temp != ref_r[i]){
			red_printf("Mismatch in '%s': dut=0x%08x, ref=0x%08x\n", regs[i], temp, ref_r[i]);
			is_same = false;
		}
	}
	if(top->pc != diff_pc){
		red_printf("Mismatch in pc: dut=0x%08x, ref=0x%08x\n", top->pc, diff_pc);
		is_same = false;
	}
  return is_same;
}
// ================= 这里是verilog中的DPI-C ====================
//停止指令
extern "C" void ebreak(uint32_t pc){
    printf("pc = 0x%x\n",pc);
  	npc_state = NPC_END;
}

extern "C" int v_pmem_read(uint32_t raddr){
	uint32_t addr = (raddr & ~0x3u) + 0x80000000;
	printf("0x%08x\n",addr);
	return pmem_read(addr,4);
}

extern "C" void v_pmem_write(int waddr, int wdata, char wmask){
	uint32_t addr = waddr & ~0x3u;
	uint32_t temp = pmem_read(addr, 4);
	if(wmask&0x1){temp = (temp & 0xFFFFFF00) | (wdata & 0x000000FF);}
	if(wmask&0x2){temp = (temp & 0xFFFF00FF) | (wdata & 0x0000FF00);}
	if(wmask&0x4){temp = (temp & 0xFF00FFFF) | (wdata & 0x00FF0000);}
	if(wmask&0x8){temp = (temp & 0x00FFFFFF) | (wdata & 0xFF000000);}
	pmem_write(addr, 4, temp);
}

// ====================   请在上面的范围内添加    =======================


// ====================      小工具        ========================
//颜色打印
void green_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    printf("\033[32m");
    vprintf(fmt, args);
    printf("\033[0m");

    va_end(args);
}

void red_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    printf("\033[30m");
    vprintf(fmt, args);
    printf("\033[0m");

    va_end(args);
}
