#ifndef RCC_H
#define RCC_H

#include "common.h"
#include "uart.h"

#define RCC_BASE 0x40023800UL

struct rcc {
	vu32 cr;
	vu32 pllcfgr;
	vu32 cfgr;
	vu32 cir;
	vu32 ahb1rstr;
	vu32 ahb2rstr;
	vu32 ahb3rstr;
	vu32 reserved0;
	vu32 apb1rstr;
	vu32 apb2rstr;
	vu32 reserved1[2];
	vu32 ahb1enr;
	vu32 ahb2enr;
	vu32 ahb3enr;
	vu32 reserved2;
	vu32 apb1enr;
	vu32 apb2enr;
	vu32 reserved3[2];
	vu32 ahb1lpenr;
	vu32 ahb2lpenr;
	vu32 ahb3lpenr;
	vu32 apb1lpenr;
	vu32 apb2lpenr;
	vu32 bdcr;
	vu32 csr;
	vu32 sscgr;
	vu32 plli2scfgr;
	vu32 pllsaicfgr;
	vu32 dckcfgr;
	vu32 ckgateenr;
	vu32 dckcfgr2;
};

void rcc_gpio_clk_enable(unsigned char port);
void rcc_uart_clk_enable(struct uart *u);

#endif
