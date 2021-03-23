#include "Lab8.h"

int main() {
    srand(time(0));
    List* list = initList();
    //printf("cmp test: %d\n", cmp(5, 2));

    for(int i = 0; i < 10; i++) {
        int insert = rand() % 6;
        insertInOrder(insert, list);
    }

    printf("Removing all 5's in the list.\n");
    removeEq(5, list);
    printList(list);

    return 0;
}
