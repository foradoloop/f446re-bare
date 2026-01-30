#ifndef UART_H
#define UART_H

#include "common.h"
#include <stddef.h>

#define UART1_BASE 0x40011000
#define UART2_BASE 0x40004400
#define UART3_BASE 0x40004800
#define UART4_BASE 0x40004C00
#define UART5_BASE 0x40005000
#define UART6_BASE 0x40011400

#define UART(n) ((struct uart *)(UART##n##_BASE))
#define USART(n) UART(n)

struct uart {
	vu32 sr;
	vu32 dr;
	vu32 brr;
	vu32 cr1;
	vu32 cr2;
	vu32 cr3;
	vu32 gtpr;
};
typedef struct uart uart;
typedef struct uart usart;

void uart_init(struct uart *u, u32 clk, u32 br);
u8 uart_write_ready(struct uart *u);
u8 uart_read_ready(struct uart *u);
void uart_write_byte(struct uart *u, u8 byte);
u8 uart_read_byte(struct uart *u);
void uart_putc(struct uart *u, char c);
void uart_puts(struct uart *u, char *s);
char uart_getc(struct uart *u);
void uart_gets(struct uart *u, char *buffer, size_t len);

#endif

