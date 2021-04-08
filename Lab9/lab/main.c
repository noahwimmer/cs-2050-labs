#include "lab9.h"

void printList(List* list) {
    Node* cur = list->head;
    printf("[");
    while(cur != NULL) {
        int print = (int) cur->data;
        printf("%d ", print);
        cur = cur->next;
    }
    printf("]\n");
}

int main(void) {
    List* list = initList();

    insertAtTail(list, (void*) 1);
    insertAtTail(list, (void*) 2);
    insertAtTail(list, (void*) 3);


    printList(list);

    printf("Current size: %d\n", getSize(list));
    printf("test at index: 1 -> %d\n", (int) getAtIndex(list, 1));

    removeHead(list);
    printList(list);
    printf("Current size: %d\n", getSize(list));
    printf("test at index: 1 -> %d\n", (int) getAtIndex(list, 1));

    printf("Freeing List...\n");
    freeList(list);
    printList(list);


    return 0;
}
