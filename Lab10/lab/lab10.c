#include "lab10.h"

typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
    double priority;
} Node;

typedef struct Queue {
    // basically a linked list struct
    Node* head;
    Node* tail;
    int size;
} Queue;

// Complexity: O(1)
// inits a pq with two dummy nodes that represent two extreme cases
Queue* initPQ() {
    Queue* pq = malloc(sizeof(Queue));
    if(!pq) {
        fprintf(stderr, "Error: Could not allocate memory for Queue\n");
        return NULL;
    }

    Node* min = malloc(sizeof(Node));
    Node* max = malloc(sizeof(Node));
    if(!min || !max) {
        fprintf(stderr, "Error: Could not allocate memory for Node\n");
        return NULL;
    }

    //setting heads vals
    max->data = (void*) 0;
    max->next = min;
    max->prev = NULL;
    max->priority = DBL_MAX;


    //setting tails vals
    min->data = (void*) 0;
    min->next = NULL;
    min->prev = max;
    min->priority = DBL_MIN;

    pq->head = max;
    pq->tail = min;
    pq->size = 2;

    return pq;
}

// Complexity: O(n)
// frees a queue and all nodes associated with it.
void freePQ(Queue* pq) {
    Node* cur = pq->head; //keeps track of nodes
    Node* temp = cur; // temp is to free

    //free each nodex
    while(cur != NULL) {
        cur = cur->next;
        free(temp);
        temp = cur;
    }
    //free container
    free(pq);
}

// This function inserts flights in a list based on the flight flightNumber
// is decreasing sorted.
// returns 1 on success and 0 on failure
int insertFlightDescendingPQ(Queue *pq, Flight *flight) {
    //create node
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        fprintf(stderr, "Error: Could not allocate memory for Node\n");
        return 0;
    }

    newNode->data = flight;
    newNode->priority = flight->flightNumber;
    //compare
    Node* x = pq->head;
    Node* y = x->next;

    while(1) {
        // if its between x and y
        if(newNode->priority <= x->priority && newNode->priority >= y->priority) {
            //insert after x
            x->next = newNode;
            newNode->next = y;

            y->prev = newNode;
            newNode->prev = x;
            break;
        } else {
            //else advance x and y
            x = y;
            y = y->next;
        }
    }
    return 1;
}

// Complexity: O(n)
// This function returns the flight at the end of the list
// This function assumes there is at least one node in the list that is not a dummy node
Flight* peekMinFlight(Queue *pq) {
    // peek second to last
    Node* cur = pq->head;
    while(cur->next->priority != DBL_MIN) {
        cur = cur->next;
    }
    return cur->data;
}

// Complexity: O(n)
// this function returns and removes the flight at the end of the list.
// This function assumes there is at least one node in the list that is not a dummy node
Flight* deQueueMinFlight(Queue *pq) {
    // release second to last Node
    // get second to last Node
    Node* cur = pq->head;
    while(cur->next->priority != DBL_MIN) {
        cur = cur->next;
    }
    // release Node
    Flight* result = cur->data;
    cur->prev->next = pq->tail;
    pq->tail->prev = cur->prev;
    free(cur);
    return result;
}
