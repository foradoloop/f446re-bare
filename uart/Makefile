CC      = arm-none-eabi-gcc
OBJCPY  = arm-none-eabi-objcopy
MACH    = cortex-m4
MEMADDR = 0x08000000

CFLAGS  = -W -Wall -Wextra -mcpu=$(MACH) -mthumb -I$(LIB_INC)
LDFLAGS = -Tlinker.ld -nostdlib 

LIB_SRC = ../lib/src
LIB_INC = ../lib/include

SRCS = $(LIB_SRC)/rcc.c $(LIB_SRC)/gpio.c $(LIB_SRC)/systick.c $(LIB_SRC)/pin.c $(LIB_SRC)/uart.c main.c startup.c
OBJS = $(SRCS:.c=.o)

all: firmware.bin

firmware.bin: firmware.elf
	$(OBJCPY) -O binary $< $@

firmware.elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

flash: firmware.bin
	st-flash --reset write $< $(MEMADDR)

clean:
	rm -f $(LIB_SRC)/*.o *.o *.elf *.bin

