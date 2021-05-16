#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct BST BST;

// Complexity: O(1)
BST* initBST();

// Complexity: O(n)
size_t BSTSize(BST *tree);

// Complexity: O(n)
void freeBST(BST *tree);

#define SECT_B

typedef struct {
    float distance;
    unsigned int flightNumber;
    unsigned short passengers;
} Flight;

// Complexity: O(log(n))
BST* insertFlight(BST *tree, Flight *flight, int* ec);

// Complexity: O(log(n))
int searchFlights(BST *tree, Flight *query);

// Complexity: O(n)
void preOrderPrintFlights(BST *tree);
