# Variables
JFLAGS = -g
JC = javac
JVM = java

SRCS := $(wildcard *.java)
CLS := $(SRCS:.java=.class)
OUT := main

${CLS} : %.class: 
	${JC} ${JFLAGS} ${SRCS}

run:
	make
	${JVM} ${OUT}

clean:
	rm *.class