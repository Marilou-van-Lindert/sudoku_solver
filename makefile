all: solver.o
	g++ -Wall -std=c++11 -o solver solver.o
solver.o: solver.cc solver.h
	g++ -Wall -std=c++11 -c solver.cc
clean:
	rm -f *.o solver