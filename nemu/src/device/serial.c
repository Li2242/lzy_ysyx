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

#include <utils.h>
#include <device/map.h>

/* http://en.wikibooks.org/wiki/Serial_Programming/8250_UART_Programming */
// NOTE: this is compatible to 16550


//模拟了串口的功能

//串口的寄存器偏移地址
#define CH_OFFSET 0

//串口的大小
static uint8_t *serial_base = NULL;

//串口输出
static void serial_putc(char ch) {
  MUXDEF(CONFIG_TARGET_AM, putch(ch), putc(ch, stderr));
}

//串口回调函数
static void serial_io_handler(uint32_t offset, int len, bool is_write) {
  assert(len == 1);
  switch (offset) {
    /* We bind the serial port with the host stderr in NEMU. */
		//在NEMU中，我们将串口与主机的标准错误输出绑定。
		//映射到 stderr 是为了让目标程序的输出独立于仿真器自身的输出，便于调试、查看和重定向。
    case CH_OFFSET:
      if (is_write) serial_putc(serial_base[0]);
      else panic("do not support read");
      break;
    default: panic("do not support offset = %d", offset);
  }
}

//初始化串口
void init_serial() {
	//串口初始化时会分别注册`0x3F8`处长度为8个字节的端口
  serial_base = new_space(8);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("serial", CONFIG_SERIAL_PORT, serial_base, 8, serial_io_handler);
#else
	//以及`0xa00003F8`处长度为8字节的MMIO空间
  add_mmio_map("serial", CONFIG_SERIAL_MMIO, serial_base, 8, serial_io_handler);
#endif
}
