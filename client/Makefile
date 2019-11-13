CXX = g++
LIBS = -pthread

.PHONY: clean

all: client.o client.out

client.out: client.o
	$(CXX) client.o $(LIBS) -o client.out

client.o: client.cpp client.hpp
	$(CXX) -c client.cpp

clean:
	rm -f *.o *.out
