#include "lab6.h"

int main(void) {
    List* list = initList(10);

    int* a = malloc(sizeof(int));
    int* b = malloc(sizeof(int));
    *a = 5;
    *b = 10;
    insertAtTail(list, a);
    insertAtTail(list, b);


    int* test = getAtIndex(list, 0);
    int* test2 = getAtIndex(list, 1);
    printf("test: %d\n", *test);
    printf("test2: %d\n", *test2);

    int* test3 = removeFromHead(list);
    test2 = getAtIndex(list, 0);

    printf("test3: %d\n", *test3);
    printf("test2: %d\n", *test2);

    freeList(list);


    return 0;
}
