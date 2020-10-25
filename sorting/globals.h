#ifndef GLOBALS_H
#define GLOBALS_H
#include "includes.h"

enum DrawType { rect, stair, circle, spiral }; // four currently implemented methods for animating the data

const GLsizei wsize = 800;
const int rows = 100; // should evenly divide window size
const int width = wsize / rows;
const int delay = 10; // num of milliseconds in each delay call
extern DrawType drawtype; // change this to change animation style
const int PI = 3.1415;
extern int nums [];

#endif