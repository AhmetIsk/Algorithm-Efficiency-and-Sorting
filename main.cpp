/*
* Title: Algorithm Efficiency and Sorting
* Author: Ahmet Isik
* ID: 21702226
* Section: 2
* Assignment: 1
* Description: there are 2 global methods which are performanceAnalysis
* and performanceAnalysisQuestionThree. There is a main method which
* performs the sorting algorithms on specific arrays and takes output.
*/
#include <iostream>
#include <ctime>
#include "auxArrayFunctions.h"
#include "sorting.h"
using namespace std;

// choose no 1 for randomly created arrays or no 2 for
// already sorted arrays
void performanceAnalysis (int no) {
    int *arr1, *arr2, *arr3;
    int count1 = 0;
    int count2 = 0;


    for ( int i = 1; i < 7; i++) {
        int N = i * 5000;
        cout << "-----------------------------------------------------" << endl;
        cout << "Part c - Time Analysis of Sorting Algorithms with an " << N << " Size Array "<< endl;
        cout << "Sorting Type     Time Elapsed     compCount      moveCount" << endl;
        if (no == 1) {
            createRandomArrays(arr1, arr2, arr3, N );
        }
        if (no == 2) {
            createAlreadySortedArrays(arr1, arr2, arr3, N );
        }

        double duration, duration1, duration2;
        clock_t startTime = clock();
        insertionSort(arr1, N, count1, count2);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Insertion Sort   " << duration << " ms           " <<
         count1 << "       " << count2 << endl;

        startTime = clock();
        mergeSort(arr2, N, count1, count2);
        duration1 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Merge Sort       " << duration1 << " ms             " <<
         count1 << "         " << count2 << endl;

        startTime = clock();
        quickSort(arr3, N, count1, count2);
        duration2 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Quick Sort       " << duration2 << " ms             " <<
         count1 << "         " << count2 << endl;
         delete[] arr1;
         delete[] arr2;
         delete[] arr3;
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

// chooses a k value that determines the maximum distance
// of items from the target
void performanceAnalysisQuestionThree () {
    int *arr1, *arr2, *arr3;
    int count1 = 0;
    int count2 = 0;
    for ( int i = 1; i < 7; i++) {
        int N = 30000;
        int k = i*i*800;
        cout << "-----------------------------------------------------" << endl;
        cout << "Question 3 - Time Analysis of Sorting Algorithms  with 30000 size of Array that items are at most "
        << k << " away from target "<< endl;
        cout << "Sorting Type     Time Elapsed     compCount      moveCount" << endl;

        createNearlySortedArrays(arr1, arr2, arr3, N, k);
        double duration, duration1, duration2;
        clock_t startTime = clock();
        insertionSort(arr1, N, count1, count2);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Insertion Sort   " << duration << " ms           " <<
         count1 << "       " << count2 << endl;

        startTime = clock();
        mergeSort(arr2, N, count1, count2);
        duration1 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Merge Sort       " << duration1 << " ms             " <<
         count1 << "         " << count2 << endl;

        startTime = clock();
        quickSort(arr3, N, count1, count2);
        duration2 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Quick Sort       " << duration2 << " ms             " <<
         count1 << "         " << count2 << endl;
         delete[] arr1;
         delete[] arr2;
         delete[] arr3;
    }
}

int main() {

    int arr[] = {9,5,8,15,16,6,3,11,18,0,14,17,2,9,11,7};
    int count1 = 0;
    int count2 = 0;
    int sizeArr = 16;
    cout << "Insertion Sort" << endl;
    insertionSort(arr, sizeArr, count1, count2);
    displayArray(arr, sizeArr);
    cout << "Number of key comparisons: " << count1 << endl;
    cout << "Number of data moves: " << count2 << endl;

    cout << "Merge Sort" << endl;
    int arr4[] = {9,5,8,15,16,6,3,11,18,0,14,17,2,9,11,7};
    mergeSort(arr4, sizeArr, count1,count2);
    displayArray(arr4, sizeArr);
    cout << "Number of key comparisons: " << count1 << endl;
    cout << "Number of data moves: " << count2 << endl;

    cout << "Quick Sort" << endl;
    int arr5[] = {9,5,8,15,16,6,3,11,18,0,14,17,2,9,11,7};
    quickSort(arr5, sizeArr, count1,count2);
    displayArray(arr5, sizeArr);
    cout << "Number of key comparisons: " << count1 << endl;
    cout << "Number of data moves: " << count2 << endl;

    // choose 1 or 2
    performanceAnalysis(1);

    performanceAnalysisQuestionThree();


return 0;
}
