#include "lab12.h"

// helper function prototypes ----

void printFlightInfo(Flight* flight);

void count(BST* tree, size_t* c);

int compare(Flight* a, Flight* b);

// ----------

struct BST {
    Flight* flight;
    struct BST* left;
    struct BST* right;
};

// Complexity: O(1)
BST* initBST() {
    BST* tree = malloc(sizeof(BST));
    if(!tree) {
        fprintf(stderr, "Error: Could not allocate memory for BST.\nReturning NULL..\n");
        return NULL;
    }
    tree->flight = NULL;
    tree->right = NULL;
    tree->left = NULL;
    return tree;
}

// Gives the amount of nodes in the BST.
// returns amount of present nodes
// Complexity: O(n)
size_t BSTSize(BST *tree) {
    size_t c = 0;

    count(tree, &c);

    return c;
}
// counts each node in the tree
void count(BST* tree, size_t* c) {
    if(tree == NULL) return;

    count(tree->left, c);

    (*c)++;

    count(tree->right, c);
}

//frees the entire bst
// Complexity: O(n)
void freeBST(BST *tree) {
    if(tree == NULL) return;

    freeBST(tree->left);

    free(tree);

    freeBST(tree->right);
}

// couldnt figure out how to insert recursively without double pointer or returning BST*
// changed the error code to a pointer and returning BST*
// Complexity: O(log(n))
BST* insertFlight(BST *tree, Flight *flight, int* ec) {
    if(tree == NULL) {
        BST* newBST = initBST();
        if(newBST == NULL) *ec = 0;
        newBST->flight = flight;
        *ec = 1;
        return newBST;
    }

    if(compare(tree->flight, flight) > 0) {
        //insert into left half
        tree->left = insertFlight(tree->left, flight, ec);
    } else {
        //insert into right half
        tree->right = insertFlight(tree->right, flight, ec);
    }

    return tree;
}

//returns fn a - b
int compare(Flight* a, Flight* b) {
    unsigned int A = a->flightNumber;
    unsigned int B = b->flightNumber;
    int result = A - B;
    return result;
}

//helper function to search for flight
int search(BST* tree, Flight* query) {
    if(tree->flight == query) return 1;
    else if(tree->left == NULL && tree->right == NULL) {
        //end of branch
        return 0;
    }


    if(compare(tree->flight, query) > 0) {
        //search left half
        return search(tree->left, query);
    } else {
        //search right
        return search(tree->right, query);
    }

}

// searches for a specific flight based on flight number.
// Complexity: O(log(n))
int searchFlights(BST *tree, Flight *query) {
    int result = 0;
    result = search(tree, query);
    return result;
}

// prints all the information from a given flight pointer.
void printFlightInfo(Flight* flight) {
    printf("Flight Distance: %f\n", flight->distance);
    printf("Flight Number: %u\n", flight->flightNumber);
    printf("Passengers: %hu\n\n", flight->passengers);
}

// prints each node in bst in an pre-order fashion
void preOrderPrintFlights(BST *tree) {
    if(tree == NULL) return;

    printFlightInfo(tree->flight);

    preOrderPrintFlights(tree->left);

    preOrderPrintFlights(tree->right);
}

