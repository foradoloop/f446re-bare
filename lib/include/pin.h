#ifndef PIN_H
#define PIN_H

#include "common.h"
#include <stdbool.h>

struct pin {
	u8 port;
	u8 pin;
};

enum pin_mode {
	PIN_MODE_INPUT = 0x00UL,
	PIN_MODE_OUTPUT = 0x01UL,
	PIN_MODE_ALTERNATE = 0x02UL,
	PIN_MODE_ANALOG = 0x03UL
};

#define PIN(portnum, pinnum) (struct pin){ .port = portnum, .pin = pinnum }

void pin_init(struct pin *pin, u8 portnum, u8 pinnum);
void pin_write(struct pin pin, bool state);
void pin_toggle(struct pin pin);
void pin_mode(struct pin pin, u8 mode);
void pin_set_af(struct pin pin, u8 af);

#endif
