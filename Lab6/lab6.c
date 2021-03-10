#include "lab6.h"

//going to be using ints for the testing of this program.
//
// void printList(List* list) {
//     for(int i = 0; i < get)
// }

/* This function returns an empty List object. The
        parameter specifies the maximum length of the list. */
List * initList(int size) {
    List* list = malloc(sizeof(list));
    if(!list) {
        printf("malloc failed.\n");
        return NULL;
    }

    list->arraySize = size;
    list->listSize = 0;
    list->arr = malloc(sizeof(void*));

    if(!list->arr) {
        printf("malloc failed.\n");
        return NULL;
    }

    return list;
}

/* This function inserts the object of the first parameter
    at the head of the list and returns an error code. */
int insertAtHead(void* o, List* list) {
    //push each element back by one
    if(list) {
        if(getListLength(list) == getListSizeLimit(list)) { //list is full
            return -1;
        } else {
            //push elements
            for(int i = getListLength(list); i > 0; i--) {
                list->arr[i] = list->arr[i-1];
            }
            list->arr[0] = o;
            list->listSize++;
        }
    }
    return 0;
}

 /* This function returns the object at the index location
    given by the first parameter. */
void * getAtIndex(int i, List* list) {
    if(list) {
        if(i < getListLength(list)) {
            return list->arr[i];
        } else {
            printf("There is no element at index [%d]\n", i);
            return NULL;
        }
    } else {
        printf("List is NULL\n");
        return NULL;
    }
}

 /* This function returns the size limit of the array, i.e.,
    the value that was specified when the List was created. */
 int getListSizeLimit(List* list) {
     if(list) {
         return list->arraySize;
     } else {
         return -1;
     }
 }

 /* This function returns the number of objects in the list. */
 int getListLength(List* list) {
     if(list) {
         return list->listSize;
     } else {
         return -1;
     }
 }

 /* This function clears the list (makes it empty) just like
    it was after initList was called. */
void clearList(List* list) {
    if(list) {
        for(int i = 0; i < getListLength(list); i++) {
            list->arr[i] = NULL;
        }
        list->listSize = 0;
    }
}

 /* This function frees all memory allocated for a list and so
    is not the same as clearList. */
 void freeList(List* list) {
     free(list->arr);
     free(list);
 }
