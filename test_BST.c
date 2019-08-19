#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

void test_insert() {
    pBST test_tree = createBST();
    printf("\nCTRL: BST before test:\n");
    printInOrder(test_tree);

    insert(32, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    insert(16, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    insert(48, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    insert(8, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    insert(24, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    insert(40, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    insert(56, test_tree);
    printf("\nTEST - Adding powers of two:\n");
    printInOrder(test_tree);

    removeAll(test_tree);
    printf("\nCTRL: BST before test:\n");
    printInOrder(test_tree);

    for (size_t i = 0; i < 8; i++) {
        insert(i, test_tree);
        printf("\nTEST - Adding numbers 0 to 7:\n");
        printInOrder(test_tree);
    }

    removeTree(test_tree);
}

void test_remove() {
    pBST test_tree = createBST();
    printf("\nCTRL: BST before test:\n");
    printInOrder(test_tree);

    removeNode(42, test_tree);
    printf("\nTEST - Remove from empty tree:\n");
    printInOrder(test_tree);

    insert(4, test_tree);
    insert(2, test_tree);
    insert(6, test_tree);
    insert(1, test_tree);
    insert(3, test_tree);
    insert(5, test_tree);
    insert(7, test_tree);
    printf("\nCTRL: BST before test:\n");
    printInOrder(test_tree);

    for (size_t i = 0; i < 10; i++) {
        if(removeNode(i, test_tree) < 0){
            printf("\nTEST - Removing inexistent key %li:\n", i);
            printInOrder(test_tree);
        }else{
            printf("\nTEST - Removing existent key %li:\n", i);
            printInOrder(test_tree);
        }
    }
}

int main(int argc, char const* argv[]) {
    printf("\n*********** Start linked list test program ***********\n");
    test_remove();
    printf("Ended linked list test program successfully!\n");
}
