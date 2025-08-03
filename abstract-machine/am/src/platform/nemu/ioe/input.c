#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
	int key_code = inl(KBD_ADDR);
	if(key_code == AM_KEY_NONE){
		kbd->keydown = 0;
		kbd->keycode = AM_KEY_NONE;
		return;
	}
  kbd->keydown = 1;
	kbd->keycode = key_code;
  return;
}
