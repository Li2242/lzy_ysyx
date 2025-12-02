#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

void __am_audio_init() {
}

//标志present  流缓冲区的大小bufsize
void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  	cfg->present = true;
	cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

//写入freq, channels和samples这三个的初始化参数
void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
	//写入参数
	outl(AUDIO_FREQ_ADDR     , ctrl->freq);
	outl(AUDIO_CHANNELS_ADDR , ctrl->channels);
	outl(AUDIO_SAMPLES_ADDR  , ctrl->samples);
	// 赋值
	outl(AUDIO_INIT_ADDR, 0); 
}

//可读出当前流缓冲区已经使用的大小count.
void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

//定义写指针
static uint32_t sbuf_wpos  = 0;

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {

	//读取硬件状态
	uint32_t sbuf_count = inl(AUDIO_COUNT_ADDR);
	uint32_t sbuf_size  = inl(AUDIO_SBUF_SIZE_ADDR);

	//计算要写入的数据长度
	uint8_t *start_p = (uint8_t *)ctl->buf.start;
    uint8_t *end_p = (uint8_t *)ctl->buf.end;
    int len = end_p - start_p;

    int written_len = 0;

	while(written_len < len){
		//循环前先更新一次
		sbuf_count = inl(AUDIO_COUNT_ADDR);
		//
		uint32_t free_space = sbuf_size - sbuf_count;
		//没有位置就等一会
		if(free_space == 0){
			for (volatile int i = 0; i < 1000; i++) {};
			continue;
		}
		//本次写入多少数据
		uint32_t write_len = (free_space < (len - written_len)) ? free_space : (len - written_len);

		for(uint32_t i =0; i < write_len; i++){
			//取出数据
			uint8_t data = start_p[written_len + i];
			//循环写入数据
			outb(AUDIO_SBUF_ADDR + sbuf_wpos, data);
			sbuf_wpos = (sbuf_wpos + 1) % sbuf_size; 
		}
		//计数
		sbuf_count += write_len;
		//写回
		outl(AUDIO_COUNT_ADDR , sbuf_count);
		//
		written_len += write_len;
	}
}

// void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
//     uint32_t sbuf_size = inl(AUDIO_SBUF_SIZE_ADDR);
//     uint8_t *data = (uint8_t *)ctl->buf.start;
//     int len = (uint8_t *)ctl->buf.end - data;
//     int written = 0;
    
//     // 同步
//     sbuf_count = inl(AUDIO_COUNT_ADDR);
    
//     while (written < len ) {
//         int free_space = sbuf_size - sbuf_count;
        
//         if (free_space == 0) {
//             // 更新硬件状态
//             sbuf_count = inl(AUDIO_COUNT_ADDR);
//             // 短暂延迟
//             for (volatile int i = 0; i < 1000; i++);
//             continue;
//         }
        
//         // 计算写入量
//         int to_write = len - written;
//         if (to_write > free_space) to_write = free_space;
        
//         // 写入数据
//         int remaining = sbuf_size - sbuf_wpos;
        
//         if (remaining >= to_write) {
//             // 连续写入
//             for (int i = 0; i < to_write; i++) {
//                 outb(AUDIO_SBUF_ADDR + sbuf_wpos + i, data[written + i]);
//             }
//             sbuf_wpos = (sbuf_wpos + to_write) % sbuf_size;
//         } else {
//             // 环绕写入
//             for (int i = 0; i < remaining; i++) {
//                 outb(AUDIO_SBUF_ADDR + sbuf_wpos + i, data[written + i]);
//             }
//             for (int i = 0; i < to_write - remaining; i++) {
//                 outb(AUDIO_SBUF_ADDR + i, data[written + remaining + i]);
//             }
//             sbuf_wpos = to_write - remaining;
//         }
        
//         written += to_write;
//         sbuf_count += to_write;
//     }
    
//     // 更新硬件
//     outl(AUDIO_COUNT_ADDR, sbuf_count);
    
// }