/*
    Author: Noah Wimmer
    Date: 1/21/21
    Prelab 1
    -----
    For this prelab you will implement a function that takes an array of floats and a user-provided number (float) and provides the user with the sum
    of the largest number in the array that is less than the provided number and the smallest number that is larger than the provided number
*/

#include <stdio.h>
#include <stdlib.h>

int sum(float arr[], int size, float target, float *result);
void selectionSort(float arr[], int n);
int isBetween(float target, float min, float max);
void swap(float *xp, float *yp);

// returns 1 if a target float is inbetween two given floats, a, b.
int isBetween(float target, float min, float max) {
    if(target > min && target < max) return 1;
    else return 0;
}

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(float arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// read doc at top of file.
int sum(float arr[], int size, float target, float *result) {
    // two options
    // sort array and add numbers beside the number. <- i did this one below
    // loop through array and set numlow and numhigh based on target.

    selectionSort(arr, size);

    for(int i = 0; i < 9; i++) {
        printf("%f ", arr[i]);
        if(i==8) printf("\n");
    }

    int index = -1;
    float min, max;
    for(int i = 1; i < size - 1; i++) {
        if(isBetween(target, arr[i-1], arr[i])) {
            index = i;
            min = arr[i-1];
            max = arr[i];
        }
    }


    printf("index: %d, %f, %f\n", index, min, max);

    if(index == 1) {
        printf("The target float, %f, is not between two floats in the array.\n", target);
        return 1;
    }

    *result = min + max;

    return 0;
}

int main(void) {

    float arr[] = {1.23, 2.04, 0.04, 5.69, 4.20, 9.99, 3.2, 6.82, 9.43};
    float target = 7; // <- change this number (per user-provided number)

    float _sum;

    int error = sum(arr, 9, target, &_sum);

    printf("The sum is %f\n", _sum);

    return error;
}
