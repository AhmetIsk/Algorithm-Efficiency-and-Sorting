/*
* Title: Algorithm Efficiency and Sorting
* Author: Ahmet Isik
* ID: 21702226
* Section: 2
* Assignment: 1
* Description: There are 3 main and 5 helper method which composes
* the insertion, merge and quick sort algorithms
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#include "sorting.h"


void insertionSort(int *arr, int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    for (int unsorted = 1; unsorted < size; ++unsorted) {

    int nextItem = arr[unsorted];
    int loc = unsorted;
    moveCount++;
    compCount++;
    for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
        arr[loc] = arr[loc-1];
        moveCount++;
        compCount++;
    }
    arr[loc] = nextItem;
    moveCount++;
    }
}
void swap(int &x, int &y) {
   int temp = x;
   x = y;
   y = temp;
}

void partition(int theArray[], int first, int last,
			int &pivotIndex, int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

	// place pivot in theArray[first]
   //choosePivot(theArray, first, last);

   int pivot = theArray[first]; // copy pivot

   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
    	  moveCount+=3;
      }	// else belongs to S2
      compCount++;
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
   moveCount+=3;
}

void helperQuicksort(int theArray[], int first, int last, int size, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

   if (first<last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      helperQuicksort(theArray, first, pivotIndex-1, size, compCount, moveCount);
      helperQuicksort(theArray, pivotIndex+1, last, size, compCount, moveCount);
   }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount) {
    int low = 0;
    int high = size - 1;
    compCount = 0;
    moveCount = 0;
    helperQuicksort(arr, low, high, size, compCount, moveCount);
}
void merge( int theArray[], int first, int mid, int last, int size, int &compCount, int &moveCount) {

	int tempArray[size]; 	// temporary array

	int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      compCount++;
      if (theArray[first1] < theArray[first2]) {
         tempArray[index] = theArray[first1];
         ++first1;
         moveCount++;
      }
      else {
          tempArray[index] = theArray[first2];
          ++first2;
          moveCount++;
      }
   }
   	// finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      tempArray[index] = theArray[first1];
      moveCount++;

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      tempArray[index] = theArray[first2];
      moveCount++;

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];
      moveCount++;
}

void helperMergesort( int theArray[], int first, int last, int size, int &compCount, int &moveCount) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      helperMergesort(theArray, first, mid, size, compCount, moveCount);

      helperMergesort(theArray, mid+1, last, size, compCount, moveCount);

      // merge the two halves
      merge(theArray, first, mid, last, size, compCount, moveCount);
   }
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount) {
    int first = 0;
    int last = size - 1;
    compCount = 0;
    moveCount = 0;
    helperMergesort(arr, first, last, size, compCount, moveCount);
}

