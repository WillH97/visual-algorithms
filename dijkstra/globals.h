#ifndef GLOBALS_H
#define GLOBALS_H

#include "includes.h"
#include "structs.h"

const GLsizei wsize = 800;
const int rows = 40;
const int h = wsize/rows;
extern int clickCount;
extern int source;
extern int end;
extern int current;
extern bool drawPath;
extern double line [];
extern std::vector<point> pts;

#endif