#include "common.h"
#include <sys/time.h>
uint32_t *rtc_port_base = NULL;
static uint64_t boot_time = 0;

//获取当前系统信息并返回
static uint64_t get_time_internal() {
  struct timeval now;
	//当前的系统时间，以微秒（μs）为单位
  gettimeofday(&now, NULL);
  uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
  return us;
}

//当前程序运行多长时间
uint64_t get_time() {
  if (boot_time == 0) boot_time = get_time_internal();
  uint64_t now = get_time_internal();
  return now - boot_time;
}

void rtc_io_handler() {
    uint64_t us = get_time();       // 获取当前系统运行时间（单位：微秒）
    rtc_port_base[0] = (uint32_t)us;// 低 32 位写入偏移 0
    rtc_port_base[1] = us >> 32;    // 高 32 位写入偏移 4
}











//设备初始化 init_timer
void init_timer() {
  rtc_port_base = (uint32_t *)new_space(8);
}
