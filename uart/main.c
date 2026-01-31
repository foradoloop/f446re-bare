#include "common.h"
#include "systick.h"
#include "rcc.h"
#include "pin.h"
#include "uart.h"

#define HSI_FREQ 16000000

static usart *usart2 = USART(2);

static inline void init()
{
	systick_init(HSI_FREQ / 1000);
	rcc_gpio_clk_enable('a');
	rcc_uart_clk_enable(usart2);

	struct pin tx = PIN('a', 2);
	struct pin rx = PIN('a', 3);
	pin_mode(tx, PIN_MODE_ALTERNATE);
	pin_mode(rx, PIN_MODE_ALTERNATE);
	pin_set_af(tx, 7);
	pin_set_af(rx, 7);

	uart_init(usart2, HSI_FREQ, 115200);
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

	while(1) {
		pin_write(led, 1);
		uart_puts(usart2, "green led on\r\n");
		delay_ms(500);
		pin_write(led, 0);
		uart_puts(usart2, "green led off \r\n");
		delay_ms(500);
	}
}

