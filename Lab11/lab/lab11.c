//
// Created by Noah Wimmer on 4/27/21.
//

#include "lab11.h"


// Complexity: O(1)
void* createArray(size_t size, size_t elemSize) {
    void* arr;
    size_t* temp = malloc(size * elemSize + sizeof(size_t));

    if(!temp) {
        fprintf(stderr, "Error: Could not allocate memory. returning NULL...\n");
        return NULL;
    }

    temp[0] = size;
    temp++;
    arr = temp;

    return arr;

}

// Complexity: O(1)
//gets the size of the specified array
size_t arraySize(void *array) {
    size_t* arr = (size_t*) array;
    return *(arr-1);
}

// Complexity: O(1)
//this function frees the specified memory
void freeArray(void *array) {
    size_t* arr = (size_t*) array;
    arr--;
    free(arr);
}

size_t searchFlights(Flight *array, Flight *query) {
    return binarySearch(array, 0, arraySize(array) - 1, query, sizeof(*query), (*compareFlights));
}

// Complexity: O(1)
// compares the two flights' flight numbers in a b-a fashion
int compareFlights(Flight *a, Flight *b) {
    unsigned int A = a->flightNumber;
    unsigned int B = b->flightNumber;
    unsigned int result = B-A;
    return result;
}

// generic binary search algorithm
// size_t ... (base pointer, left index, right index, query, size of element, compare function)
size_t binarySearch(void* arr, int l, int r, void* query, size_t size, int (*cmp)(Flight*, Flight*)) {
    if(arraySize(arr) == 1) {
        if(cmp(arr, query) == 0) {
            return 0;
        }
    }
    if(l<r) {
        int mid = (l+r) / 2;
        //int midpoint = mid * size; this was used for debugging.
        if(cmp(arr + (mid * size), query) == 0) {
            // query found in array
            return mid;
        }

        //if mid < query
        if(cmp(arr + (mid * size), query) > 0) {
            //look in right half
            return binarySearch(arr, mid+1, r, query, size, cmp);
        } else {
            // look in left half
            return binarySearch(arr, 0, mid - 1, query, size, cmp);
        }
    }
    // none found
    return SIZE_MAX;
}
