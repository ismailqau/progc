CC      = gcc
CFLAGS  = -g

default: main run

cr: main run

all: main

main: ./src/main.c
	$(CC) $(CFLAGS) -o ./src/main ./src/main.c

run:
	./src/main
