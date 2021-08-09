CFLAGS=-Wall -Wextra -Werror -Wpedantic -g
CC=clang $(CFLAGS)

all: lrc

lrc: lrc.o
	$(CC) -o lrc lrc.o
lrc.o: lrc.c
	$(CC) $(CFLAGS) -c lrc.c
clean:
	rm -f lrc lrc.o
infer:
	make clean; infer-capture -- make; infer-analyze -- make
clang:
	clang-format -i -style=file *.c
