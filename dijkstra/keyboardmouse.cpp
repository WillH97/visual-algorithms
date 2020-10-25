#include "includes.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

using std::cout;
using std::endl;

void mouse( int button, int state, int x, int y )
{ 
    y = wsize - y;

    if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
	// create point on the bottom left of square that user clicked on
		int x1, y1;
		for (int i = 0; i < x; i += h)
			x1 = i / h;

		for (int i = 0; i < y; i += h)
			y1 = i / h;

		cout << x1 << " " << y1 << endl;

		if ( clickCount < 2 ) {
			if ( clickCount < 1 ) 
				source = x1 + (y1 * rows);
			
			else 
				end = x1 + (y1 * rows);

			clickCount++;
		}

		else 
			pts[x1+(y1*rows)].wall = true;

		display();
	}

    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
    	line[0] = (double)x;
    	line[1] = (double)y;
    }

    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_UP ) {
    	line[2] = (double)x;
    	line[3] = (double)y;

    	if ( line[0] > line[2] ) {
    		double tempx = line[0];
    		double tempy = line[1];
    		line[0] = line[2];
    		line[1] = line[3];
    		line[2] = tempx;
    		line[3] = tempy;
    	}

    	double m = (line[3] - line[1]) / (line[2] - line[0]);
    	double length = line[2] - line[0];

    	for (double i = 0; i < length; i += length/50) {
    		int x1, y1; 
    		
    		for (int j = 0; j < line[0] + i; j += h)
    			x1 = j / h;

	    	for (int j = 0; j < line[1] + (i*m); j += h)
    			y1 = j / h;

    		cout << x1 << " " << y1 << endl;

    		pts[x1+(y1*rows)].wall = true;
    	}

    	display();
    }
}

void keyboard( unsigned char key, int x, int y )
{
	if ( key == 'q' ) 
		exit(0);

	else if ( key == 'r' ) {
		pts.clear();
		buildPts(pts);
		clickCount = 0;
		source = -10;
		end = -10;
		display();
	}

	else if ( key == 'd' ) {
		runAlgorithm(pts);
		cout << pts[end].distance << endl;
		display();
	}

	else if ( key == 'p' ) {
		if ( drawPath ) {
			drawPath = false;
			display();
		}

		else {
			drawPath = true;
			display();
		}
	}

	else if ( key = 'g' ) {
		//generateRandomPoints(pts);
		display();
	}
}