#include <dlfcn.h>
#include "common.h"


void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n) = NULL;
uint32_t (*ref_difftest_regcpy)(void *dut, uint32_t pc, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;


void init_difftest(char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);

  //打开传入的动态库文件ref_so_file
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  //通过动态链接对动态库中的上述API符号进行符号解析和重定位, 返回它们的地址.
	//此时他们这几个变量就变成了函数
  ref_difftest_memcpy = (void (*)(uint32_t addr, void *buf, size_t n))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (uint32_t(*)(void *dut, uint32_t pc, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void(*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void(*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void(*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  green_printf("Differential testing: NO\n");
  green_printf("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.\n", ref_so_file);

	//将DUT的guest memory拷贝到REF中.
  ref_difftest_memcpy(MBASE, guest_to_host(MBASE), img_size);
	//将DUT的寄存器状态拷贝到REF中.
	void* temp = (void *)&(top->rootp->npc__DOT__u_regfile2__DOT__rf);
	//初始化寄存器和pc 此时还没有pc所以这边传的是MBASE
  ref_difftest_regcpy(temp , top->pc , DIFFTEST_TO_REF);
}

static void checkregs(uint32_t *ref, uint32_t diff_pc) {
	npc_state = NPC_ABORT;
  if (!difftest_checkregs(ref, diff_pc)) {
    reg_display();
  }
}

//可以进行逐条指令执行后的状态对比了
/*
	它会在cpu_exec()的主循环中被调用, 在NEMU中执行完一条指令后,
	就在difftest_step()中让REF执行相同的指令, 然后读出REF中的寄存器,
	并进行对比.
*/
void difftest_step(uint32_t pc) {
  uint32_t diff_reg[32] = {};
	uint32_t diff_pc;
  ref_difftest_exec(1);
  diff_pc = ref_difftest_regcpy(diff_reg , pc ,DIFFTEST_TO_DUT);
	printf("diff_pc=0x%08x\n",diff_pc);
  checkregs(diff_reg, diff_pc);
}

