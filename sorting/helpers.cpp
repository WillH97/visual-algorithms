#include "globals.h"
#include "prototypes.h"

void buildNums( int nums[rows] )
{
	int j = 0;
	for (int i = 0; i < rows; i++) {
		j += wsize / rows;
		nums[i] = j;
	}
}

void swap( int nums[rows], int i, int j )
{
    int k;
    k = nums[i];
    nums[i] = nums[j];
    nums[j] = k;
}

void randomize( int nums[rows] ) 
{
	for (int i = rows-1; i > 0; i--) {
		int j = rand() % i;
		swap(nums, i, j);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		display();
	}
}