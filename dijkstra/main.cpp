#include "includes.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

int clickCount = 0; //used by mouse handler to choose if next click will be start, end, or wall 
int source;
int end;
int current;
bool drawPath = true; //toggles path display
double line [4];
std::vector<point> pts;

void init( int argc, char* argv[] )
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(wsize, wsize); /* set pixel window */
    glutCreateWindow("Dijkstra's Algorithm"); /* window title */

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (double)wsize, 0.0, (double)wsize);
}

int main( int argc, char* argv[] )
{
    init(argc, argv);

    //random seed for generating random wall points if user chooses
    srand(time(0));

    buildPts(pts);

    glutMouseFunc(mouse);  /* Define Mouse Handler */
    glutKeyboardFunc(keyboard); /* Define Keyboard Handler */
    glutDisplayFunc(display); /* Display callback invoked when window opened */
    glutMainLoop(); /* enter event loop */

    return 0;
}
