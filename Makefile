SHELL = /bin/sh

CC=g++
CFLAGS=-Wall -g
DEPS = 
OBJ = main.o 
LIBS = -lSDL2

# Add required compiler flags for windows mingw
ifeq ($(OS),Windows_NT)
	LIBS += -lmingw32 -lSDL2main -mwindows
endif

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

clean:
	-rm -f *.o main