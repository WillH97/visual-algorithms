#include "globals.h"
#include "includes.h"

void display( )
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8, 0.3, 0.3);

    if ( drawtype == rect ) {
	    for (int i = 0; i < rows; i++) {
	    	glBegin(GL_POLYGON);
	    		glVertex2i(i*width + 1, 0);
	    		glVertex2i(i*width + width - 1, 0);
	    		glVertex2i(i*width + width - 1, nums[i] - 1);
	    		glVertex2i(i*width + 1, nums[i] - 1);
	    	glEnd();
	    }
	}

	else if ( drawtype == stair ) {
		for (int i = 0; i < rows; i++) {
	    	glBegin(GL_POLYGON);
	    		glVertex2i(i*width, 0);
	    		glVertex2i(i*width + width, 0);
	    		glVertex2i(i*width + width, nums[i]);
	    		glVertex2i(i*width, nums[i]);
	    	glEnd();
	    }
	}

    else if ( drawtype == circle ) {
        glPointSize(5);
        for (double i = 0; i < rows; i++) {
            glBegin(GL_POINTS);
                int offset = wsize/2 - abs(((nums[(int)i]*rows) / wsize) - i);
                if (offset < 0)
                    offset = 0;
                float x = offset * cos( (i*2*PI) / rows ) + (wsize/2); 
                float y = offset * sin( (i*2*PI) / rows ) + (wsize/2);
                glVertex2f(x, y);
            glEnd();
        }
    }

    else if ( drawtype == spiral ) {
        glPointSize(5);
        for (double i = 0; i < rows; i++) {
            glBegin(GL_POINTS);
                float x = (nums[(int)i]/2) * cos( (i*2*PI) / rows ) + (wsize/2); 
                float y = (nums[(int)i]/2) * sin( (i*2*PI) / rows ) + (wsize/2);
                glVertex2f(x, y);
            glEnd();
        }
    }

    glFlush();
}