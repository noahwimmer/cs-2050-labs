#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#define SECT_B
typedef struct {
	float distance;
	unsigned int flightNumber;
	unsigned short passengers;
} Flight;

int compareFlights(Flight *a, Flight *b);
int insertFlightAscending(List *list, Flight *flight);
int countAllEqualFlights(List *list, Flight *flight);
void printFlights(List *list);


// Helper functions I imeplemented outside of grading scope
int insertAtTail(List* list, void* o);
int insertAtHead(List* list, void* o);
Node* getNodeAtIndex(List* list, int index);
int insertAfter(List* list, void* object, void* sentinel);
int listContains(List* list, void* object);
