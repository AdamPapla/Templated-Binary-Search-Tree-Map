CC=g++
CFLAGS=-Wall -Wextra
HFILES=map.hh node.hh
all: map

map: $(HFILES) main.cc
	$(CC) $(CFLAGS) -o map main.cc

clean: 
	rm map