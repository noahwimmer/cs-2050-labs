#include "lab8.h"

// This function takes two pointers to Flight structs and compares them based upon their flight-Number members.
// The function should return a strictly negative number if a is less than b, 0 if they are equal, and a strictly positive number if a is greater than b.
int compareFlights(Flight *a, Flight *b) {
    unsigned int fn1 = a->flightNumber;
    unsigned int fn2 = b->flightNumber;
    return fn1 - fn2;
}

// This function takes a list and pointer to a struct.
// This function will insert the struct onto the list in sorted order using the above compare function.
// The function will maintain the list in ascending order.
int insertFlightAscending(List *list, Flight *flight) {
    int ec; //error code
    if(listContains(list, flight)) { //if the list already contains the same data. insert after the last duplicate
        ec = insertAfter(list, flight, flight);
        return ec;
    } else {
        // list does not contain duplicate
        int size = getSize(list);
        Node* current = list->head;
        if(size == 0) { // if there are no nodes yet in the list
            ec = insertAtHead(list, flight);
            return ec;
        } else if(size == 1) { // if there is only one node in the list
            if(compareFlights(current->data, flight) > 0) {
                ec = insertAtHead(list, flight);
                return ec;
            } else {
                ec = insertAtTail(list, flight);
                printFlights(list);
                return ec;
            }
        } else {
            //now there are at least 2 nodes in the data and we need to start comparison in middle of two nodes
            for(int i = 1; i < size; i++) {
                Node* p = getNodeAtIndex(list, i - 1);
                Node* q = getNodeAtIndex(list, i);
                if(compareFlights(flight, p->data) < 0 && i==1) {
                    //if the flight is before the first node
                    ec = insertAtHead(list, flight);
                    return ec;
                } else if(compareFlights(flight, p->data) > 0 && compareFlights(flight, q->data) < 0) {
                    // if its in the middle of two nodes
                    ec = insertAfter(list, flight, p->data);
                    return ec;
                } else if(compareFlights(flight, q->data) > 0 && (i == size - 1)) {
                    // if its after the last node
                    ec = insertAtTail(list, flight);
                    return ec;
                }
            }
            return -1;
        }
    }
}

//This function takes a list containing struct pointers, and returns the number of structs on the list which are equal to the given struct.
int countAllEqualFlights(List *list, Flight *flight) {
    int count = 0;
    Node* current = list->head;
    Flight* currentFlight = current->data;
    for(int i = 0; i < getSize(list); i++) {
        if(compareFlights(currentFlight, flight) == 0) count++;
        current = current->next;
        if(i != getSize(list) - 1)
        currentFlight = current->data;
    }
    return count;
}

// This function takes a list containing Flight strucsts and prints out all of the structs in a readable format.
void printFlights(List *list) {
    Node* current = list->head;
    Flight* flight = current->data;
    for(int i = 0; i < getSize(list); i++) {
        int distance = flight->distance;
        unsigned int FN = flight->flightNumber;
        unsigned short passengers = flight->passengers;
        printf("Distance: %d\nFN: %u\nPassengers: %hu\n\n", distance, FN, passengers);
        current = current->next;
        if(i != getSize(list) - 1)
        flight = current->data;
    }
    printf("\n");
}
// -----------------------------------------------------------------------------------------
// These are helper functions


// function that determines if an object exists in the list
// returns 1 if it does exist, 0 if it doesnt
int listContains(List* list, void* object) {
    Node* temp = list->head;
    for(int i = 0; i < getSize(list); i++) {
        if(temp->data == object) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// this is last weeks code from lab7
int insertAfter(List* list, void* object, void* sentinel) {
    if(!listContains(list, sentinel)) {
        //if sentinel does not exist
        if(getSize(list) > 0) {
            //insert at the end
            Node* newNode = malloc(sizeof(Node));
            if(!newNode) {
                fprintf(stderr, "Malloc failed.\n");
                return 0;
            }
            Node* tail = getAtIndex(list, getSize(list) - 1);
            newNode->data = object;
            newNode->next = NULL;
            tail->next = newNode;
            list->size++;
            return 1;
        } else {
            //malloc first node
            Node* newNode = malloc(sizeof(Node));
            if(!newNode) {
                fprintf(stderr, "Malloc failed.\n");
                return 0;
            }
            newNode->data = object;
            newNode->next = NULL;
            list->head = newNode;
            list->size++;
            return 1;
        }
    } else {
        //sentinel exists
        Node* newNode = malloc(sizeof(Node));
        if(!newNode) {
            fprintf(stderr, "Malloc failed.\n");
            return 0;
        }
        newNode->data = object;
        Node* temp = list->head;
        for(int i = 0; i < getSize(list); i++) {
            //find last sentinel node.
            if(i == getSize(list) - 1) {
                if(temp->data == sentinel) {
                    //insert newNode here
                    newNode->next = temp->next;
                    temp->next = newNode;
                    list->size++;
                    return 1;
                } else {
                    temp = temp->next;
                }
            } else {
                if(temp->data == sentinel && temp->next->data != sentinel) {
                    //insert newNode here
                    newNode->next = temp->next;
                    temp->next = newNode;
                    list->size++;
                    return 1;
                } else {
                    temp = temp->next;
                }
            }
        }
        return 0;
    }
}

/*
 * This function takes in a list ptr and an index to get the node at the specified index
 * List* list - The list to gather a node from
 * int index - the specified index
 * returns the node at the specified index.
 */
Node* getNodeAtIndex(List* list, int index) {
    if(getSize(list) > 0) {
        // List has at least one node.
        Node* current = list->head;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    } else {
        // The list has no nodes
        return NULL;
    }
}

/*
 * This function inserts a node at the head of the list.
 * List* list - The list to be changed
 * void* o - the object to be stored at the head of the list
 * returns 0 if the function failed
 * returns 1 if successful
 */
int insertAtHead(List* list, void* o) {
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        fprintf(stderr, "Error: Could not allocate memory..\nReturning -1.\n");
        return 0;
    }
    newNode->next = list->head;
    newNode->data = o;
    list->head = newNode;
    list->size++;
    return 1;
}

/*
 * This function appends a node to the end of the list
 * List* list - The list that is being changed
 * void* o - the object to be stored at the end of the list.
 * returns 0 if the function failed
 * returns 1 if successful
 */
int insertAtTail(List* list, void* o) {
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        fprintf(stderr, "Error: Could not allocate memory..\nReturning -1.\n");
        return 0;
    }
    newNode->data = o;
    newNode->next = NULL;
    Node* p = getNodeAtIndex(list, getSize(list) - 1);
    p->next = newNode;
    list->size++;
    return 1;
}
