CFLAGS=-Wall -Wextra -DDEBUG -g -std=c++14 -c
CFLAGS2=-Wall -Wextra -DDEBUG -g -std=c++14
P=program1

all: $(P).o Star.o Planet.o Vector.o
	g++ $(CFLAGS2) $(P).o Vector.o Planet.o Star.o -o $(P)
$(P).o: $(P).cpp
	g++ $(CFLAGS) $(P).cpp
Vector.o: Vector.cpp
	g++ $(CFLAGS) Vector.cpp
Starvector.o: Starvector.cpp
	g++ $(CFLAGS) Starvector.cpp
Star.o: Star.cpp
	g++ $(CFLAGS) Star.cpp
Planet.o: Planet.cpp
	g++ $(CFLAGS) Planet.cpp
run: all
	./$(P)
clean:
	rm -rf $(P) *.o
memcheck:
	valgrind ./$(P)
