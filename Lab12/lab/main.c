#include "lab12.h"

#include <time.h>

Flight* initFlight(float dist, unsigned int flightNumber, unsigned short passengers);

Flight* initFlight(float dist, unsigned int flightNumber, unsigned short passengers) {
    Flight* flight = malloc(sizeof(Flight));
    if(!flight) {
        fprintf(stderr, "Error: Could not allocate memory for flight.\nReturning NULL...\n");
        return NULL;
    }
    flight->distance = dist;
    flight->flightNumber = flightNumber;
    flight->passengers = passengers;
    return flight;
}

int main() {
    srand(time(NULL));

    BST* bst = NULL;
    int ec;

    Flight* query = initFlight(rand() % 50000, rand() % 10000, rand() % 150);


    for(int i = 0; i < 10; i++) {
        bst = insertFlight(bst, initFlight(rand() % 50000, rand() % 10000, rand() % 150), &ec);
    }

    bst = insertFlight(bst, query, &ec);

    int found = searchFlights(bst, query);

    preOrderPrintFlights(bst);

    printf("Query in list? %d\n", found);

    freeBST(bst);

    return 0;
}
