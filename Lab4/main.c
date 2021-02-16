#include "lab4.h"

int main(void) {
    int* array;
    array = createArray(10, sizeof(int));

    for(int i = 0; i < 10; i++) {
        array[i] = i;
    }

    printf("%d\n", array[5]);

    freeArray((void**) &array);

    return 0;
}
