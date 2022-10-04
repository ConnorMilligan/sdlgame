SHELL = /bin/sh

CC=g++
CFLAGS=-Wall -g
DEPS = 
OBJ = main.o 
LIBS = -lSDL2 

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main