#include <stdio.h>
#include <stdlib.h>

#define COMMON_1
typedef struct {
	void **array;
	int size;
	int maxSize;
} List;

List* initList(int maxSize);
int getSize(List *list);
void freeList(List *list);
void* getAtIndex(List *list, int index);

#define SECT_B
int insertAtTail(List *list, void *object);
int isEmpty(List *list);
int listContains(List *list, void *object);
void* removeFromHead(List *list);


//helper function I made.
int getMaxSize(List* list);
