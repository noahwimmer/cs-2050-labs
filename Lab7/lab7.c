#include "lab7.h"

/* This function returns an empty List object. */
List initList() {
    List* temp = malloc(sizeof(List));
    if(!temp) {
        //Malloc failed
        fprintf(stderr, "Malloc failed.\nUnable to allocate space.\n");
        return NULL;
    }
    List list = *temp;
    list.p->head = malloc(sizeof(Node));
    if(!list.p->head) {
        //Malloc failed
        fprintf(stderr, "Malloc failed.\nUnable to allocate space.\n");
        return NULL;
    }
    list.p->listLength = 0;

    return list;
}

/* This function inserts the object of the first parameter at the head of the list and returns an error code. */
int insertAtHead(void* o, List list) {
    Node* next = list.p->head->next;
    Node* node = malloc(sizeof(Node));
    if(!node) {
        fprintf(stderr, "Malloc failed.\n");
        return -1;
    }

    node->o = o;
    node->next = next;
    list.p->listLength++;
    return 0;
}

/* This function returns the object at the index location given by the first parameter. */
void* getAtIndex(int index, List list) {
    Node* temp = list.p->head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->o;
}

/* This function returns the size limit of the array, i.e., the value that was specified when the List was created. */
int getSizeLimit(List list) {

}

/* This function returns the number of objects in the list. */
int countItems(List list) {
    if(list) {
        return list.p->listLength;
    } else return 0;
}

/* This function clears the list (makes it empty) just like after it was created by initList. */
void clearList(List list) {
    for(int i = 0; i < countItems(list); i++) {
        Node* temp = list.p->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        free(temp);
    }
}

/* This function frees all memory allocated for a list. */
void freeList(List list) {
    clearList(list);
    free(list);
}
