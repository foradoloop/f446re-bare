#include "gpio.h"

void gpio_pin_set_moder(struct gpio *gpio, u8 pin, u8 mode)
{
	gpio->moder &= ~(0x03UL << (pin << 1));
	gpio->moder |= (0x03UL & mode) << (pin << 1);
}

void gpio_pin_set_bsrr(struct gpio *gpio, u8 pin)
{
	gpio->bsrr = BIT(pin);
}

void gpio_pin_reset_bsrr(struct gpio *gpio, u8 pin)
{
	gpio->bsrr = BIT(16 + pin);
}

void gpio_pin_write_bsrr(struct gpio *gpio, u8 pin, u8 state)
{
	if (state) {
		gpio_pin_set_bsrr(gpio, pin);
	} else {
		gpio_pin_reset_bsrr(gpio, pin);
	}
}

void gpio_pin_toggle_bsrr(struct gpio *gpio, u8 pin)
{
	gpio->bsrr = BIT(pin + (16 * READ_BIT(gpio->odr, pin)));
}

void gpio_pin_set_af(struct gpio *gpio, u8 pin, u8 af)
{
	u8 index = pin / 8;
	u8 shift = (pin & 0x07) * 4;
	gpio->afr[index] &= ~(0xFUL << shift);
	gpio->afr[index ] |= (u32)af << shift;
}

