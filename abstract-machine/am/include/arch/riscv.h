#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

/*
虽然这块内存是“栈上的一块匿名区域”，但在 C 里我们把它的指针解释成了 Context*
，于是它就“被命名为 Context 了”。
*/
struct Context {
  // TODO: fix the order of these members to match trap.S
  uintptr_t  gpr[NR_REGS], mcause, mstatus, mepc;
  void *pdir;
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#endif
