#include "prelab2.h"

// solution file.

float* readFloatFileIntoArray(FILE *fptr, int* length) {
    fscanf(fptr, "%d", length);
    float* arr = malloc(*length * sizeof(float));
    if(arr == NULL) {
        //malloc failed
        exit(1);
    }
    // two ways -> for loop through the length of the list.
    // or for loop and loop until the end of the file.
    // both solutions scale to the length of the list, depends on personal preference.

    for(int i = 0; i < *length; i++) {
        fscanf(fptr, "%f", arr + i);
    }

    /*
    int i = 0;
    while(fptr && !feof(fptr)) {
        fscanf(fptr, "%f", arr + i);
        i++;
    }
    */
    return arr;
}


void freeFloatArray(float** arr) {
    free(*arr);
    *arr = NULL;
}

void printFloatArray(float* arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%.2f ", *(arr + i));
    }
}
