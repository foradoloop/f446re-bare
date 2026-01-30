#ifndef SYSTICK_H
#define SYSTICK_H

#include "common.h"

struct systick {
	vu32 ctrl;
	vu32 load;
	vu32 val;
	vu32 calib;
};

void SysTick_Handler(void);
void systick_init(u32 ticks);
u32 get_systick_counter();

#endif
