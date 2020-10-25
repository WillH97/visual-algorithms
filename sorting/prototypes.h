#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "globals.h"
// keyboard and display
void keyboard( unsigned char key, int x, int y );
void display();

// sorting algorithms
void bubbleSort( int nums[rows] );
void cocktailSort( int nums[rows] );
void selectionSort( int nums[rows] );
void mergeSort( int nums[rows], int low, int high );
void heapSort( int nums[rows] );
void quickSort( int nums[rows], int low, int high );
void radixSort(int arr[], int n);

// helper functions
void randomize( int nums[rows] );
void buildNums( int nums[rows] );
void swap( int nums[rows], int i, int j );

#endif