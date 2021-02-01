#include <stdio.h>
#include <stdlib.h>

//put all includes and prototypes in this file.

float* readFloatFileIntoArray(FILE *fptr, int* length);
void freeFloatArray(float** arr);
void printFloatArray(float* arr, int length);
