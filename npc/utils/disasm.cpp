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
	// 从地址处动态加载一个共享库
	dl_handle = dlopen("/home/lzy14/ysyx-workbench/nemu/tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
	assert(dl_handle);
	  
	cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
	// reinterpret_cast 强制类型转换 用于将一个指针或引用重新解释
	// dlsym 查找共享对象中 handle 所指向的名为 name 的符号的运行时地址
	void* func_ptr1 = dlsym(dl_handle, "cs_open");
	cs_open_dl = reinterpret_cast<cs_err (*)(cs_arch, cs_mode, csh*)>(func_ptr1);
  	assert(cs_open_dl);

  	void* func_ptr2 = dlsym(dl_handle, "cs_disasm");
  	assert(func_ptr2);
	cs_disasm_dl = reinterpret_cast<size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**)>(func_ptr2);

	void *func_ptr3 = dlsym(dl_handle, "cs_free");
	assert(func_ptr3);
	cs_free_dl = reinterpret_cast<void(*)(cs_insn*, size_t)>(func_ptr3);

    //架构
  	cs_arch arch =  CS_ARCH_RISCV;
    //模式
  	cs_mode mode = CS_MODE_RISCV32 ;
	//返回反汇编器的句柄
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
