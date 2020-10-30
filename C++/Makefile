# Variables
CC=g++
CFLAGS = -c -Wall

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:.cpp=.o)
OUT := main

.PHONY = ${OUT} clean

${OUT} : ${BINS}
	${CC} ${BINS} -o ${OUT}

%: %.o
	${CC} ${CFLAGS} $< -o $@

%.o: %.cpp
	${CC} -c $<

run:
	make
	./${OUT}

clean:
	rm *.o main