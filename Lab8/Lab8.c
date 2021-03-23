//
// Created by Noah Wimmer on 3/22/21.
//

#include "Lab8.h"

//printing a list of integers.
void printList(List* list) {
    Node* temp = list->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

int getSize(List *list) {
    return list->size;
}

// this function returns the node at the given index in a list.
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


int insertInOrder(void* o, List* list) {
    //if the list contains the object, place it after.
    if(listContains(list, o)) {
        printf("Inserting [%d] duplicate\n", (int) o);
        insertAfter(list, o, o);
        printList(list);
    } else {
        // if the list is empty
        int size = getSize(list);
        Node* current = list->head;
        if(size == 0) {
            printf("Inserting [%d] at head.\n", (int) o);
            insertAtHead(list, o);
            printList(list);
        }
        // list does not contain the object
        // bubble up to the position that it needs to insert at.
        // insert there

        // if size is 1
        else if(size == 1) {
            if(cmp(current->data, o) > 0) {
                // if current > o
                // insert in beginning
                printf("Inserting [%d] at head.\n", (int) o);
                insertAtHead(list, o);
                printList(list);
            } else {
                //insert at the end
                printf("Inserting [%d] at tail.\n", (int) o);
                insertAtTail(list, o);
                printList(list);
            }
        } else if(size > 1) {
            for(int i = 1; i < size; i++) {
                Node* p = getAtIndex(list, i - 1); // first node pair
                Node* q = getAtIndex(list, i); // second node pair
                int insert = (int) o;
                int a = (int) p->data;
                int b = (int) q->data;
                int eq = 0;
                if(cmp(o, p->data) < 0 && i == 1) { //insert at beginning
                    printf("Inserting [%d] at head.\n", (int) o);
                    insertAtHead(list, o);
                    printList(list);
                    break;
                }
                else if((cmp(o, p->data) > 0) && (cmp(o, q->data) < 0)) {
                    printf("Inserting [%d] in between [%d] and [%d].\n", (int) o, (int) p->data, (int) q->data);
                    eq = insertAfter(list, o, p->data);
                    printList(list);
                    if(eq) break;
                } else if(cmp(o, q->data) > 0 && (i == size - 1)) {
                    //insert at tail
                    printf("Inserting [%d] at tail.\n", (int) o);
                    insertAtTail(list, o);
                    printList(list);
                    break;
                }
            }
        }
    }
}

int removeEq(void* o, List* list) {
    // given that the list is sorted.
    // contains(o) {
    //     remove each instance of o
    // }
    if(!(listContains(list, o))) {
        return 0;
    } else {
        // needs to remove objects
        Node* temp = list->head;
        int i = 0;
        while(listContains(list, o)) {
            //remove each node
            if(cmp(temp->data, o) == 0) {
                //remove temp
                temp = temp->next;
                removeNodeAtIndex(list, i);
            } else {
                temp = temp->next;
                i++;
            }
        } return 0;
    }
}

int cmp(int a, int b) {
    return a-b;
}

/*int cmp(void* o1, void* o2){
    int* a = (int*) o1;
    int* b = (int*) o2;
    return(*a - *b);
}*/

int listContains(List *list, void *object) {
    Node* temp = list->head;
    for(int i = 0; i < getSize(list); i++) {
        if(temp->data == object) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void removeNodeAtIndex(List *list, int index) {
    if(index > 0) {
        //remove a node in middle of the list
        Node* p = getAtIndex(list, index);
        Node* q = getAtIndex(list, index - 1);
        q->next = q->next->next;
        list->size--;
        free(p);
    } else if(index == getSize(list) - 1) {
        // remove the end of the list
        Node* p = getAtIndex(list, index);
        Node* q = getAtIndex(list, index - 1);
        q->next = NULL;
        list->size--;
        free(p);
    } else {
            //remove head.
            Node* p = getAtIndex(list, 0);
            list->head = list->head->next;
            list->size--;
            free(p);
    }
}


int insertAfter(List *list, void *object, void* sentinel) {
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
            //find last sentinel node.
            if(i == getSize(list) - 1) {
                if(temp->data == sentinel) {
                    //insert newNode here
                    newNode->next = temp->next;
                    temp->next = newNode;
                    list->size++;
                    return 1;
                } else {
                    temp = temp->next;
                }
            } else {
                if(temp->data == sentinel && temp->next->data != sentinel) {
                    //insert newNode here
                    newNode->next = temp->next;
                    temp->next = newNode;
                    list->size++;
                    return 1;
                } else {
                    temp = temp->next;
                }
            }
        }
        return 0;
    }
}

void insertAtHead(List* list, void* o) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = o;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void insertAtTail(List* list, void* o) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = o;
    newNode->next = NULL;
    Node* p = getAtIndex(list, getSize(list) - 1);
    p->next = newNode;
    list->size++;
}
