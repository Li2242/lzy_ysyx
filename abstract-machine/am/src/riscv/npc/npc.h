# define DEVICE_BASE 0xa0000000

#define MMIO_BASE 0xa0000000
//串口设备的地址
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
//键盘地址
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
//实时时钟地址
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)
//显示控制器的地址
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
//音频地址
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
//磁盘地址
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)
//帧缓冲区（显示用的内存）地址
#define FB_ADDR         (MMIO_BASE   + 0x1000000)
//音频缓冲区地址。
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)