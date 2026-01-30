#include "systick.h"

#define SYSTICK_BASE 0xE000E010UL

static vu32 systick_counter = 0;

void systick_init(u32 ticks)
{
	struct systick *systick = (struct systick *)SYSTICK_BASE;
	u32 counter = (ticks - 1) & 0x00FFFFFFUL;
	systick->load = counter;
	systick->val = 0;
	systick->ctrl = 0x01UL | 0x02UL | 0x04UL;
}

void SysTick_Handler(void)
{
	systick_counter++;
}

u32 get_systick_counter()
{
	return systick_counter;
}
