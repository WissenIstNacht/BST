#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

void printArray(int* array, int sz) {
    printf("[");
    for (int i = 0; i < sz; i++) {
        if (i == sz - 1) {
            printf("%i", array[i]);
        } else {
            printf("%i, ", array[i]);
        }
    }
    printf("]\n");
}

void test_insert() {
    pBST test_tree = createBST();
    printf("\nCTRL: BST before test:\n");
    printInOrder(test_tree);

    insert(32, test_tree);
    insert(16, test_tree);
    insert(48, test_tree);
    insert(8, test_tree);
    insert(24, test_tree);
    insert(40, test_tree);
    insert(56, test_tree);

    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    removeAll(test_tree);

    for (size_t i = 0; i < 8; i++) {
        insert(i, test_tree);
    }
    
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    removeTree(test_tree);
}

int main(int argc, char const* argv[]) {
    printf("\n*********** Start linked list test program ***********\n");
    test_insert();
    printf("Ended linked list test program successfully!\n");
}
