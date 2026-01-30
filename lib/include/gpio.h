#ifndef GPIO_H
#define GPIO_H

#include "common.h"

#define GPIO_BASE 0x40020000UL
#define GPIO_OFFSET 0x400UL

#define GPIO(x) ((struct gpio *)(GPIO_BASE + GPIO_OFFSET * (x - 'a')))

struct gpio {
	vu32 moder;
	vu32 otyper;
	vu32 ospeedr;
	vu32 pupdr;
	vu32 idr;
	vu32 odr;
	vu32 bsrr;
	vu32 lckr;
	vu32 afr[2];
};

void gpio_pin_set_bsrr(struct gpio *gpio, u8 pin);
void gpio_pin_reset_bsrr(struct gpio *gpio, u8 pin);
void gpio_pin_write_bsrr(struct gpio *gpio, u8 pin, u8 state);
void gpio_pin_toggle_bsrr(struct gpio *gpio, u8 pin);

void gpio_pin_set_moder(struct gpio *gpio, u8 pin, u8 mode);
void gpio_pin_set_af(struct gpio *gpio, u8 pin, u8 af);

#endif
