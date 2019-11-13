CXX = g++
LIBS = -pthread

.PHONY: clean

all: server.o server.out

server.out: server.o
	$(CXX) server.o $(LIBS) -o server.out

server.o: server.cpp server.hpp
	$(CXX) -c server.cpp

clean:
	rm -f *.o *.out
