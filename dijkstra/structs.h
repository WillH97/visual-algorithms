#ifndef STRUCTS_H
#define STRUCTS_H

struct point {
	int x;
	int y;
	double distance;
	bool visited;
	bool wall;
	int parent;

	point () { }
	point (int x, int y) {
		this -> x = x;
		this -> y = y;
		this -> distance = 1000000;
		this -> visited = false;
		this -> wall = false;
		this -> parent = -1;
	}
};

#endif