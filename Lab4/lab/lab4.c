#include "lab4.h"

/*
    function takes in a pointer to double array and finds the max value and stores it beyond the array
    linear scan through array to find largest number
*/
void findArrayMax(double *array) {
    int size = getArraySize(array); //to make it more readable
    array[size + 1] = array[0]; //default value
    for(int i = 1; i < size; i++) {
        if(array[i] > array[size+1]) {
            array[size + 1] = array[i];

        }
    }
}


// returns the max value of the given array.
int getArrayMax(double *array) {
    return (int) array[getArraySize(array) + 1];
}


/*
    creates an array with the size and datatype determined in the params as well as the size of extraBytes to store the max value in the array.
    returns null if memory cannot be allocated

*/
void *createArray(int size, size_t elemSize, size_t extraBytes) {
    void* arr = malloc(size * elemSize + extraBytes + sizeof(int));
    if(arr == NULL) {
        //checking if malloc failed
        fprintf(stderr, "Memory was unable to be allocated.");
        return arr;
    }

    // modifying the pointer
    int* temp = arr;
    temp -= 1;
    temp[-1] = size;
    arr = temp;



    return arr;
}

// gives the size of the array given in the params
int getArraySize(void *array) {
    int* arr = array;
    return arr[-1];
}

//frees the array given in the params
void freeArray(void *array) {
    //reset array pointer back to default
    int* temp = array;
    temp += 1;
    array = temp;

    free(array);
}
