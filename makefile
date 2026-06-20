all: main.o
	g++ -Wall -std=c++11 -o solver main.o
main.o: main.cc
	g++ -Wall -std=c++11 -c main.cc
clean:
	rm -f *.o solver