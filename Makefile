CC=gcc
CFLAGS=-std=c++11

all: hypergraph.o

hypergraph.o: hypergraph.hpp
	$(CC) $(CFLAGS) -o hypergraph.o -c hypergraph.hpp

clean:
	rm *.o
