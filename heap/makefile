CFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: program2

program2: program2.o Planet.o Parser.o Scanner.o
	g++ $(CFLAGS) program2.o Planet.o Parser.o Scanner.o -o program2
program2.o: program2.cpp
	g++ $(CFLAGS) -c program2.cpp -o program2.o
Planet.o: Planet.h Planet.cpp Heap.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o
Parser.o: Parser.h Parser.cpp
	g++ $(CFLAGS) -c Parser.cpp -o Parser.o
Scanner.o: Scanner.h Scanner.cpp
	g++ $(CFLAGS) -c Scanner.cpp -o Scanner.o
memcheck: all
	valgrind --leak-check=full ./program2
run: all
	./program2
clean:
	rm -rf *.o program2
