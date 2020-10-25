dijkstra : main.o includes.h globals.h prototypes.h
	g++ -o dijkstra main.o display.o keyboardmouse.o dijkstra.o -lGL -lGLU -lglut

display.o : display.cpp
	g++ -c display.cpp

keyboardmouse.o : keyboardmouse.cpp
	g++ -c keyboardmouse.cpp

dijkstra.o : dijkstra.cpp
	g++ -c dijkstra.cpp

main.o : main.cpp display.o keyboardmouse.o dijkstra.o
	g++ -c main.cpp 