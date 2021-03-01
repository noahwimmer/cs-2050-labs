#include "lab5.h"

int main(void) {
    Flight* flights = loadFlightsFromFile("flights.txt");
    printFlightArray(flights);

    printf("The longest flight was number: %u\n", getFN(getLongestFlight(flights)));
    printf("The average distance was: %.2f\n", calculateAverageDistance(flights));



    return 0;
}
