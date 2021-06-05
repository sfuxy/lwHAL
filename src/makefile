# @Author: SIlvano
# @Date:   2021-06-03T07:46:59-07:00
# @Last modified by:   SIlvano
# @Last modified time: 2021-06-05T05:05:51-07:00

# makefile

EXEC = lwhal
CC = gcc
LINKER = gcc

SOURCES = \
main.c \
pin.c \
gpio.c

OBJECTS = \
main.o \
pin.o \
gpio.o

#OPT = -O3
OPT = -g

CFLAGS = -Wall -Wextra -Wunused-function
CFLAGS += $(OPT)

LFLAGS =
#-ledit
INCLUDES = -I.

all:
	@echo " ### lwHAL ### "
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
