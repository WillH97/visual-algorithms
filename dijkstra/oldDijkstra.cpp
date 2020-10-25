#include <iostream>
#include <vector>
#include <chrono> // milliseconds, system_clock
#include <thread> // sleep_for, sleep_until

using std::vector;
using std::cout;
using std::endl;
using namespace std::this_thread;
using namespace std::chrono;

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

//GLOBAL VARIABLES
const GLsizei wsize = 800;
const int rows = 40;
const int h = wsize/rows;
int clickCount = 0;
int source;
int end;
int current;
bool drawPath = true;
double line [4];
vector<point> pts;

void display();

void printVector( vector<point>& pts )
{
	for (int i = 0; i < pts.size(); i++)
		cout << pts[i].x << " " << pts[i].y << endl;
}

void buildPts( vector<point>& pts )
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			point p (j, i);
			pts.push_back(p);
		}
	}
}

int findMinDistance( vector<point>& pts ) 
{
	double min = 10000000;
	int index;

	for (int i = 0; i < pts.size(); i++) {
		if ( !pts[i].visited && !pts[i].wall ) {
			if ( pts[i].distance < min ) {
				min = pts[i].distance;
				index = i;
			}
		}
	}

	return index;
}

void updateDistances( vector<point>& pts, int index ) 
{
	int up = index + rows, down = index - rows, left = index - 1, right = index + 1;
	//int diag1 = up - 1, diag2 = up + 1, diag3 = down - 1, diag4 = down + 1;

	int indexRow = index / rows;	

	if ( up >= 0 && up < pts.size() ) {
		if ( !pts[up].wall ) {
			int newDistance = pts[index].distance + 1;
			if ( newDistance < pts[up].distance ) {
				pts[up].distance = newDistance;
				pts[up].parent = index;
			}
		}
	}

	if ( down >= 0 && down < pts.size() ) {
		if ( !pts[down].wall ) {
			int newDistance = pts[index].distance + 1;
			if ( newDistance < pts[down].distance ) {
				pts[down].distance = newDistance;
				pts[down].parent = index;
			}
		}
	}

	if ( (left / rows) == indexRow ) {
		if ( !pts[left].wall ) {
			int newDistance = pts[index].distance + 1;
			if ( newDistance < pts[left].distance ) {
				pts[left].distance = newDistance;
				pts[left].parent = index;
			}
		}
	}

	if ( (right / rows) == indexRow ) {
		if ( !pts[right].wall ) {
			int newDistance = pts[index].distance + 1;
			if ( newDistance < pts[right].distance ) {
				pts[right].distance = newDistance;
				pts[right].parent = index;
			}
		}
	}

	/*
	if ( (diag1 / rows) == indexRow+1 ) {
		if ( !pts[diag1].wall ) {
			int newDistance = pts[index].distance + 1.4142;
			if ( newDistance < pts[diag1].distance ) {
				pts[diag1].distance = newDistance;
				pts[diag1].parent = index;
			}
		}
	}

	if ( (diag2 / rows) == indexRow+1 ) {
		if ( !pts[diag2].wall ) {
			int newDistance = pts[index].distance + 1.4142;
			if ( newDistance < pts[diag2].distance ) {
				pts[diag2].distance = newDistance;
				pts[diag2].parent = index;
			}
		}
	}

	if ( (diag3 / rows) == indexRow-1 ) {
		if ( !pts[diag3].wall ) {
			int newDistance = pts[index].distance + 1.4142;
			if ( newDistance < pts[diag3].distance ) {
				pts[diag3].distance = newDistance;
				pts[diag3].parent = index;
			}
		}
	}

	if ( (diag4 / rows) == indexRow-1 ) {
		if ( !pts[diag4].wall ) {
			int newDistance = pts[index].distance + 1.4142;
			if ( newDistance < pts[diag4].distance ) {
				pts[diag4].distance = newDistance;
				pts[diag4].parent = index;
			}
		}
	}
	*/
}

void debug( int x )
{
	cout << "we made it to" << " " << x << endl;
}

void runAlgorithm( vector<point>& pts )
{
	pts[source].distance = 0;

	while ( !pts[end].visited ) {
		int index = findMinDistance(pts);
		pts[index].visited = true;
		updateDistances(pts, index);

		current = index;
		sleep_for(milliseconds(50));
		display();
	}

	current = end;
}