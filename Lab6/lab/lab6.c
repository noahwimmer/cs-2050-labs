#include "lab6.h"

//is this a queue data structure. first in first out.

//helper function to get the maximum size of the list
//returns the maxsize of the list
//returns -1 if the list is NULL
int getMaxSize(List* list) {
    if(list) {
        return list->maxSize;
    } else {
        return -1;
    }
}

//Initializes a list with a maximum size of maxSize
//returns null if malloc fails
List* initList(int maxSize) {
    //allocating space
    List* list = malloc(sizeof(list));
    if(!list) {
        fprintf(stderr, "Malloc Failed.\n");
        return NULL;
    }

    //assigning default values
    list->maxSize = maxSize;
    list->size = 0;
    list->array = malloc(sizeof(void*));

    if(!(list->array)) {
        fprintf(stderr, "Malloc Failed.\n");
        return NULL;
    }

    return list;
}

//returns the number of elements in the list
//return -1 if the list is NULL
int getSize(List *list) {
    if(list) {
        return list->size;
    } else {
        return -1;
    }
}

//frees the list and elements from memory
void freeList(List *list) {
    free(list->array);
    list->array = NULL;
    free(list);
}

//returns the element in the list at index, "index"
//returns null if there does not exist an element at the specified index, or that the list is null.
//assume index is greater than -1
void* getAtIndex(List *list, int index) {
    if(list) {
        //if the index is within the bounds of the size
        if(index < getSize(list)) {
            return list->array[index];
        } else {
            //else the index is out of bounds.
            printf("There is no element at index [%d]\n", index);
            return NULL;
        }
    } else {
        printf("List is NULL\n");
        return NULL;
    }
}

//inserts an element at the end of the list
// returns 0 if insertion failed. returns 1 if successful.
int insertAtTail(List *list, void *object) {
    if(list) {
        if(getSize(list) == getMaxSize(list)) {
            //if list is full
            return 0;
        } else {
            //assign new element and increment size
            list->array[getSize(list)] = object;
            list->size++;
            return 1;
        }
    } else {
        printf("List is NULL.\n");
        return 0;
    }
}

//returns an int whether or not the listsize > 0.
//returns 1 if empty, 0 if there is at least one elements in the list
//reurns -1 if the list is NULL
int isEmpty(List *list) {
    if(list) {
        return (getSize(list) == 0) ? 1 : 0;
    } else {
        //list is NULL
        return -1;
    }
}

//returns an int whether or not the list contains an object.
//returns 1 if the list indeed contains, 0 if it does not contain.
//returns 0 if the list is NULL
int listContains(List *list, void *object) {
    if(list) {
        for(int i = 0; i < getSize(list); i++) {
            //linear scan through array
            if(list->array[i] == object) {
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

//removes the first element in the array
void* removeFromHead(List *list) {
    void* temp = list->array[0]; // saves return value
    for(int i = 0; i < getSize(list) - 1; i++) {
        //moves each element back by once space
        list->array[i] = list->array[i+1];
    }
    list->size--;
    return temp;
}
