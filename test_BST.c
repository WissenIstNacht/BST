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

int main(int argc, char const *argv[])
{
     printf("\n*********** Start linked list test program ***********\n");

    pBST test_tree = createBST();
    int curr_size = test_tree->size;
    printf("The value is %i\n", curr_size);
    
    insert(32, test_tree);
    insert(16, test_tree);
    insert(48, test_tree);

    int* a = traversal(1, test_tree);
    printArray(a, test_tree->size);

    printf("Ended linked list test program successfully!\n");
}
