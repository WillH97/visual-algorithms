#include "includes.h"
#include "globals.h"
#include "prototypes.h"

using std::chrono::milliseconds;
using std::this_thread::sleep_for;

void bubbleSort( int nums[rows] )
{
	for (int i = 0; i < rows-1; i++) {
		for (int j = 0; j < rows-i-1; j++ ) {
			if ( nums[j] > nums[j+1] ) {
				swap(nums, j, j+1);

				sleep_for(milliseconds(delay));
				display();
			}
		}
	}
}

void cocktailSort( int nums[rows] ) 
{ 
    bool swapped = true;
    int start = 0;
    int end = rows - 1;
  
    while (swapped) { 
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false; 
  
        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i) { 
            if (nums[i] > nums[i + 1]) { 
                swap(nums, i, i+1);

				sleep_for(milliseconds(delay));
				display();

                swapped = true; 
            } 
        } 
  
        // if nothing moved, then array is sorted. 
        if (!swapped) 
            break; 
  
        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false; 
  
        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end; 
  
        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i) { 
            if (nums[i] > nums[i + 1]) { 
                swap(nums, i, i+1);

				sleep_for(milliseconds(delay));
				display();

                swapped = true; 
            } 
        } 
  
        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start; 
    } 
} 

void selectionSort( int nums[rows] )  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < rows-1; i++) {  
        // Find the minimum element in unsorted array  
        min_idx = i;
        //sleep_for(milliseconds(delay));
        //display();
        for (j = i+1; j < rows; j++) {
        	if (nums[j] < nums[min_idx]) {
            	min_idx = j; 
            	sleep_for(milliseconds(delay));
				display();
        	}
        }
  
        // Swap the found minimum element with the first element 
        swap(nums, min_idx, i);

        sleep_for(milliseconds(delay));
        display();
    }  
}  

void merge( int nums[rows], int low, int mid, int high )
{
	int i, j, k; 
    int n1 = mid - low + 1; 
    int n2 = high - mid; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = nums[low + i];

    for (j = 0; j < n2; j++) 
        R[j] = nums[mid + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = low; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            nums[k] = L[i]; 
            i++; 

            sleep_for(milliseconds(delay));
			display();
        } 
        else { 
            nums[k] = R[j]; 
            j++; 

            sleep_for(milliseconds(delay));
			display();
        } 
        k++; 
    } 

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        nums[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        nums[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort( int nums[rows], int low, int high )
{
	if ( high > low ) {
		int mid = (low + high) / 2;
		mergeSort(nums, low, mid);
		mergeSort(nums, mid+1, high);
		merge(nums, low, mid, high);
	}
}

void heapify( int nums[rows], int n, int i ) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if ( l < n && nums[l] > nums[largest] ) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if ( r < n && nums[r] > nums[largest] ) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(nums, i, largest);

        sleep_for(milliseconds(delay));
        display();

        // Recursively heapify the affected sub-tree 
        heapify(nums, n, largest); 
    } 
} 

void heapSort( int nums[rows] )
{
    // Build heap (rearrange array) 
    for (int i = rows / 2 - 1; i >= 0; i--) 
        heapify(nums, rows, i); 
  
    // One by one extract an element from heap 
    for (int i=rows-1; i > 0; i--) { 
        // Move current root to end 
        swap(nums, 0, i); 
  
        sleep_for(milliseconds(delay));
        display();

        // call max heapify on the reduced heap 
        heapify(nums, i, 0); 
    } 
}

int partition( int nums[rows], int low, int high )
{
	int pivot = nums[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++) {  
        // If current element is smaller than the pivot  
        if (nums[j] < pivot) {  
            i++; // increment index of smaller element  
			swap(nums, i, j);

			sleep_for(milliseconds(delay));
			display();
        }  
    }
    swap(nums, i+1, high);

    sleep_for(milliseconds(delay));
    display();

    return (i + 1);  
}

void quickSort( int nums[rows], int low, int high )
{
	if (low < high) {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(nums, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(nums, low, pi - 1);  
        quickSort(nums, pi + 1, high);  
    }
}

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) {
        arr[i] = output[i]; 
        sleep_for(milliseconds(delay));
        display();
    }
} 

void radixSort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
} 