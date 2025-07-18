/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/
/*
  主机地址：用于标识和访问内存位置的地址。它是相对于主机系统而言的，主机系统可以是物理机，也可以是运行在虚拟机管理程序之上的虚拟机。主机地址是程序在运行时实际使用的地址，操作系统会根据这个地址来进行内存的读写操作。

  物理地址：物理地址是指计算机硬件（如内存芯片）中实际存储数据的地址。它直接对应着内存模块中的某个物理存储单元，是硬件层面上的地址。在计算机系统中，物理地址是由硬件电路来识别和访问的。

  关系：主机地址和物理地址之间通常需要进行转换。这种转换是由内存管理单元（MMU）来完成的，主要通过页表等机制实现。主机地址经过 MMU 的转换后，会得到对应的物理地址，然后 CPU 才能根据这个物理地址来访问内存。
*/




#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif
//将物理地址 paddr 转换为主机地址。
//地址映射 例如如果mips32的CPU打算访问内存地址0x80000000, 我们会让它最终访问pmem[0]
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
//将主机地址 haddr 转换为客户机地址。
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

//从物理地址 addr 处读取长度为 len 的数据。
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

//将数据 data 写入到物理地址 addr 处，长度为 len。
static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

//越界处理
static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

//内存初始化函数
void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
    //把0x80000000前面的地址都初始化掉，从0x80000000开始是我们要设置的内存
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

//读
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) {
		word_t temp = pmem_read(addr, len);
		//mtrace
		#ifdef CONFIG_MTRACE
			log_write("R  adder=0x%08x  size=%d  data=0x%08x\n",addr,len,temp);
		#endif
    return temp;
  }
  //先不管
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  //是否越界
  out_of_bound(addr);
  return 0;
}
//写
void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
		pmem_write(addr, len, data);
		//mtrace
		#ifdef CONFIG_MTRACE
			log_write("W  adder=0x%08x  size=%d  data=0x%08x\n",addr,len,data);
		#endif

		return;
		}
  //先不管
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  //是否越界
  out_of_bound(addr);
}
