CC=g++
CFLAGS=-Wall -Wextra
HFILES=tree.hh node.hh
all: tree

tree: $(HFILES) main.cc
	$(CC) $(CFLAGS) -o tree main.cc

clean: 
	rm tree 