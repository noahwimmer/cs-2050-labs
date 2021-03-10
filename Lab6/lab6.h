#include <stdio.h>
#include <stdlib.h>

typedef struct _List {
    void** arr;
    int arraySize, listSize;
} List;

/* This function returns an empty List object. The
        parameter specifies the maximum length of the list. */
List * initList(int);
/* This function inserts the object of the first parameter
    at the head of the list and returns an error code. */
int insertAtHead(void*, List*);
 /* This function returns the object at the index location
    given by the first parameter. */
void * getAtIndex(int, List*);
 /* This function returns the size limit of the array, i.e.,
    the value that was specified when the List was created. */
 int getListSizeLimit(List*);
 /* This function returns the number of objects in the list. */
 int getListLength(List*);
 /* This function clears the list (makes it empty) just like
    it was after initList was called. */
void clearList(List*);
 /* This function frees all memory allocated for a list and so
    is not the same as clearList. */
 void freeList(List*);
