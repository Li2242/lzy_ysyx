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

#include <common.h>
#include <device/map.h>

#define SCREEN_W (MUXDEF(CONFIG_VGA_SIZE_800x600, 800, 400))
#define SCREEN_H (MUXDEF(CONFIG_VGA_SIZE_800x600, 600, 300))

static uint32_t screen_width() {
  return MUXDEF(CONFIG_TARGET_AM, io_read(AM_GPU_CONFIG).width, SCREEN_W);
}

static uint32_t screen_height() {
  return MUXDEF(CONFIG_TARGET_AM, io_read(AM_GPU_CONFIG).height, SCREEN_H);
}

static uint32_t screen_size() {
  return screen_width() * screen_height() * sizeof(uint32_t);
}

static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;

#ifdef CONFIG_VGA_SHOW_SCREEN
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

//初始化一个小屏幕
static void init_screen() {
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "%s-NEMU", str(__GUEST_ISA__));
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(
      SCREEN_W * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)),
      SCREEN_H * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)),
      0, &window, &renderer);
	//设置window标题
  SDL_SetWindowTitle(window, title);
	//相当于画布 用来存放你‘将来要显示’的像素图像。
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
	//把渲染器当前内容真正显示到屏幕上。
  SDL_RenderPresent(renderer);
}

//更新屏幕:将显存 (vmem) 中的像素数据同步到窗口显示屏幕上。
static inline void update_screen() {
	//把 vmem 拷贝进 texture
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
	//清除上一帧的画面
  SDL_RenderClear(renderer);
	//把 texture 画到 renderer（渲染器）上
	//两个 NULL 表示整张 texture 都用，覆盖整个窗口
  SDL_RenderCopy(renderer, texture, NULL, NULL);
	//将 renderer 的内容真正呈现到屏幕上。
  SDL_RenderPresent(renderer);
}
#else
static void init_screen() {}

static inline void update_screen() {
  io_write(AM_GPU_FBDRAW, 0, 0, vmem, screen_width(), screen_height(), true);
}
#endif
#endif

//若sync为true, 则马上将帧缓冲中的内容同步到屏幕上.
void vga_update_screen() {
  // TODO: call `update_screen()` when the sync register is non-zero,
  // then zero out the sync register
	if(vgactl_port_base[1] != 1){
		update_screen();
		vgactl_port_base[1] = 0;
	}
}

//初始化
void init_vga() {
  vgactl_port_base = (uint32_t *)new_space(8);
	//宽高
  vgactl_port_base[0] = (screen_width() << 16) | screen_height();

#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("vgactl", CONFIG_VGA_CTL_PORT, vgactl_port_base, 8, NULL);
#else
  add_mmio_map("vgactl", CONFIG_VGA_CTL_MMIO, vgactl_port_base, 8, NULL);
#endif
	//一段用于映射到video memory(显存, 也叫frame buffer, 帧缓冲)的MMIO空间.
  vmem = new_space(screen_size());
	//显存
  add_mmio_map("vmem", CONFIG_FB_ADDR, vmem, screen_size(), NULL);
	//初始化画布
  IFDEF(CONFIG_VGA_SHOW_SCREEN, init_screen());
	//清空画布
  IFDEF(CONFIG_VGA_SHOW_SCREEN, memset(vmem, 0, screen_size()));
}
