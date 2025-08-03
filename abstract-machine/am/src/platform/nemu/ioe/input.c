#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
	putch('1');
	uint32_t key_code = inl(KBD_ADDR);
	putch('2');
	if(key_code == AM_KEY_NONE){
		putch('3');		kbd->keydown = 0;
		kbd->keycode = AM_KEY_NONE;
		return;
	}
  kbd->keydown = 1;
	kbd->keycode = key_code;
  return;
}
