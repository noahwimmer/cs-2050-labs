#include <stdio.h>
#include <stdlib.h>

#define SECT_B
int* loadGameScores(FILE *file, int *startIndex, int *length);
void freeIntArray(int **array, int startIndex);
