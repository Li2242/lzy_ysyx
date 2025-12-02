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

#include <device/map.h>
#include <device/alarm.h>
#include <utils.h>

static uint32_t *rtc_port_base = NULL;

//时钟的回调函数，用来更新时间
static void rtc_io_handler(uint32_t offset, int len, bool is_write) {
  	assert(offset == 0 || offset == 4);
	//offset在为4的时候才更新,如果先读低位会到的是上一次未更新的时间
	//学到一个名词叫时钟撕裂，防止时钟撕裂
  	if (!is_write && offset == 4) {
		uint64_t us = get_time();       // 运行时间
		rtc_port_base[0] = (uint32_t)us;// 低32写入偏移 0
		rtc_port_base[1] = us >> 32;    // 高32写入偏移 4
  }
}

//时钟中断，目前用不上
#ifndef CONFIG_TARGET_AM
static void timer_intr() {
  if (nemu_state.state == NEMU_RUNNING) {
    extern void dev_raise_intr();
    dev_raise_intr();
  }
}
#endif


void init_timer() {
	//初始化时会分配处长度为8个字节的端口
  	rtc_port_base = (uint32_t *)new_space(8);
#ifdef CONFIG_HAS_PORT_IO
	//端口
  	add_pio_map ("rtc", CONFIG_RTC_PORT, rtc_port_base, 8, rtc_io_handler);
#else
	//内存映射
  	add_mmio_map("rtc", CONFIG_RTC_MMIO, rtc_port_base, 8, rtc_io_handler);
#endif
  	IFNDEF(CONFIG_TARGET_AM, add_alarm_handle(timer_intr));
}
