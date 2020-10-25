#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "includes.h"

// glut I/O
void mouse( int button, int state, int x, int y );
void keyboard( unsigned char key, int x, int y );
void display( );
void displayPath( );

void buildPts( std::vector<point>& pts );
void runAlgorithm( std::vector<point>& pts );

#endif