#include "lab3.h"

int main(void) {
    double* arr = createDoubleArray(100, 200);
    arr[150] = 150.25;

    printf("%lf\n", arr[150]);

    freeDoubleArray(&arr, 100);


    return 0;
}
