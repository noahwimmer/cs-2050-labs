#ifndef LAB_9
#define LAB_9

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} liststuff;

typedef struct {
    liststuff* p;
} List;

List initList(int* ec);

int insertHead(List list, void* data);

void* removeHead(List list);

int insertTail(List list, void* data);

void* removeTail(List list);

void freeList(List list);

#endif
