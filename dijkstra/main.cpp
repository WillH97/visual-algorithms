#include "includes.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

int clickCount = 0;
int source;
int end;
int current;
bool drawPath = true;
double line [4];
std::vector<point> pts;

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