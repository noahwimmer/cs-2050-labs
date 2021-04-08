#include <stdio.h>
#include <stdlib.h>

// partial typedef, so you can define your own list type
typedef struct node {
    void* data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int size;
} List;

// COMPLEXITY: O(1)
List* initList();
// COMPLEXITY: O(1)
int getSize(List *list);
// COMPLEXITY: O(n)
void* getAtIndex(List *list, int index);
// COMPLEXITY: O(n)
void freeList(List *list);

#define SECT_B
// COMPLEXITY: O(n)
int insertAtTail(List *list, void *object);
// COMPLEXITY: O(1)
void* getHead(List *list);
// COMPLEXITY: O(1)
void* removeHead(List *list);
