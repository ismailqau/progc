CC      = gcc
CFLAGS  = -g
RM      = rm -f


default: main run

all: main

main: ./src/main.c
	$(CC) $(CFLAGS) -o ./src/main ./src/main.c

run:
	./src/main

clean veryclean:
	$(RM) ./src/main