main: main.o vector.o
	g++ main.o vector.o -o main

main.o: main.cpp
	g++ -c main.cpp -std=c++11

vector.o: vector.cpp
	g++ -c vector.cpp -std=c++11

clean:
	rm *.o main