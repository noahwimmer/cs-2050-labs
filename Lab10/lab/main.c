#include "lab10.h"

Flight* initFlight(float dist, unsigned int flightNumber, unsigned short passengers) {
    Flight* flight = malloc(sizeof(Flight));
    if(!flight) {
        return NULL;
    }

    flight->distance = dist;
    flight->flightNumber = flightNumber;
    flight->passengers = passengers;
    return flight;
}

int main(void) {
    Queue* pq = initPQ();
    Flight* f1 = initFlight(120, 255, 50);
    Flight* f2 = initFlight(150, 500, 65);

    insertFlightDescendingPQ(pq, f1);
    insertFlightDescendingPQ(pq, f2);

    Flight* test = peekMinFlight(pq);
    printf("test: %f\n", test->distance);

    deQueueMinFlight(pq);
    test = peekMinFlight(pq);
    printf("test2: %f\n", test->distance);

    freePQ(pq);

    return 0;
}
