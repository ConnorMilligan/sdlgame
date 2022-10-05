SHELL = /bin/sh

CC=g++
CFLAGS=-Wall -g
DEPS = 
OBJ = main.o 

ifeq ($(OS),Windows_NT)
	LIBS = -lmingw32 -lSDL2main -lSDL2 -mwindows
else 
	LIBS = -lSDL2
endif

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main