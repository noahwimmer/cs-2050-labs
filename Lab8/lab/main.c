#include "lab8.h"

int main(void) {
    List* list = initList();
    Flight* flight1 = malloc(sizeof(Flight));
    Flight* flight2 = malloc(sizeof(Flight));
    Flight* flight3 = malloc(sizeof(Flight));
    Flight* flight4 = malloc(sizeof(Flight));
    flight1->distance = 100;
    flight2->distance = 200124;
    flight3->distance = 1231;
    flight4->distance = 0;
    flight1->flightNumber = 1;
    flight2->flightNumber = 2;
    flight3->flightNumber = 3;
    flight4->flightNumber = 4;
    flight1->passengers = 50;
    flight2->passengers = 120;
    flight3->passengers = 25;
    flight4->passengers = 75;



    insertAtHead(list, flight1);
    insertAtTail(list, flight2);
    insertAtTail(list, flight3);
    insertAtTail(list, flight4);
    printFlights(list);
    int eq = countAllEqualFlights(list, flight1);
    eq += countAllEqualFlights(list, flight4);
    printf("Equal flights: %d\n", eq);

    List* ascending = initList();
    insertFlightAscending(ascending, flight1);
    insertFlightAscending(ascending, flight2);
    insertFlightAscending(ascending, flight3);
    insertFlightAscending(ascending, flight4);
    insertFlightAscending(ascending, flight2);

    printf("ascending flights:\n");
    printFlights(ascending);

    freeList(list);
    freeList(ascending);
    return 0;
}
