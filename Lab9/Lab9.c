#include "Lab9.h"


List initList(int* ec) {
    List* list = malloc(sizeof(List));
    liststuff* _p = malloc(sizeof(liststuff));
    if(!list) {
        fprintf(stderr, "Error: Could not allocate memory.\n");
        *ec = 0;
    }
    _p->head = NULL;
    _p->tail = NULL;
    _p->size = 0;
    *ec = 1;
    list->p = _p;
    List ret = *list;
    return ret;
}

int getSize(List list) {
    return list.p->size;
}


int insertHead(List list, void* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list.p->head;
    newNode->prev = NULL;
    if(!newNode) {
        fprintf(stderr, "Error: Could not allocate memory.\n");
        return 0;
    }
    list.p->head = newNode;
    if(getSize(list) == 0) {
        list.p->tail = newNode;
    }
    list.p->size++;
    return 1;
}

void* removeHead(List list) {
    Node* head = list.p->head;
    void* data = head->data;
    list.p->head = head->next;
    free(head);
    return data;
}

int insertTail(List list, void* o) {
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        // malloc failed
        fprintf(stderr, "ERROR: Memory for node was not allocated.\n");
        return 1;
    }
    newNode->data = o;
    newNode->next = NULL;
    newNode->prev = list.p->tail;
    list.p->tail->next = newNode;
    list.p->tail = newNode;
    return 0;
}

void* removeTail(List list) {
    Node* tail = list.p->tail;
    Node* prev = tail->prev;
    void* data = tail->data;
    prev->next = NULL;
    free(tail);
    return data;
}

void freeList(List list) {
    Node* cur = list.p->head;
    printf("cur: %p\n", cur);
    while(cur) {
        removeHead(list);
        cur = cur->next;
    }
}
