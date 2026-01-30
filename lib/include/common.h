#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef volatile uint8_t vu8;
typedef volatile uint16_t vu16;
typedef volatile uint32_t vu32;

#define BIT(n) (0x01UL << (n))
#define SET_BIT(reg, n) (reg |= BIT(n))
#define CLEAR_BIT(reg, n) (reg &= ~BIT(n))
#define READ_BIT(reg, n) ((reg >> (n)) & 0x01UL)

#define dummy(var) { u32 temp = var; (void)temp; }

#endif
