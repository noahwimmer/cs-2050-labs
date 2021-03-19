#include "lab7.h"

int main(void) {
    Int* test = malloc(sizeof(Int));
    Int* test2 = malloc(sizeof(Int));
    Int* test3 = malloc(sizeof(Int));
    Int* sentinel = malloc(sizeof(Int));
    test->val = 1;
    test2->val = 2;
    test3->val = 3;
    sentinel->val = -1;

    List* list = initList();
    printf("List initialized.\n");
    printf("default size: %d\n", getSize(list));

    printf("insert 1\n");
    insertAfter(list, test, sentinel);
    printf("size after insert: %d\n", getSize(list));
    printf("insert 2\n");
    insertAfter(list, test2, test);
    printf("size after insert: %d\n", getSize(list));
    printf("insert 3\n");
    insertAfter(list, test3, test);
    printf("size after insert: %d\n", getSize(list));
    insertAfter(list, test, test2);
    printf("size after insert: %d\n", getSize(list));



    printf("list: ");
    printList(list);

    printf("\nremoving index 1\n");
    removeAtIndex(list, 1);
    printf("size after removal: %d\n", getSize(list));
    printList(list);


    freeList(list);

    return 0;
}
