#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

//屏幕大小寄存器
//AM_DEVREG( 9, GPU_CONFIG,   RD, bool present, has_accel; int width, height, vmemsz);
void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = inw(VGACTL_ADDR+2), .height = inw(VGACTL_ADDR),
    .vmemsz = inw(VGACTL_ADDR+2) * inw(VGACTL_ADDR) * sizeof(uint32_t)
  };
}
// AM_DEVREG(11, GPU_FBDRAW,   WR, int x, y; void *pixels; int w, h; bool sync);  //AM帧缓冲控制器
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x;
	int y = ctl->y;
	int w = ctl->w;
	int h = ctl->h;
	bool sync = ctl->sync;
	uint32_t *pixels = ctl->pixels;
	
	//屏幕宽度
	int width = inw(VGACTL_ADDR+2);

	//把地址搞过来，整成数组的形式写
	uint32_t* fb = (uint32_t*)FB_ADDR;
	
	//有点难想啊，还好想明白了
	for (int j = 0; j < h; j++) {       
		for (int i = 0; i < w; i++) {  
			int screen_index = (y + j) * width + (x + i);
			int pixel_index = j * w + i;
			fb[screen_index] = pixels[pixel_index];
		}
	}
	//触发刷新
	if (sync) {
    outl(SYNC_ADDR, 1);  
  }
}


void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
