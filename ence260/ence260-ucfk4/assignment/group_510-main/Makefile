# Makefile for the program.
#
# Author:
# - Yang Zhang (yzh365)

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out


# Compile: create object files from C source files.
action.o: action.c action.h ../../drivers/avr/system.h ../../drivers/display.h ../../fonts/font5x7_1.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

button.o: ../../drivers/button.c ../../drivers/avr/system.h ../../drivers/avr/pio.h ../../drivers/button.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

game.o: game.c ../../drivers/avr/system.h ../../drivers/display.h ../../fonts/font5x7_1.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h ../../drivers/navswitch.h ../../drivers/avr/ir_uart.h
	$(CC) -c $(CFLAGS) $< -o $@

gameinit.o: gameinit.c gameinit.h ../../drivers/avr/system.h ../../utils/tinygl.h ../../utils/pacer.h ../../fonts/font5x7_1.h ../../drivers/display.h ../../utils/font.h ../../drivers/navswitch.h ../../drivers/avr/ir_uart.h ../../drivers/avr/pio.h ../../drivers/button.h
	$(CC) -c $(CFLAGS) $< -o $@

ir_uart.o: ../../drivers/avr/ir_uart.c ../../drivers/avr/ir_uart.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/avr/timer0.h ../../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/ledmat.h ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/navswitch.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../utils/pacer.h ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

prescale.o: ../../drivers/avr/prescale.c ../../drivers/avr/prescale.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

rules.o: rules.c rules.h ../../drivers/avr/system.h ../../drivers/display.h  ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/timer.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer0.o: ../../drivers/avr/timer0.c ../../drivers/avr/timer0.h ../../drivers/avr/system.h ../../drivers/avr/bits.h ../../drivers/avr/prescale.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../utils/tinygl.h ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

usart1.o: ../../drivers/avr/usart1.c ../../drivers/avr/system.h ../../drivers/avr/pio.h ../../drivers/button.h
	$(CC) -c $(CFLAGS) $< -o $@

# Link: create ELF output file from object files.
game.out: action.o button.o display.o font.o game.o gameinit.o ir_uart.o ledmat.o navswitch.o pacer.o pio.o prescale.o rules.o system.o timer.o timer0.o tinygl.o usart1.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.out
	$(OBJCOPY) -O ihex game.out game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start


