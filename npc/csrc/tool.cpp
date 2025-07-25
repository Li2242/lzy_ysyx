#include "common.h"

//判断以什么形式读出
inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default:assert(0);
  }
}

//从物理地址 addr 处读取长度为 len 的数据。
uint32_t pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host(addr),len);
  return ret;
}

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - MBASE; }
