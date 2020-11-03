#include "includes.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

using std::vector;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void printVector( vector<point>& pts )
{
	for (int i = 0; i < pts.size(); i++)
		cout << pts[i].x << " " << pts[i].y << endl;
}

void buildPts( vector<point>& pts )
{
//Pre  : Vector of point structs has been declared
//Post : Vector of point structs has been initialized with points
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			point p (j, i);
			pts.push_back(p);
		}
	}
}

int findMinDistance( vector<point>& pts ) 
{
//Pre  : Vector of point structs has been initalized and sent into the main algorithm handler
//Post : The index of the next unvisited point with smallest distance from source is returned
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
//Pre  : Index of smallest distance from source has been found
//Post : Distances for the adjecent points are updated if applicable
	
	//The four adjecent points to the current index
	int up = index + rows, down = index - rows, left = index - 1, right = index + 1;

	//Used to make sure adjacent left and right points do not overflow into next or previous row
	int indexRow = index / rows;	

	//If up point exists and is not visited, try to update distance
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
}

//Keep this around because you never know
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
		sleep_for(milliseconds(10));
		display();
	}

	current = end;
}
