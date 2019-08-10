#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

int main(int argc, char const *argv[])
{
     printf("\n*********** Start linked list test program ***********\n");

    pBST test_tree = createBST();
    int curr_size = test_tree->size;
    printf("The value is %i\n", curr_size);
    
    insert(1, test_tree);
    curr_size = test_tree->size;
    printf("The value is %i\n", curr_size);
    int first_key = test_tree->root->key;
    printf("The value is %i\n", first_key);
    return 0;

    printf("Ended linked list test program successfully!\n");
}
