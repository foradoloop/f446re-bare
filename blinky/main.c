#include "common.h"
#include "systick.h"
#include "rcc.h"
#include "pin.h"

#define HSI_FREQ 16000000

static inline void init()
{
	systick_init(HSI_FREQ / 1000);
	rcc_gpio_clk_enable('a');
}

static inline void delay_ms(u32 ms)
{
	u32 begin = get_systick_counter();
	while ((get_systick_counter() - begin) < ms);
}

int main(void)
{
	init();

	struct pin led = PIN('a', 5);
	pin_mode(led, PIN_MODE_OUTPUT);

	while (1) {
		pin_toggle(led);
		delay_ms(500);
	}
}

