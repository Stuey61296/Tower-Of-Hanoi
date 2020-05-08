# Variables
CC=g++
CFLAGS = -c -Wall
all: main

main: main.o towerPole.o poleNode.o tower.o
	$(CC) main.o towerPole.o poleNode.o tower.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
towerPole.o: towerPole.cpp
	$(CC) $(CFLAGS) towerPole.cpp
poleNode.o: poleNode.cpp
	$(CC) $(CFLAGS) poleNode.cpp
tower.o : tower.cpp
	$(CC) $(CFLAGS) tower.cpp

clean_windows:
	del *.o main.exe

clean:
	rm *.o main

run_windows:
	make && .\main.exe

run:
	make && ./main