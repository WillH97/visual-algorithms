#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "oldDijkstra.cpp"

using std::vector;

//GLOBAL VARIABLES
//const GLsizei wsize = 800;
//int h = wsize/20;
//vector<point> pts;

void init( int argc, char* argv[] )
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(wsize, wsize); /* set pixel window */
    glutCreateWindow("Polygon Tesselation"); /* window title */

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (double)wsize, 0.0, (double)wsize);
}

void display( )
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

	// draw a box for each wall point
	for (int i = 0; i < pts.size(); i++) {
		if ( pts[i].wall ) {
			// draw box
			glColor3f(0,0,0);
			glBegin(GL_POLYGON);
				glVertex2i( (pts[i].x)*h,  (pts[i].y)*h);
				glVertex2i( (pts[i].x * h) + h, (pts[i].y)*h);
				glVertex2i( (pts[i].x * h) + h, (pts[i].y*h) + h);
				glVertex2i( (pts[i].x)*h,  (pts[i].y * h) + h);
			glEnd();
		} else if ( pts[i].visited ) {
			glColor3f(0.5, 0.5, 0.5);
			glBegin(GL_POLYGON);
				glVertex2i( (pts[i].x)*h,  (pts[i].y)*h);
				glVertex2i( (pts[i].x * h) + h, (pts[i].y)*h);
				glVertex2i( (pts[i].x * h) + h, (pts[i].y*h) + h);
				glVertex2i( (pts[i].x)*h,  (pts[i].y * h) + h);
			glEnd();
		}
	}

	// draw srcPt and endPt
	if ( clickCount > 0 ) {
		glColor3f(0, 0.8, 0);
		glBegin(GL_POLYGON);
			glVertex2i(pts[source].x*h, pts[source].y*h);
			glVertex2i((pts[source].x*h)+h, pts[source].y*h);
			glVertex2i((pts[source].x*h)+h, (pts[source].y*h)+h);
			glVertex2i(pts[source].x*h, (pts[source].y*h)+h);
		glEnd();
	}

	if ( clickCount > 1 ) {
		glColor3f(0.8, 0, 0);
		glBegin(GL_POLYGON);
			glVertex2i(pts[end].x*h, pts[end].y*h);
			glVertex2i((pts[end].x*h)+h, pts[end].y*h);
			glVertex2i((pts[end].x*h)+h, (pts[end].y*h)+h);
			glVertex2i(pts[end].x*h, (pts[end].y*h)+h);
		glEnd();
	}

		glColor3f(0, 0.8, 0);
	    int index = current;
	    while ( pts[index].parent != -1 ) {
	    	glBegin(GL_POLYGON);
					glVertex2i(pts[index].x*h, pts[index].y*h);
					glVertex2i((pts[index].x*h)+h, pts[index].y*h);
					glVertex2i((pts[index].x*h)+h, (pts[index].y*h)+h);
					glVertex2i(pts[index].x*h, (pts[index].y*h)+h);
			glEnd();
			index = pts[index].parent;
		}

	glColor3f(0,0,0);
	// drawing vertical grid lines
	for (int i = 0; i < wsize; i += h) {
		glBegin(GL_LINES);
			glVertex2i(0, i);
			glVertex2i(wsize, i);
		glEnd();
	}

	// drawing horizontal grid lines
	for (int i = 0; i < wsize; i += h) {
		glBegin(GL_LINES);
			glVertex2i(i, 0);
			glVertex2i(i, wsize);
		glEnd();
	}

	/*
	// draw path
	if ( drawPath ) {
		glColor3f(0, 0.8, 0);
	    int index = end;
	    while ( pts[index].parent != -1 ) {
	    	glBegin(GL_POLYGON);
					glVertex2i(pts[index].x*h, pts[index].y*h);
					glVertex2i((pts[index].x*h)+h, pts[index].y*h);
					glVertex2i((pts[index].x*h)+h, (pts[index].y*h)+h);
					glVertex2i(pts[index].x*h, (pts[index].y*h)+h);
			glEnd();

			index = pts[index].parent;
	    }
	}
	*/
	glFlush();
}

void displayPath( )
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0.8, 0);

    int index = end;
    while ( pts[index].parent != -1 ) {
    	glBegin(GL_POLYGON);
				glVertex2i(pts[index].x*h, pts[index].y*h);
				glVertex2i((pts[index].x*h)+h, pts[index].y*h);
				glVertex2i((pts[index].x*h)+h, (pts[index].y*h)+h);
				glVertex2i(pts[index].x*h, (pts[index].y*h)+h);
		glEnd();

		index = pts[index].parent;
    }

    glFlush();
}

void generateRandomPoints( vector<point>& pts )
{
	for (int i = 0; i < 100; i++) {
		int random = rand() % (rows*rows);
			if ( random != source && random != end )
				pts[random].wall = true;
	}
}

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
		generateRandomPoints(pts);
		display();
	}
}

int main( int argc, char* argv[] )
{
    init(argc, argv);

	srand(time(0));

    buildPts(pts);

    glutMouseFunc(mouse);  /* Define Mouse Handler */
    glutKeyboardFunc(keyboard); /* Define Keyboard Handler */
    glutDisplayFunc(display); /* Display callback invoked when window opened */
    glutMainLoop(); /* enter event loop */

    return 0;
}
