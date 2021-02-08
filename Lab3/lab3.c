#include "lab3.h"

/* This function returnsa double array that can be indexedstarting at minIndex and ending at maxIndex,
 i.e., minIndexis the index of the first element of the array and maxIndexis the index of the last element of the array.

 The function:void freeDoubleArray(double* array,int minIndex) must be called to free the allocated array.*/

double* createDoubleArray(int minIndex, int maxIndex) {
    int size = maxIndex - minIndex;

    double* arr = malloc(size * sizeof(double));

    if(arr == NULL) {
        //if malloc failed
        exit(1);
    }

    arr += minIndex;

    return arr;
}

void freeDoubleArray(double** arr, int minIndex) {
    *arr -= minIndex;
    free(*arr);
    *arr = NULL;
}
