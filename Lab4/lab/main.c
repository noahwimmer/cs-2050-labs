#include "lab4.h"

// takes in a pointer to double and prints the values in the array.
void printArr(double* arr) {
    for(int i = 0; i < getArraySize(arr); i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

int main() {
    //create example array
    double* arr = (double*) createArray(10, sizeof(double), sizeof(double));
    for(int i = 0; i < getArraySize(arr); i++) {
        arr[i] = i;
    }
    arr[5] = 50;

    //print array
    printArr(arr);

    //find and print the max value of the array
    findArrayMax(arr);
    printf("max: %d\n", getArrayMax(arr));

    //frees the array
    freeArray((void*) arr);


    return 0;
}
