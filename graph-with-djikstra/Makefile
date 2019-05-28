P = program3
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(P).o
	g++ Galaxy.o Planet.o  $(P).o -o $(P)

$(P).o: Galaxy.o Planet.o
	g++ -c $(CFLAGS) -c $(P).cpp 

Galaxy.o: Galaxy.cpp Galaxy.h
	g++ $(CFLAGS) -c Galaxy.cpp

Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp

run: all
	./$(P)

clean:
	rm *.o $(P)

memcheck: all
	valgrind --track-origins=yes --leak-check=full ./$(P)
