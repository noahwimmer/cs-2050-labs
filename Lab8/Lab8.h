//
// Created by Noah Wimmer on 3/22/21.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef LAB8_LAB8_H
#define LAB8_LAB8_H

typedef struct Node Node;

struct Node {
    Node *next;
    void *data;
};

typedef struct {
    Node *head;
    int size;
} List;

List* initList();
int getSize(List *list);
void freeList(List *list);
void* getAtIndex(List *list, int index);

void printList(List* list);
void insertAtHead(List* list, void* o);
void insertAtTail(List* list, void* o);


int listContains(List *list, void *object);
int insertInOrder(void* o, List* list);
int removeEq(void* o, List* list);
//int cmp(void* o1, void* o2);
int cmp(int a, int b);
void removeNodeAtIndex(List *list, int index);
int insertAfter(List *list, void *object, void *sentinel);

#endif //LAB8_LAB8_H
