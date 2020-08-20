CC=clang
CFLAGS=-g

binconvert: main.c
	$(CC) $(CFLAGS) -o $@ $^

install:
	cp binconvert ~/.local/bin/binconvert
