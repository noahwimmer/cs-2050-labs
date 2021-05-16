#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Complexity: O(1)
void* createArray(size_t size, size_t elemSize);

// Complexity: O(1)
size_t arraySize(void *array);

// Complexity: O(1)
void freeArray(void *array);

#define SECT_B

typedef struct {
    float distance;
    unsigned int flightNumber;
    unsigned short passengers;
} Flight;

// Complexity: O(log(n))
size_t searchFlights(Flight *array, Flight *query);

// Complexity: O(1)
int compareFlights(Flight *a, Flight *b);

//helper function
size_t binarySearch(void* arr, int l, int r, void* query, size_t size, int (*compareFlights)(Flight*, Flight*));


