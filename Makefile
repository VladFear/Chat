CXX = g++
LIBS = -pthread

all: server

server.out: server.o
	$(CXX) server.o $(LIBS) -o server.out

server.o: server.cpp server.hpp
	$(CXX) -c server.cpp

clean:
	rm -f *.o
