#include "Lab9.h"

void printList(List list) {
    Node* cur = list.p->head;
    while(cur != NULL) {
        int print = (int) cur->data;
        printf("%d ", print);
        cur = cur->next;
    }
    printf("\n");
}


int main(void) {

    int ec;
    List list = initList(&ec);

    if(ec) {
        insertHead(list, (void*) 1);
        insertHead(list, (void*) 2);
        insertTail(list, (void*) 3);
        removeHead(list);
        removeTail(list);
    }
    printList(list);
    freeList(list);
    printList(list);
}
