# stm32f4 port makefile

EXEC = stm32f4_lwhal
CC = gcc
LINKER = gcc

lwHAL_SRC = src
STM32F4_SRC = ../../src

SOURCES = \
$(lwHAL_SRC)/test.c \
$(lwHAL_SRC)/stm32f4_gpio.c \
$(STM32F4_SRC)/gpio.c \
$(STM32F4_SRC)/pin.c

OBJECTS = \
test.o \
stm32f4_gpio.o \
gpio.o \
pin.o

#OPT = -O3
OPT = -g

CFLAGS = -Wall -Wextra -Wunused-function
CFLAGS += $(OPT)

LFLAGS =
#-ledit
INCLUDES = -I./$(lwHAL_SRC) -I./$(STM32F4_SRC)

all:
	@echo " ### lwHAL STM32F4 ### "
	$(CC) -c $(INCLUDES) $(SOURCES) $(CFLAGS)
	@echo " <Compilation completed!> "

	$(LINKER) $(OBJECTS) $(LFLAGS) -o $(EXEC)
	@echo " <Linking completed!> "
	make clean

nolink:
	$(CC) -c $(INCLUDES) $(SOURCES) $(CFLAGS)

prof:
	$(CC) -Wall -pg $(INCLUDES) $(SOURCES) -o $(EXEC) -fstack-usage

.PHONY: clean

clean:
	rm $(OBJECTS)
	@echo " <Objects files removed!> "


	-c $(INCLUDES) $(SOURCES) $(CFLAGS)
