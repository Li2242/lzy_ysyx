#include <am.h>
#include <nemu.h>
#include <stdio.h>


#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)


void __am_audio_init() {

}

//可读出存在标志present以及流缓冲区的大小bufsize
void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
	cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

//写入freq, channels和samples这三个的初始化参数`
void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
	outl(AUDIO_FREQ_ADDR     , ctrl->freq);
	outl(AUDIO_CHANNELS_ADDR , ctrl->channels);
	outl(AUDIO_SAMPLES_ADDR  , ctrl->samples);
	outl(AUDIO_INIT_ADDR     , 1); // 直接触发 NEMU 端初始化
}

//可读出当前流缓冲区已经使用的大小count.
void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

/*
 可将[buf.start, buf.end)区间的内容作为音频数据写入流缓冲区.
 若当前流缓冲区的空闲空间少于即将写入的音频数据, 此次写入将会一直等待, 
 直到有足够的空闲空间将音频数据完全写入流缓冲区才会返回.
*/
static uint32_t sbuf_wpos  = 0;
static uint32_t sbuf_count = 0;

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
	sbuf_count = inl(AUDIO_COUNT_ADDR);
	uint32_t sbuf_size  = inl(AUDIO_SBUF_SIZE_ADDR);
	// printf("__am_audio_play调用前的%d\n",sbuf_count);


	int len = (uint8_t *)ctl->buf.end - (uint8_t *)ctl->buf.start;
	int i =0;

	while(i < len){
		//计算缓冲区的空闲空间
		int free_space = sbuf_size - sbuf_count;
		if(free_space == 0){
			for(int i = 0;i<1000000;i++){

			}
			continue;
		}
		outb(AUDIO_SBUF_ADDR + sbuf_wpos,*((uint8_t *)ctl->buf.start + i));
    sbuf_wpos = (sbuf_wpos + 1) % sbuf_size;
    sbuf_count++;
    i++;
	}

	//写回
	outl(AUDIO_COUNT_ADDR , sbuf_count);
	// printf("__am_audio_play调用后的%d\n",sbuf_count);
}
