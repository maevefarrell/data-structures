P = lab8
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(P).o
	g++ Hash.o $(P).o -o $(P)

$(P).o: Hash.o
	g++ -c $(CFLAGS) -c $(P).cpp

Hash.o: Hash.cpp Hash.h
	g++ $(CFLAGS) -c Hash.cpp

run: all
	./$(P)

clean:
	rm *.o $(P)

memcheck: all
	valgrind ./$(P)
