#include "common.h"
#include <SDL2/SDL.h>

#define SCREEN_W 800
#define SCREEN_H 800
#define SCREEN_SIZE 1000*1000

void *vmem = NULL;
uint32_t *vgactl_port_base = NULL;

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;


//初始化
//texture纹理； renderer渲染器； veme显存
static void init_screen() {
	SDL_Window *window = NULL;
	//标题
	char title[128];
	sprintf(title, "RISCV32E-NPC");
	SDL_Init(SDL_INIT_VIDEO);
	//创建renderer
	SDL_CreateWindowAndRenderer(
		SCREEN_W ,
		SCREEN_H ,
		0, &window, &renderer);
	//设置窗口的标题
  	SDL_SetWindowTitle(window, title);
	//创造texture
  	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
	//展示renderer
  	SDL_RenderPresent(renderer);
}


//更新屏幕      将显存中的像素数据同步到窗口显示屏幕上
static inline void update_screen() {
	//将vmem中的数据传入的到texture中
  	SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
	//清空renderer
  	SDL_RenderClear(renderer);
	//将texture传入到renderer中
  	SDL_RenderCopy(renderer, texture, NULL, NULL);
	//展现renderer
  	SDL_RenderPresent(renderer);
}


//若sync为true, 则马上将帧缓冲中的内容同步到屏幕上.
void vga_update_screen() {
	if(vgactl_port_base[1] != 0){
		update_screen();
		vgactl_port_base[1] = 0;
		// printf("刷新成功! vgactl_port_base=%08x\n",vgactl_port_base[1]);
	}
}



//初始化
void init_vga() {
  	vgactl_port_base = (uint32_t *)new_space(8);
	//宽高
  	vgactl_port_base[0] = (SCREEN_W << 16) | SCREEN_H;

  	vmem = new_space(SCREEN_SIZE);
	//初始化
  	init_screen();
	//清空
  	memset(vmem, 0, SCREEN_SIZE);
}