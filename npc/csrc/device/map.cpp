
#include "common.h"
//最大内存
#define IO_SPACE_MAX (32 * 1024 * 1024)

#define PAGE_SHIFT        12
//页的大小2的12次方=4096 字节
#define PAGE_SIZE         (1ul << PAGE_SHIFT)
//PAGE_MASK = 0xFFF 表示页内偏移掩码（低 12 位是页内偏移）
#define PAGE_MASK         (PAGE_SIZE - 1)

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

//分配内存（以页为单位）
uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  // page aligned; 页对齐(这个处理对齐的思路好，可以学习)
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

//初始化映射内存
void init_map() {
  io_space = malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}


