#include "lab6.h"

int main(void) {
    List* list = initList(10);

    int* a = malloc(sizeof(int));
    *a = 5;
    insertAtHead(a, list);

    int* test = getAtIndex(0, list);
    printf("test: %d\n", *test);

    clearList(list);

    int* test2 = getAtIndex(0, list);
    //printf("test2: %d\n", *test2);

    freeList(list);

    return 0;
}
