#include <am.h>
#include <nemu.h>

//键盘的最高位是标志位

#define KEYDOWN_MASK 0x8000

//从nemu中写入的地址读出键码
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
	uint32_t key_code = inl(KBD_ADDR);
	if(key_code == AM_KEY_NONE){
		kbd->keydown = 0;
		kbd->keycode = AM_KEY_NONE;
		return;
	}
  	kbd->keydown = key_code & KEYDOWN_MASK ? 1 : 0;
	kbd->keycode = key_code & ~KEYDOWN_MASK;
  return;
}
