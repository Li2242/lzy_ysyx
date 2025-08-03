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

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
}

void init_audio() {
	//注册0x200处长度为24个字节的端口
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
