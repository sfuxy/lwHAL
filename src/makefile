# makefile

EXEC = lwhal
CC = gcc
LINKER = gcc

SOURCES = \
test.c \
pin.c \
gpio.c

OBJECTS = \
test.o \
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
