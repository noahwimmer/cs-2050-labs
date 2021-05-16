#include "lab11.h"

// returns 0 if equal, else diffence between b-a
// interpreted with integers
int cmp(void* a, void* b) {
    int* A = (int*) a;
    int* B = (int*) b;
    int x = *A;
    int y = *B;
    int result = *B - *A;
    return result;
}


int main() {
    int (*compare)(int*, int*);
    compare = cmp;
    int* arr = malloc(100 * sizeof(int));
    for(int i = 0; i < 100; i++) {
        arr[i] = i;
    }

    int result = binarySearch(arr, 0, 100, 99, sizeof(int), compare);

    printf("result = %d\n", result);

    return 0;
}
