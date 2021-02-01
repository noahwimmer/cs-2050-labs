#include "prelab2.h"

int main(void) {
    char* filename = "nums.txt";
    FILE *file = fopen(filename, "r");

    if(!file) {
        fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
        return -1;
    }

    int length;

    float* arr = readFloatFileIntoArray(file, &length);
    printFloatArray(arr, length);
    freeFloatArray(&arr);
    //if(!arr) printf("free"); <- tests if the array was freed and that the array pointer is now null after it was freed. (to avoid seg faults)
    return 0;
}
