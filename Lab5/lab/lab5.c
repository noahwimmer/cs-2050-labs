#include "lab5.h"

int getSize(Flight* flights);
void freeArray(Flight* flights);


void freeArray(Flight* flights) {
    int* temp = (int*) flights;
    temp--;
    free(temp);
}

int getSize(Flight* flights) {
    int* temp = (int*) flights;
    return temp[-1];
}

/*
    Takes in a flight struct and returns the flight's distance
*/
float getDist(Flight* flight) {
    return flight->distance;
}

/*
    Takes in a flight struct and a float distance and sets that flight's distance to the given distance
*/
void setDist(Flight *flight, float dist) {
    flight->distance = dist;
}

/*
    Takes in a flight struct and returns the flight number
*/
unsigned int getFN(Flight *flight) {
    return flight->flightNumber;
}

/*
    Takes in a flight struct and uint and asssigns that flight's number to the given number in parameters
*/
void setFN(Flight *flight, unsigned int FN) {
    flight->flightNumber = FN;
}

/*
    Takes in a flight struct and returns the amount of passengers
*/
unsigned short getPass(Flight *flight) {
    return flight->passengers;
}

/*
    takes in a flight struct and ushort and assigns the flight's passengers to the given ushort
*/
void setPass(Flight *flight, unsigned short pass) {
    flight->passengers = pass;
}

/*
    takes in a flight struct array and prints the info of each flight
*/
void printFlightArray(Flight *flights) {
    printf("\n");
    for(int i = 0; i < getSize(flights); i++) {
        printf("Distance: %.2f, FN: %u, Pass: %hu\n", getDist(&flights[i]), getFN(&flights[i]), getPass(&flights[i]));
    }
    printf("\n");
}

/*
    takes in a filename and loads the flight info into an array of flights

    retuns NULL if the file cannot be read
    returns NULL if malloc fails to allocate memory
*/
Flight* loadFlightsFromFile(const char *filename) {
    //opening file
    FILE* fp = fopen(filename, "r");
    if(!fp) {
        fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
        return NULL;
    }

    //getting size of array
    int size = 0;
    fscanf(fp, "%d", &size);

    //allocating space for flights
    Flight* flights = NULL;
    int* temp = malloc(size * sizeof(Flight) + sizeof(int));
    if(temp == NULL) {
        //malloc failed
        printf("Malloc failed to allocate space.\n");
        return NULL;
    }

    //modifying array pointer
    temp[0] = size;
    temp++;
    flights = (Flight*) temp;


    //assigning values to each flight in array
    float dist = 0.0;
    unsigned int fn = 0;
    unsigned short pass = 0;
    for(int i = 0; i < size; i++) {
        fscanf(fp, "%f, %u, %hu", &dist, &fn, &pass);
        setDist(&flights[i], dist);
        setFN(&flights[i], fn);
        setPass(&flights[i], pass);
    }

    //closing file and returning array of flights
    fclose(fp);
    return flights;
}
/*
    takes in a flight array and returns the longest flight. (distance)
*/
Flight* getLongestFlight(Flight *flights) {
    //keeps track of longest flight via index
    int longest_i = 0;
    for(int i = 1; i < getSize(flights); i++) {
        //compares each element to the current saved longest
        if(getDist(&flights[i]) > getDist(&flights[longest_i])) {
            // if new flight dist > current longest dist, set new longest dist to current index
            longest_i = i;
        }
    }
    return &flights[longest_i];
}

/*
    takes in a flight nmber and array of flights and returns the specific flight given the flight number
    returns NULL if there is no matching flight with flight number
*/
Flight* getFlightByFlightNumber(Flight *flights, unsigned int flightNumber) {
    //linear scan through array and returns the flight associated with FN
    //returns null if there are no matches
    for(int i = 0; i < getSize(flights); i++) {
        if(getFN(&flights[i]) == flightNumber) {
            return &flights[i];
        }
    }
    return NULL;
}

/*
    takes in an array of flights and returns the average distance of all the flights
*/
float calculateAverageDistance(Flight *flights) {
    //getting the sum of all flight distances.
    float sum = 0;
    for(int i = 0; i < getSize(flights); i++) {
        sum += getDist(&flights[i]);
        //printf("sum: %.2f\n", sum);
    }

    return sum / (float) getSize(flights);
}
