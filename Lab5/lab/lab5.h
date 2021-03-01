#include <stdio.h>
#include <stdlib.h>

#define SECT_B
typedef struct {
	float distance;
	unsigned int flightNumber;
	unsigned short passengers;
} Flight;

float getDist(Flight *flight);
void setDist(Flight *flight, float dist);
unsigned int getFN(Flight *flight);
void setFN(Flight *flight, unsigned int FN);
unsigned short getPass(Flight *flight);
void setPass(Flight *flight, unsigned short pass);
void printFlightArray(Flight *flights);
Flight* loadFlightsFromFile(const char *filename);
Flight* getLongestFlight(Flight *flights);
Flight* getFlightByFlightNumber(Flight *flights, unsigned int flightNumber);
float calculateAverageDistance(Flight *flights);