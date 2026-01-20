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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

//地址的转换
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
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

//越界处理（为了在npc里做镜像源注释掉了）
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
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

//读
word_t paddr_read(paddr_t addr, int len) {
  	if (likely(in_pmem(addr))){
	word_t temp = pmem_read(addr, len);
//mtrace
#ifdef CONFIG_MTRACE
	log_write("\t\tR  adder=0x%08x  size=%d  data=0x%08x\n",addr,len,temp);
#endif
    return temp;
}
	//不在nemu物理内存中，在设备中
	IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
	//越~界~喽~
	out_of_bound(addr);
	return 0;
}

//写
void paddr_write(paddr_t addr, int len, word_t data) {
	//是否在nemu物理内存中
  	if (likely(in_pmem(addr))){
		pmem_write(addr, len, data);
//mtrace
#ifdef CONFIG_MTRACE
		log_write("\t\tW  adder=0x%08x  size=%d  data=0x%08x\n",addr,len,data);
#endif
		return;
	}
  //不在nemu物理内存中，在设备中
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  //越~界~喽~
  out_of_bound(addr);
}
