#include "lab2.h"

/*
    Function takes in a file pointer and a int pointer that assigns the int
    pointer to the length of the array and assigns long array the values in a
    file and returns that array

    can exit with error code 1 if allocating the array fails during runtime.
*/
long* readLongFromFile(FILE *file, int *length) {
    fscanf(file, "%d", length); // assigns length to the first line in file
    long* arr = malloc(*length * sizeof(long));
    if(arr == NULL) {
        //checking if malloc failed
        exit(1);
    }

    //assign each element to each integer in "integers.txt"
    for(int i = 0; i < *length; i++) {
        fscanf(file, "%ld", arr + i);
    }

    //returns resulting array
    return arr;
}


/*
    Function takes a double pointer to an array and frees the memory
    also sets the array pointer to null so that the user cannot use the array again.
*/
void freeLongArray(long **array) {
    free(*array);
    *array = NULL;
}
