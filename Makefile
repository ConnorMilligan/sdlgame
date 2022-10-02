SHELL = /bin/sh

CC=g++
CFLAGS=-Wall -g
DEPS = game.h sprite.h
OBJ = main.o game.o sprite.o
LIBS = -lSDL2 -lGLEW -lGL

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main