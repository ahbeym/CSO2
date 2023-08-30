#Group: Ahbey Mesfin, Simon Anderson,

CC = clang
CFLAGS = -g 
LDFLAGS = -Wall #static?

.PHONY: all clean

#all and clean targets
all: libsay.so guesser

clean:
	rm cheer.o grunt.o guesser.o libsay.so guesser
##

#build each .c file into a .o file
cheer.o: cheer.c say.h
	$(CC) -c cheer.c

grunt.o: grunt.c say.h
	$(CC) -c grunt.c

guesser.o: guesser.c say.h
	$(CC) -c guesser.c
##

#combine cheer.o and grunt.o into library
libsay.so: cheer.o grunt.o say.h
	$(CC) $(LDFLAGS) $(CFLAGS) -fPIC -c cheer.o grunt.o
	$(CC) -shared grunt.o cheer.o -o $@ 

##

#$@ is the same as saying libsay.so for this rule ^

#building guesser
guesser: guesser.o
	$(CC) cheer.o grunt.o guesser.o -L./ -lsay -Wl,-rpath . -o $@
