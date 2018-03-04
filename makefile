CC=gcc
CFLAGS=-I. -Wall -Werror -Wextra
DEPS = debug.h, common.h, chunk.h, memory.h, value.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clox: main.o debug.o chunk.o memory.o value.o
	$(CC) -o clox main.o debug.o chunk.o memory.o value.o $(CFLAGS)

clean:
	-rm clox *.o

.PHONY: debug
debug: CFLAGS += -ggdb
debug: clean clox
