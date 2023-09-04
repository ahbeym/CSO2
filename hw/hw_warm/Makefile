
.PHONY: all clean

all: split

clean:
	rm -f split *.o

split.o: split.c split.h
	clang -c split.c

main.o: main.c split.h
	clang -c main.c 

split: main.o split.o
	clang split.o main.o -o split