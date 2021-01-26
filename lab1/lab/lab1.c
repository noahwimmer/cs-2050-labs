#include "lab1.h"

// Required code goes here

//This function takes a float array and the size of the array as parameters, and searches the array for the maximum number
// in the data that is less than the provided ceiling. The function returns 1 on success and 0 if the data does not contain a number
//smaller than the provided ceiling. The result of this analysis must be placed into the result variable.

int maxBelow(float *array, int size, float *result, int ceiling) {
    int error;
    if(array[0] < ceiling) {
        *result = array[0];
        error = 1;
    } else error = 0;

    for(int i = 1; i < size; i++) {
        if(array[i] > *result && array[i] < ceiling) {
            *result = array[i];
            error = 1;
        }
    }
    return error;
}
