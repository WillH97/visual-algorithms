#include "includes.h"
#include "globals.h"
#include "structs.h"

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
