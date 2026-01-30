#include "rcc.h"

void rcc_gpio_clk_enable(unsigned char port)
{
	struct rcc *rcc = (struct rcc *)RCC_BASE;
	SET_BIT(rcc->ahb1enr, port - 'a');

	dummy(rcc->ahb1enr);
}

void rcc_uart_clk_enable(struct uart *u)
{
    struct rcc *rcc = (struct rcc *)RCC_BASE;
    u32 addr = (u32)u;

    switch(addr) {
	    case UART1_BASE:
		    rcc->apb2enr |= BIT(4);
		    break;
	    case UART2_BASE:
		    rcc->apb1enr |= BIT(17);
		    break;
	    case UART3_BASE:
		    rcc->apb1enr |= BIT(18);
		    break;
	    case UART4_BASE:
		    rcc->apb1enr |= BIT(19);
		    break;
	    case UART5_BASE:
		    rcc->apb1enr |= BIT(20);
		    break;
	    case UART6_BASE:
		    rcc->apb2enr |= BIT(5);
		    break;
	    default:
		    break;
    }

    dummy(rcc->apb1enr);
    dummy(rcc->apb2enr);
}

