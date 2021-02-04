#include <stdio.h>
#include <stdlib.h>

#define SECT_B
long* readLongFromFile(FILE *file, int *length);
void freeLongArray(long **array);
