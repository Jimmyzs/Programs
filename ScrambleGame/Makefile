all: Scramble
Scramble: main.o Scramble.o
	g++ -std=c++11 -o Scramble main.o Scramble.o
Scramble.o: Scramble.cpp Scramble.h
	g++ -std=c++11 -c Scramble.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm Scramble *.o
