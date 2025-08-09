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

enum {
	//freq, channels和samples这三个寄存器可写入相应的初始化参数
  reg_freq,
  reg_channels,
  reg_samples,
	//sbuf_size寄存器可读出流缓冲区的大小
  reg_sbuf_size,
	//init寄存器用于初始化, 写入后将根据设置好的freq, channels和samples来对SDL的音频子系统进行初始化
  reg_init,
	//count寄存器可以读出当前流缓冲区已经使用的大小
  reg_count,
  nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static SDL_AudioSpec s={};        // 保存 SDL 音频参数
static uint32_t sbuf_rpos = 0;      // 环形缓冲区读指针
static uint32_t sbuf_count = 0;     // 当前缓冲区已用字节数

void audio_callback(void *userdata, uint8_t *stream, int len){
	if (!audio_base || !sbuf) return;
	sbuf_count = audio_base[reg_count];     // 当前缓冲区已用字节数

	for(int i =0; i<len ;i++){
		if(sbuf_count>0){
			stream[i] = sbuf[sbuf_rpos];
			sbuf_rpos = (sbuf_rpos + 1) % CONFIG_SB_SIZE;
			sbuf_count--;
		}else{
			stream[i] = 0;
		}
	}

	//修改之后再把公共区域的改一下
	audio_base[reg_count]    = sbuf_count;
	printf("audio_callback调用后的%d\n",audio_base[reg_count]);
}

//填充音频数据的回调函数
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
	int reg_index = offset /4;
	switch(reg_index){
		case reg_freq:
		case reg_channels:
		case reg_samples:
			break;

		case reg_init:
			s.freq     = audio_base[reg_freq];
			s.channels = audio_base[reg_channels];
			s.samples  = audio_base[reg_samples];
			s.format   = AUDIO_S16SYS;
			s.callback = audio_callback;
			s.userdata = NULL;
			if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
				printf("Failed to init SDL audio: %s\n", SDL_GetError());
				return;
			}
			if (SDL_OpenAudio(&s, NULL) < 0) {
				printf("Failed to open audio: %s\n", SDL_GetError());
				return;
			}
			SDL_PauseAudio(0);
			printf("调用了！\n");
			break;

		case reg_sbuf_size :
			audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
			break;

		case reg_count:
		//这里应该些什么
			audio_base[reg_count] = sbuf_count;
			break;
		default:
			break;
	}
}

void init_audio() {
	//注册0x200处长度为24个字节的端口
	//我想再加几个
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
	//注册0xa0000200处长度为24字节的MMIO空间
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif
	//注册了从0xa1200000开始, 长度为64KB的MMIO空间作为流缓冲区.
  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
