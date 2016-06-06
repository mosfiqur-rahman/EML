CC=gcc
CFLAGS=-c -Wall

all: test

test: test.o common_eml.o
    $(CC) test.o common_eml.o -o test

main.o: main.c
    $(CC) $(CFLAGS) main.c

clean:
    rm *o test
