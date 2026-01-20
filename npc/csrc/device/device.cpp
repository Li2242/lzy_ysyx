#include "common.h"
#include <SDL2/SDL.h>

void device_update() {
  static uint64_t last = 0;
  uint64_t now = get_time();
  //没超过一定的时间段就不更新
  if (now - last < 1000000 / 60) {
    return;
  }
  //同时也要更新时间
  last = now;
  //是否要刷新屏幕呀？
  vga_update_screen();

#ifndef CONFIG_TARGET_AM
  SDL_Event event;
	//检查用户是否点击关闭窗口
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			npc_state = NPC_QUIT;
			break;
      default: break;
    }
  }
#endif
}

//清空所有SDL事件队列
void sdl_clear_event_queue() {
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event));
#endif
}



void init_device() {
	init_map();
	init_serial();
	init_timer();
	init_vga();
}

