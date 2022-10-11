CC = gcc
CPP = g++
CFLAGS = -Wall -g
EXE = main

all: $(EXE)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.dSYM *.o $(EXE)