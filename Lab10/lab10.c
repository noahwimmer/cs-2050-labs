#include "lab10.h"

PQueue initPQueue(int* ec) {
    PQueue* pq = malloc(sizeof(PQueue));
    if(!pq) {
        //malloc failed
        fprintf(stderr, "Error: Could not allocate memory for PQueue\n");
        *ec = 0;
        return NULL;
    }


    Node* min = malloc(sizeof(Node));
    Node* max = malloc(sizeof(Node));
    if(!min) {
        fprintf(stderr, "Error: Could not allocate memory for min\n");
        *ec = 0;
        return NULL;
    }
    if(!max) {
        fprintf(stderr, "Error: Could not allocate memory for max\n");
        *ec = 0;
        return NULL;
    }

    min->data = DBL_MIN;
    max->data = DBL_MAX;
    min->next = max;
    min->prev = NULL;

    max->next = NULL;
    max->prev = min;

    pq->p->head = min;
    pq->p->tail = max;
    pq->p->size = 2;
    *ec = 1;


    return *pq;
}

int insertPQ(void* object, double priority, PQueue pq) {
    //create Node
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        fprintf(stderr, "Error: Could not allocate memory for max\n");
        return 0;
    }
    newNode->data = object;
    newNode->priority = priority;
    //compare

    Node* x = pq.p->head;
    Node* y = x->next;
    while(1) {
        if(newNode->priority >= x->priority && newNode <= y->priority) {
            //insert after x
            x->next = newNode;
            newNode->prev = x;
            newNode->next = y;
            y-prev->newNode;
            break;
        } else {
            x = y;
            y = x->next;
        }
    }
}

// same thing as remove from head
void* minDeletePQ(PQueue pq) {
    Node* head = pq.p->head;
    head->next->prev = NULL;
    void* data = head->data;
    pq.p->head = head->next;
    free(head);
    return data;
}

// same thing as remove from tail
void* maxDeletePQ(Pqueue pq) {
    Node* prev = pq.p->prev;
    prev->next = NULL;
    void* data = prev->data;
    pq.p->tail = prev;
    free(prev);
    return data;
}

double getMinPriority(PQueue pq) {
    return pq.p->head->priority;
}

double getMaxPriority(PQueue pq) {
    return pq.p->tail->priority;
}

int getSizePQ(PQueue pq) {
    return pq.p->size;
}

void freePQ(PQueue pq) {
    Node* cur = list->head;
    while(cur) {
        minDeletePQ(pq);
        cur = cur->next;
    }
}
