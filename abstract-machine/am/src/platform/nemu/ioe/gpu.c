#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

//屏幕大小寄存器
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
	uint32_t *pixels = ctl->pixels;
	int width = inw(VGACTL_ADDR+2);
	uint32_t* fb = (uint32_t*)FB_ADDR;

	for (int j = 0; j < h; j++) {       
		for (int i = 0; i < w; i++) {     
			int screen_index = (y + j) * width + (x + i);
			int pixel_index = j * w + i;
			fb[screen_index] = pixels[pixel_index];
		}
	}

}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
