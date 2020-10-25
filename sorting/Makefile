sort : main.o includes.h globals.h prototypes.h
	g++ -o sort main.o display.o keyboard.o sortingalgos.o helpers.o -lGL -lGLU -lglut

display.o : display.cpp
	g++ -c display.cpp

keyboard.o : keyboard.cpp
	g++ -c keyboard.cpp

sortingalgos.o : sortingalgos.cpp display.o helpers.o
	g++ -c sortingalgos.cpp

helpers.o : helpers.cpp
	g++ -c helpers.cpp 

main.o : main.cpp display.o keyboard.o sortingalgos.o helpers.o
	g++ -c main.cpp 