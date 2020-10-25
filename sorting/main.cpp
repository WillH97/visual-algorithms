#include "includes.h"
#include "globals.h"
#include "prototypes.h"

DrawType drawtype = rect;
int nums [rows];

void init( int argc, char* argv[] )
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(wsize, wsize); /* set pixel window */
    glutCreateWindow("Sorting Algorithms"); /* window title */

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (double)wsize, 0.0, (double)wsize);
}

int main( int argc, char* argv[] )
{
    std::cout << "ayyy we got here" << std::endl;
	srand(time(0));
	buildNums(nums);
    
	init(argc, argv);
    glutKeyboardFunc(keyboard); /* Define Keyboard Handler */
    glutDisplayFunc(display); /* Display callback invoked when window opened */
    glutMainLoop(); /* enter event loop */

    return 0;
}