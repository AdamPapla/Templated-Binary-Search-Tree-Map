CC=g++
CFLAGS=-Wall -Wextra
SFILES=tree.cc
all: tree

tree: tree.hh tree.o main.cc
	$(CC) $(CFLAGS) -o tree $(SFILES) main.cc

clean: 
	rm tree.o tree 