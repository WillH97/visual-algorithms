#include "globals.h"
#include "prototypes.h"

void keyboard( unsigned char key, int x, int y )
{
    if ( key == 'e' ) exit(0);

	else if ( key == 'r' ) {
		randomize(nums);
		display();
	}

	else if ( key == 'b' ) {
		bubbleSort(nums);
		display();
	}

	else if ( key == 'c' ) {
		cocktailSort(nums);
		display();
	}

	else if ( key == 's' ) {
		selectionSort(nums);
		display();
	}

	else if ( key == 'm' ) {
		mergeSort(nums, 0, rows);
		display();
	}

    else if ( key == 'h' ) {
        heapSort(nums);
        display();
    }

	else if ( key == 'q' ) {
		quickSort(nums, 0, rows);
		display();
	}

    else if ( key == 'x' ) {
        radixSort(nums, rows);
        display();
    }
}