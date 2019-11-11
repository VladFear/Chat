CXX = g++
LIBS = -pthread

all: server client

server.out: server.o
	$(CXX) server.o $(LIBS) -o server.out

server.o: server.cpp server.hpp
	$(CXX) -c server.cpp

client.out: client.o
	$(CXX) client.o $(LIBS) -o client.out

client.o: client.cpp client.hpp
	$(CXX) -c client.cpp

clean:
	rm -f *.o
