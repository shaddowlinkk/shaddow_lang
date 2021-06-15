CC = gcc
CFLAGS = -c -std=c99 -g
LDFFLAGS = -g
SRC = ${wildcard src/*.c}
HDR = ${wildcard include/*.h}
OBJ = ${SRC:.c=.o}
EXEC = mycomp

all: ${SRC} ${OBJ} ${EXEC}

${EXEC}: ${OBJ}
	${CC} ${LDFFLAGS} $^ -o $@
%.o: %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@
clean:
	rm src/*.o ${EXEC}
	