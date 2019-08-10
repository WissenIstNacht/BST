#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/*===== STRUCTURE ============================================================*/
pBST createBST() {
    pBST new_tree = malloc(sizeof(BST));

    if (!new_tree) return NULL;

    new_tree->size = 0;
    new_tree->root = NULL;

    return new_tree;
}

int insert(int key, pBST tree) {
    pNode new_node = malloc(sizeof(node));
    if (!new_node) return -1;

    new_node->key = key;
    new_node->l_child = NULL;
    new_node->r_child = NULL;

    if (tree->size == 0) {
        tree->root = new_node;
        tree->size = 1;
    }

    /* Get correct leaf */
    pNode curr_parent = tree->root;
    do {
        if (key < curr_parent->key) {
            if (curr_parent->l_child == NULL) {
                curr_parent->l_child = new_node;
                tree->size++;
                return 0;
            }
            curr_parent = curr_parent->l_child;
        } else if (key > curr_parent->key) {
            if (curr_parent->r_child == NULL) {
                curr_parent->r_child = new_node;
                tree->size++;
                return 0;
            }
            curr_parent = curr_parent->r_child;
        } else {
            return 1;
        }
    } while (1);
}

void removeNode() {}

void removeAll() {}

void removeTree() {}

/*===== UTILITY
 * ==============================================================*/

int search() {}
