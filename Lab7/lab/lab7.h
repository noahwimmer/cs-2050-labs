#include <stdio.h>
#include <stdlib.h>

//for testing
typedef struct {
    int val;
} Int;

// partial typedef, so the Node type can contain itself
typedef struct Node Node;

struct Node {
	Node *next;
	void *data;
};

typedef struct {
	Node *head;
	int size;
} List;

void printList(List* list);

List* initList();
int getSize(List *list);
void freeList(List *list);
void* getAtIndex(List *list, int index);

#define SECT_B
int insertAfter(List *list, void *object, void *sentinel);
int listContains(List *list, void *object);
void* removeAtIndex(List *list, int index);
