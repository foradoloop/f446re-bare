#include "common.h"
#include "systick.h"
#include "main.h"

extern u32 _estack; 

void Reset_Handler(void);

__attribute__((section(".isr_vector")))u32 const vector_table[] = {
	(u32)&_estack,
	(u32)Reset_Handler,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	(u32)SysTick_Handler
};

void Reset_Handler(void)
{
	extern u32 _sidata, _sdata, _edata, _sbss, _ebss;
	u32 *src = &_sidata;
	u32 *dst = &_sdata;

	while (dst < &_edata) {
		*dst++ = *src ++;
	}

	dst = &_sbss;
	while (dst < &_ebss) {
		*dst++ = 0;
	}

	main();

	while (1);
}
