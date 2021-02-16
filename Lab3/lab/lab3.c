#include "lab3.h"

/*

    FILE *file - file pointer
    int *startIndex - an int pointer to the starting index of the array.
    int *length - the size of the array.

    This function takes pointers to the file, starting index, and length and
    loads game scores from a file into a dynamically allocated array.

    returns a pointer to the start of the array.

*/
int* loadGameScores(FILE *file, int *startIndex, int *length) {
    //gathering min index from .txt information
    int max;
    fscanf(file, "%d", length);
    fscanf(file, "%d", &max);
    *startIndex = max - *length;

    // declaring and checking malloc
    int* arr = malloc(*length * sizeof(int));
    if(arr == NULL) {
        //checking if malloc failed
        exit(1);
    }

    // assigning scores in the array
    for(int i = 0; i < *length; i++) {
        fscanf(file, "%d", arr + i);
    }

    //modifying array pointer
    arr -= (*startIndex);

    return arr;
}

/*

    int **array - double pointer to an array
    int startIndex - the starting index value

    this function frees allocated space

    no return value
*/
void freeIntArray(int **array, int startIndex) {
    //set the array pointer to default and frees
    *array += startIndex;
    free(*array);
    *array = NULL;
}
