#include "Lab12.h"

// prints out a double array of length n
void printArray(double* arr, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        (i < (n-1)) ? printf("%lf, ", arr[i]) : printf("%lf]\n", arr[i]);
    }
}

int main() {
    srand48(time(NULL));

    int n = 10;

    double* arr = malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        arr[i] = drand48() * 10;
    }

    printArray(arr, n);
    printf("Sorting...\n");
    finalPrelabSort(arr, n);
    printArray(arr, n);


    return 0;
}
