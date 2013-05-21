all: main

calc.o: calc.cpp calc.hpp
	g++ -c calc.cpp

point.o: point.cpp point.hpp calc.o
	g++ -c point.cpp 

main.o: main.cpp
	g++ -c main.cpp

main: main.o point.o calc.o
	g++ main.o point.o calc.o -o tutorat -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU

clean: 
	rm -rf *.o
