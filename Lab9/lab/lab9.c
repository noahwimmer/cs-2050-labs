#include "lab9.h"

// COMPLEXITY: O(1)
// sets up a new list object.
List* initList() {
    List* list = malloc(sizeof(List));
    if(!list) {
        //malloc failed
        fprintf(stderr, "ERROR: Could not allocate memory for List.\n");
        return NULL;
    }

    //setting default values
    list->size = 0;
    list->head = NULL;

    return list;
}

// COMPLEXITY: O(1)
//returns the size of the list.
int getSize(List *list) {
    return list->size;
}

// COMPLEXITY: O(n)
// returns the object in the node at index, "index"
void* getAtIndex(List *list, int index) {
    Node* cur = list->head;
    for(int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

// COMPLEXITY: O(n)
// frees the list
void freeList(List *list) {
    Node* cur = list->head;
    while(cur) {
        removeHead(list);
        cur = cur->next;
    }
}

// COMPLEXITY: O(n)
// since this relies on o(n) time, we must use a singly-linked list, otherwise, an insertTail function
// would have an O(1) time.
// Inserts the given object at the tail of the list in O(n) time. Returns 1 on success, else 0.
int insertAtTail(List *list, void *object) {
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        //malloc failed
        fprintf(stderr, "ERROR: Could not allocate memory for Node.\n");
        return 0;
    }
    newNode->next = NULL;
    newNode->data = object;

    if(getSize(list) == 0) {
        list->head = newNode;
        list->size++;
        return 1;
    }

    //get the last node in the list
    Node* last = list->head;
    for(int i = 0; i < list->size - 1; i++) {
        last = last->next;
    }

    //assign values
    last->next = newNode;
    list->size++;
    return 1;
}

// COMPLEXITY: O(1)
// This function returns the object at the head of the list in O(1) time
void* getHead(List *list) {
    return list->head;
}

// COMPLEXITY: O(1)
// This function removes and returns the object at the head of the list in O(1) time
void* removeHead(List *list) {
    Node* old = list->head; //saving the old head for free
    void* data = list->head->data; // saving the old data for return value
    list->head = list->head->next; // assigning new head
    free(old);
    list->size--;
    return data;
}
