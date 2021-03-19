#include "lab7.h"

// my function to print each test value in my linked list.
//edited lab7.h file to incorperate testing
void printList(List* list) {
    Node* temp = list->head;
    while(temp != NULL) {
        Int* d = (Int*) temp->data;
        printf("%d ", d->val);
        temp = temp->next;
    }
    printf("\n");
}

// This function initializes and returns a linked list.
List* initList() {
    List* list = malloc(sizeof(List));
    if(!list) {
        fprintf(stderr, "Malloc failed. Function return NULL.\n");
        return NULL;
    }
    //default values
    list->size = 0;
    list->head = NULL;
    return list;
}
// This function takes a linked list and returns the number of elements on the list.
int getSize(List *list) {
    return list->size;
}
//This function takes a linked list and frees all memory allocated for the list.
// Remember that you should not free the user’s data, as that does not belong to your library.
void freeList(List *list) {
    while(getSize(list) > 0) {
        //free each node
        int i;
        Node* temp = list->head;
        for(i = 0; i < getSize(list); i++) {
            temp = temp->next;
        }
        free(temp);
        list->size--;
    }
    free(list);
}

// This function takes a linked list and returns the object at the given index, or NULL on error.
void* getAtIndex(List *list, int index) {
    if(getSize(list) > 0) {
        //has at least one node
        Node* temp = list->head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    } else {
        //list has no nodes
        return NULL;
    }
}

// This function takes a linked list and attempts to insert the given object after the specified sentinel object in the list.
// If the sentinel object does not exist on the list, the object should be inserted at the end of the list.
// It should return 1 on success and 0 on failure.
int insertAfter(List *list, void *object, void *sentinel) {
    if(!listContains(list, sentinel)) {
        //if sentinel does not exist
        if(getSize(list) > 0) {
            //insert at the end
            Node* newNode = malloc(sizeof(Node));
            if(!newNode) {
                fprintf(stderr, "Malloc failed.\n");
                return 0;
            }
            Node* tail = getAtIndex(list, getSize(list) - 1);
            newNode->data = object;
            newNode->next = NULL;
            tail->next = newNode;
            list->size++;
            return 1;
        } else {
            //malloc first node
            Node* newNode = malloc(sizeof(Node));
            if(!newNode) {
                fprintf(stderr, "Malloc failed.\n");
                return 0;
            }
            newNode->data = object;
            newNode->next = NULL;
            list->head = newNode;
            list->size++;
            return 1;
        }
    } else {
        //sentinel exists
        Node* newNode = malloc(sizeof(Node));
        if(!newNode) {
            fprintf(stderr, "Malloc failed.\n");
            return 0;
        }
        newNode->data = object;
        Node* temp = list->head;
        for(int i = 0; i < getSize(list); i++) {
            //find sentinel node.
            if(temp->data == sentinel) {
                //insert newNode here
                newNode->next = temp->next;
                temp->next = newNode;
                list->size++;
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
}

//This function takes a linked list and returns 1 if the given object is on the list, or 0 otherwise.
int listContains(List *list, void *object) {
    for(int i = 0; i < getSize(list); i++) {
        Node* temp = list->head;
        if(temp->data == object) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
// This function takes a linked list and removes the object at the given index of the list.
// This function must return the object to the user.
void* removeAtIndex(List *list, int index) {
    if(index > 0) {
        Node* p = getAtIndex(list, index);
        Node* q = getAtIndex(list, index - 1);
        q->next = q->next->next;
        list->size--;
        free(p);
        return p->data;
    } else {
        Node* p = getAtIndex(list, 0);
        list->head = NULL;
        list->size--;
        free(p);
        return p->data;
    }
}
