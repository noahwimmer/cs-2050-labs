#ifndef lab10
#define lab10

#include <stdlib.h>
#include <stdio.h>
#include <float.h>


typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
    int priority;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} PQueuestuff;

typedef struct {
    PQueuestuff* p;
} PQueue;


PQueue initPQueue(int* ec);

int insertPQ(void* object, double priority, PQueue pq);

void* minDeletePQ(PQueue pq);

void* maxDeletePQ(Pqueue pq);

double getMinPriority(PQueue pq);

double getMaxPriority(PQueue pq);

int getSizePQ(PQueue pq);

void freePQ(PQueue pq);

#endif
