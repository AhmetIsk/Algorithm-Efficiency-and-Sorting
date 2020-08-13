/*
* Title: Algorithm Efficiency and Sorting
* Author: Ahmet Isik
* ID: 21702226
* Section: 2
* Assignment: 1
* Description: There are 3 main and 5 helper method header which composes
* the insertion, merge and quick sort algorithms
*/
#ifndef SORTING_H
#define SORTING_H
//swap method override
void swap(int &x, int &y);
// partition method override
void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
// helper method for quick sort algorithm takes first as 0
// and takes last as size - 1
void helperQuicksort(int theArray[], int first, int last, int size, int &compCount, int &moveCount);
// merge method override
void merge( int theArray[], int first, int mid, int last, int size, int &compCount, int &moveCount);
// helper method for merge sort algorithm takes first as 0
// and takes last as size - 1
void helperMergesort( int theArray[], int first, int last, int size, int &compCount, int &moveCount);
void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);

#endif // SORTING_H
