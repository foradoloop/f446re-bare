#include "pin.h"
#include "gpio.h"

void pin_init(struct pin *pin, u8 portnum, u8 pinnum)
{
	if (pin) {
		pin->port = portnum;
		pin->pin = pinnum;
	}
}

void pin_write(struct pin pin, bool state)
{
	gpio_pin_write_bsrr(GPIO(pin.port), pin.pin, state);
}

void pin_toggle(struct pin pin)
{
	gpio_pin_toggle_bsrr(GPIO(pin.port), pin.pin);
}

void pin_mode(struct pin pin, u8 mode)
{
	gpio_pin_set_moder(GPIO(pin.port), pin.pin, mode);
}

void pin_set_af(struct pin pin, u8 af)
{
	gpio_pin_set_af(GPIO(pin.port), pin.pin, af);
}

