#include "common.h"

static char *img_file = NULL;
static void out_of_bound(uint32_t addr);
//判断以什么形式读出
inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default:assert(0);
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

//地址转换
uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - MBASE; }


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
long load_img() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  assert(fp);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(pmem, size, 1, fp);
  assert(ret == 1);
  fclose(fp);
  return size;
}


void green_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    // 设置为绿色：\033[32m，恢复默认颜色：\033[0m
    printf("\033[32m");       // 设置颜色
    vprintf(fmt, args);       // 实际打印
    printf("\033[0m");        // 恢复默认

    va_end(args);
}
