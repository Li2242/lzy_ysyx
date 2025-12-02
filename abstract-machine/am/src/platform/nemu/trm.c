#include <am.h>
#include <nemu.h>

extern char _heap_start;
int main(const char *args);
//用于指示堆区的起始和末尾，在linker.ld中
Area heap = RANGE(&_heap_start, PMEM_END);
//mainargs 将MAINARGS_PLACEHOLDER展开为其定义的字符串
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  nemu_trap(code);
  // should not reach here
  while (1);
}

void _trm_init() {
	//传入修改改过的mainargs
  	int ret = main(mainargs);
  	halt(ret);
}
