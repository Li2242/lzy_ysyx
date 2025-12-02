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
#include <SDL2/SDL.h>

//寄存器
enum {
	//采样率
	reg_freq,
	//通道数
	reg_channels,
	//样本数
	reg_samples,
	//缓冲区大小
	reg_sbuf_size,
	//初始化
	reg_init,
	//可以读出当前流缓冲区已经使用的大小
	reg_count,
	nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static SDL_AudioSpec s;          // 保存 SDL 音频参数
static uint32_t sbuf_rpos = 0;      // 环形缓冲区读指针
static uint32_t sbuf_count = 0;     // 当前缓冲区已用字节数

//SDL音频的回调函数
void audio_callback(void *userdata, uint8_t *stream, int len){

	sbuf_count = audio_base[reg_count];     // 当前缓冲区已用字节数

	//防止越界
	if (sbuf_count > CONFIG_SB_SIZE) sbuf_count = CONFIG_SB_SIZE;
	if (sbuf_count < 0) sbuf_count = 0;


	if(sbuf_count >= len){
		int remaining = CONFIG_SB_SIZE - sbuf_rpos;
		//数据足够时的连续拷贝分支
		if(remaining >= len){
			memcpy(stream,sbuf + sbuf_rpos, len);
			//指针直接加上长度就行
			sbuf_rpos = (len + sbuf_rpos) % CONFIG_SB_SIZE;
		}else{
			//数据足够时的环绕拷贝分支
			memcpy(stream, sbuf + sbuf_rpos,remaining);
			memcpy(stream + remaining,sbuf,len - remaining);
			//从头开始的指针
			sbuf_rpos = len - remaining;
		}
		sbuf_count -= len;
	}else{
		int remaining = CONFIG_SB_SIZE - sbuf_rpos;
		//数据不足时环绕copy
		if(remaining < sbuf_count){
			memcpy(stream,sbuf + sbuf_rpos, remaining);
			memcpy(stream + remaining,sbuf,sbuf_count-remaining);
			//从头开始
			sbuf_rpos = sbuf_count - remaining;
		}else{
			//数据不足时直接copy
			memcpy(stream,sbuf + sbuf_rpos, sbuf_count);
			//直接加上
			sbuf_rpos = (sbuf_count + sbuf_rpos) % CONFIG_SB_SIZE;
		}
		//静音填充位置
		memset(stream + sbuf_count,0,len - sbuf_count);
		sbuf_count = 0;
	}
	//修改之后把计数改一下
	audio_base[reg_count] = sbuf_count;
}

//填充音频数据的回调函数
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
	int reg_index = offset /4;
	switch(reg_index){
		//init寄存器用于初始化
		case reg_init:
			//初始化SDL
			if (SDL_Init(SDL_INIT_AUDIO) < 0) {
				fprintf(stderr, "SDL初始化失败: %s\n", SDL_GetError());
				return;
			}
			//设置参数
			s.freq     = audio_base[reg_freq];
			s.channels = audio_base[reg_channels];
			s.samples  = audio_base[reg_samples];
			s.format   = AUDIO_S16SYS; //16位有符号数
			s.callback = audio_callback;
			s.userdata = NULL;
			sbuf_count = 0;
			//启动的音频功能，让后面的音频代码能正常工作
			if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
				printf("Failed to init SDL audio: %s\n", SDL_GetError());
				return;
			}
			//打开默认音频设备并配置参数
			if (SDL_OpenAudio(&s, NULL) < 0) {
				printf("Failed to open audio: %s\n", SDL_GetError());
				return;
			}
			//控制音频播放状态， 0:开始播放/继续播放  非0:暂停播放
			SDL_PauseAudio(0);
			break;

		//这个是不变的所以可以放在这
		case reg_sbuf_size :
			audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
			break;

		default:  break;
	}
}

void init_audio() {
	//0xa0000200 几个寄存器的空间
	uint32_t space_size = sizeof(uint32_t) * nr_reg;
	audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  	add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  	add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif
	//0xa1200000 流缓冲区
	sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
	add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
