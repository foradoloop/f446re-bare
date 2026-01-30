#include "uart.h"

void uart_init(struct uart *u, u32 clk, u32 br)
{
	u->brr = clk / br;
	u->cr1 = BIT(13) | BIT(3) | BIT(2);
}

u8 uart_write_ready(struct uart *u)
{
	return READ_BIT(u->sr, 7);
}

u8 uart_read_ready(struct uart *u)
{
	return READ_BIT(u->sr, 5);
}

void uart_write_byte(struct uart *u, u8 byte)
{
	u->dr = (u32)byte;
}

u8 uart_read_byte(struct uart *u)
{
	return (u8)u->dr;
}

void uart_putc(struct uart *u, char c)
{
	while (!uart_write_ready(u));
	uart_write_byte(u, c);
}

void uart_puts(struct uart *u, char *s)
{
	while (*s) {
		uart_putc(u, *s++);
	}
}

char uart_getc(struct uart *u)
{
	while (!uart_read_ready(u));
	return (char)uart_read_byte(u);
}

void uart_gets(struct uart *u, char *buffer, size_t len)
{
	size_t i = 0;
	for (; i < len - 1; i++) {
		char c = uart_getc(u);
		if (c == '\r' || c == '\n') {
			break;
		}
		buffer[i] = c;
	}
	buffer[i] = '\0';
}

