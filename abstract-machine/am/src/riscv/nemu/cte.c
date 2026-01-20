#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>


static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  	if (user_handler) {
		Event ev = {0};
		switch (c->mcause) {
			//这是在处理自限指令 因此软件需要在适当的地方对保存的PC加上4
			case 9:
			case 8:
			case 11: 
				c->mepc += 4;
				ev.event = EVENT_YIELD;
				break; 
			default:ev.event = EVENT_ERROR; break;
		}
		c = user_handler(ev, c);
		assert(c != NULL);
	}
  return c;
}

extern void __am_asm_trap(void);


// initialize exception entry
bool cte_init(Context*(*handler)(Event, Context*)) {
	//把 __am_asm_trap 的地址写到 mtvec 里
	//直接将异常入口地址设置到mtvec寄存器中即可.
  	asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  	// register event handler
  	user_handler = handler;

	return true;
}

//kcontext只能在栈上放置一个上下文结构
//kstack 栈的范围
//entry  内核线程入口(内核线程不能从entry返回)
//arg    内核线程参数
Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
	//uintptr_t 是一种无符号整型，保证足够大能存放一个内存地址
	//给Context划分内存
	uintptr_t sp = (uintptr_t)kstack.end; //从高
	sp -= sizeof(Context);                //到低
	//结构体指针 -> 结构体的低地址
	Context* c = (Context *)sp;

	c->mepc = (uintptr_t)entry;
	// 传参给entry,放在a0中
	c->gpr[10] = (uintptr_t)arg;
  return c;
}

//用于进行自陷操作, 会触发一个编号为EVENT_YIELD事件. 
void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
