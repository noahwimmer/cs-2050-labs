#include "lab4.h"

void* createArray(int n, int dataSize) {
    void* array = malloc(n * dataSize);

    return array;
}

void freeArray(void** arr) {
    free(*arr);
    *arr = NULL;
}
