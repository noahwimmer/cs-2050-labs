#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void* o;
    struct _node* next;
} Node;

typedef internalStruct {
    Node *head;
    int listLength;
} ListStuff;

typedef struct arrayListStruct {
    ListStuff *p;
} List;

/* This function returns an empty List object. */
List initList(int);
/* This function inserts the object of the first parameter at the head of the list and returns an error code. */
int insertAtHead(void*, List);
/* This function returns the object at the index location given by the first parameter. */
void* getAtIndex(int, List);
/* This function returns the size limit of the array, i.e., the value that was specified when the List was created. */
int getSizeLimit(List);
/* This function returns the number of objects in the list. */
int countItems(List);
/* This function clears the list (makes it empty) just like after it was created by initList. */
void clearList(List);
/* This function frees all memory allocated for a list. */
void freeList(List);
