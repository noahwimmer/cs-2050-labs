#include "lab11.h"

// function for testing
Flight* initFlight(float dist, unsigned int fn, unsigned short passengers) {
    Flight* flight = malloc(sizeof(Flight));
    if(!flight) {
        fprintf(stderr, "Error: Could not allocate memory. returning NULL...\n");
        return NULL;
    }

    flight->distance = dist;
    flight->flightNumber = fn;
    flight->passengers = passengers;

    return flight;
}

//testing search
// this function uses the lab function to init the array and then fill in the information with each flight.
Flight* createFlightArray(size_t size) {
    Flight* arr = (Flight*) createArray(size, sizeof(Flight));
    for(int i = 0; i < size; i++) {
        Flight* flight = initFlight(rand() % 10000, (i+1) * 37, rand() % 100);
        Flight newFlight = *flight;
        arr[i] = newFlight;
    }
    return arr;
}

int main() {
    srand(0); // for random flight generation
    Flight* arr = (Flight*) createFlightArray(10);
    //debugging ***
//    Flight first = *arr;
//    printf("%f %u\n", first.distance, first.flightNumber);
    //****

    size_t result = searchFlights(arr, arr + 1);
    printf("result = %zu\n", result);

    freeArray(arr);
    return 0;
}
