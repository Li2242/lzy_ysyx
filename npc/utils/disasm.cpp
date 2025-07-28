#include <dlfcn.h>
#include <capstone/capstone.h>
#include "common.h"

static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);

static csh handle;

//初始化反汇编
void init_disasm() {
  void *dl_handle;

  // 打开共享对象file并将其映射进来；返回一个句柄，可传递给 `dlsym` 以从中获取符号值。(符号对应的运行时地址)
  dl_handle = dlopen("tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  assert(dl_handle);

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  //查找共享对象中 handle 所指向的名为 name 的符号的运行时地址
  // cs_open_dl = dlsym(dl_handle, "cs_open");
	cs_open_dl = reinterpret_cast<cs_err (*)(cs_arch, cs_mode, csh*)>(dlsym(dl_handle, "cs_open"));
  assert(cs_open_dl);

  // cs_disasm_dl = dlsym(dl_handle, "cs_disasm");
	cs_disasm_dl = reinterpret_cast<size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**)>(dlsym(dl_handle, "cs_disasm"));
  assert(cs_disasm_dl);

  // cs_free_dl = dlsym(dl_handle, "cs_free");
	cs_free_dl = reinterpret_cast<void (*)(cs_insn*, size_t)>(dlsym(dl_handle, "cs_free"));
  assert(cs_free_dl);
    //架构
  cs_arch arch =  CS_ARCH_RISCV;

    //模式
  cs_mode mode = CS_MODE_RISCV32 ;
	int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);

}
//反汇编 与外界的接口
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
	cs_insn *insn;
	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  assert(count == 1);
  //这个应该是在写入riscv指令
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0') {
    //这是后面的操作数变量
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  cs_free_dl(insn, count);
}
