P = lab5
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(P).o
	g++ Planet.o Star.o Probe.o $(P).o -o $(P)

$(P).o: Star.o Planet.o Probe.o
	g++ -c $(CFLAGS) -c $(P).cpp

Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp

Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp

Probe.o: Probe.cpp Probe.h
	g++ $(CFLAGS) -c Probe.cpp

run: all
	./$(P)

clean:
	rm *.o $(P)

memcheck: all
	valgrind ./$(P)
