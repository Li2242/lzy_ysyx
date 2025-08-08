#include <am.h>
#include <nemu.h>
#include <SDL2/SDL.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)


//写入后将根据设置好的`freq`, `channels`和`samples`来对SDL的音频子系统进行初始化
void __am_audio_init() {
}

//可读出存在标志present以及流缓冲区的大小bufsize
void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = false;
}

//可根据写入的freq, channels和samples对声卡进行初始化.
void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
	SDL_AudioSpec s = {};
	s.freq     = ctrl->freq;
	s.format   = AUDIO_S16SYS;
	s.channels = ctrl->channels; 
	s.samples  = ctrl->samples;
	s.callback = outl; 
	s.userdata = NULL;        
	
	SDL_InitSubSystem(SDL_INIT_AUDIO); // 只初始化音频子系统
	SDL_OpenAudio(&s, NULL); //打开设备并准备好缓冲区
	SDL_PauseAudio(0);       //开始播放音频
}

//可读出当前流缓冲区已经使用的大小count.
void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = 0;
}

/*
 可将[buf.start, buf.end)区间的内容作为音频数据写入流缓冲区.
 若当前流缓冲区的空闲空间少于即将写入的音频数据, 此次写入将会一直等待, 
 直到有足够的空闲空间将音频数据完全写入流缓冲区才会返回.
*/
void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
}
