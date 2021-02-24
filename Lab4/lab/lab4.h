#include <stdio.h>
#include <stdlib.h>

#define SECT_B
void findArrayMax(double *array);
int getArrayMax(double *array);
void *createArray(int size, size_t elemSize, size_t extraBytes);
int getArraySize(void *array);
void freeArray(void *array);
