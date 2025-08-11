#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>


static Context* (*user_handler)(Event, Context*) = NULL;

/*
参数 Context *c 通过 a0 寄存器传递
汇编调用前，把上下文指针放进 a0
直接用 call 指令调用，函数用 a0 取参数
*/


Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
		// printf("=====================\n");
// //   uintptr_t  mcause, mstatus, mepc, gpr[NR_REGS];
		// printf("mcause = %x, mstatus=%x, mepc=0x%x\n",c->mcause,c->mstatus,c->mepc);
		// int j = 0;
		// for(int i =0;i<32;i++){
		// 	printf("gpr[%d]=0x%x    \t",i,c->gpr[i]);
		// 	j++;
		// 	if(j==4){
		// 		j = 0;
		// 		printf("\n");
		// 	}
		// }
    switch (c->mcause) {
			case 1: ev.event = EVENT_YIELD; break; 
      default:ev.event = EVENT_ERROR; break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

//用于进行CTE相关的初始化操作. 
// initialize exception entry
bool cte_init(Context*(*handler)(Event, Context*)) {
	//把 __am_asm_trap 的地址写到 mtvec 里
	// 直接将异常入口地址设置到mtvec寄存器中即可.
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
	// user_handler 是一个全局变量，用来存储用户提供的 handler 函数。
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
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
