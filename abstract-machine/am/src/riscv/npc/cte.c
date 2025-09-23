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
				ev.event = EVENT_YIELD; break; 
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
 //uintptr_t 是一种无符号整型，保证足够大能存放一个指针的整数类型。(也是为了做字节单位减法)
	//给Context划分内存
	uintptr_t sp = (uintptr_t)kstack.end; //从高
	sp -= sizeof(Context);                //到低
	//.你需要在kstack的底部创建一个以entry为入口的上下文结构
	Context* c = (Context *)sp;

	c->mepc = (uintptr_t)entry;
	// 如果需要传递参数给entry函数，可以放在a0寄存器(c->gpr[10])里（RISC-V约定）
	c->gpr[10] = (uintptr_t)arg;
  return c;
}

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
