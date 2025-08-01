#include <am.h>
#include <nemu.h>
#include "/home/lzy14/ysyx/ysyx-workbench/abstract-machine/klib/include/klib.h"

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
	putstr("0\n");
	uint32_t high32= inl(RTC_ADDR + 4);
	printf("%d ",high32);
	uint32_t low32 = inl(RTC_ADDR);
	printf("%d\n",low32);
	putstr("1\n");
	uptime->us = (uint64_t)high32<<32 | low32;
	
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
