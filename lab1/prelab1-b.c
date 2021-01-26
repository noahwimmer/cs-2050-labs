/*
    Author: Noah Wimmer
    Date: 1/25/21
    Prelab 1
    -----
    For this prelab you will implement a function that takes an array of floats and a user-provided number (float) and provides the user with the sum
    of the largest number in the array that is less than the provided number and the smallest number that is larger than the provided number
*/

#include <stdio.h>
#include <stdlib.h>

int sum(float arr[], int size, float target, float *result);

int sum(float arr[], int size, float target, float *result)  {
    // two options
    // sort array and add numbers beside the number.
    // loop through array and set numlow and numhigh based on target. <- I did this one below

    // are there any constrants of the given array? max value / min value?
    float minOver;
    float maxUnder = minOver = arr[0];

    for(int i = 0; i < size; i++) {
        if(arr[i] < target && arr[i] > maxUnder) {
            maxUnder = arr[i];
        }
        if(arr[i] > target && arr[i] < minOver) {
            minOver = arr[i];
        }
        //printf the information to make sure its correct.
        //insert an error here for any mishaps.
    }

    *result = maxUnder + minOver;

    return 0;
}

int main(void) {
    int error;
    float arr[] = {1.23, 2.04, 0.04, 5.69, 4.20, 9.99, 3.2, 6.82, 9.43};
    float target = 5;

    float result;

    error = sum(arr, sizeof(arr)/sizeof(arr[0]), target, &result);

    printf("%f\n", result);

    return error;
}
