all: main

main.o: main.cpp
	g++ -c main.cpp

main: main.o
	g++ main.o -o tutorat -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU

clean: 
	rm -rf *.o