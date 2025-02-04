#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/*===== AUXILIARY ============================================================*/
static pNode get(int key, pBST tree) {
    pNode curr_parent = tree->root;
    do {
        if (key < curr_parent->key) {
            if (curr_parent->l_child == NULL) {
                return NULL;
            }
            curr_parent = curr_parent->l_child;
        } else if (key > curr_parent->key) {
            if (curr_parent->r_child == NULL) {
                return NULL;
            }
            curr_parent = curr_parent->r_child;
        } else {
            return curr_parent;
        }
    } while (1);
}

static void inOrder(pNode curr_node, int* out, int* count){
    if(curr_node->l_child != NULL){
        inOrder(curr_node->l_child, out, count);
    }
    out[*count] = curr_node->key;
    (*count)++;
    if (curr_node->r_child != NULL){
        inOrder(curr_node->r_child, out, count);
    }
}

static void preOrder(pNode curr_node, int* out, int* count){
    out[*count] = curr_node->key;
    (*count)++;
    if(curr_node->l_child != NULL){
        inOrder(curr_node->l_child, out, count);
    }
    if (curr_node->r_child != NULL){
        inOrder(curr_node->r_child, out, count);
    }
}

static void postOrder(pNode curr_node, int* out, int* count){
    if(curr_node->l_child != NULL){
        inOrder(curr_node->l_child, out, count);
    }
    if (curr_node->r_child != NULL){
        inOrder(curr_node->r_child, out, count);
    }
    out[*count] = curr_node->key;
    (*count)++;
}

static void recDeleting(pNode curr_node){
    if(curr_node->l_child != NULL){
        recDeleting(curr_node->l_child);
        curr_node->l_child = NULL;
    }
    if(curr_node->r_child != NULL){
        recDeleting(curr_node->r_child);
        curr_node->r_child = NULL;
    }
    free(curr_node);
}

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
        return 0;
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

int removeNode(int key, pBST tree) {
    if (tree->size == 0) return -1;

    /* Find note that's to be deleted */
    pNode parent = NULL;
    pNode curr_node = tree->root;
    do {
        if (key < curr_node->key) {
            if (curr_node->l_child == NULL) {  // node not in tree
                return -1;
            }
            parent = curr_node;
            curr_node = curr_node->l_child;
        } else if (key > curr_node->key) {
            if (curr_node->r_child == NULL) {  // node not in tree
                return -1;
            }
            parent = curr_node;
            curr_node = curr_node->r_child;
        } else {  // Node found
            break;
        }
    } while (1);
    pNode to_delete = curr_node;

    /* Delete node according to Hibbard's case distinction */
    /* Deleted node has no children */
    if (to_delete->l_child == NULL && to_delete->r_child == NULL) {
        if(to_delete == tree->root){    //SC: root
            tree->root = NULL;
        }else if (to_delete->key < parent->key) {
            parent->l_child = NULL;
        } else {
            parent->r_child = NULL;
        }
        free(to_delete);
    }
    /* Deleted node has only right child */
    else if (to_delete->l_child == NULL) {
        if(to_delete == tree->root){    //SC: root
            tree->root = to_delete->r_child;
        }else if (to_delete->key < parent->key) {
            parent->l_child = to_delete->r_child;
        } else {
            parent->r_child = to_delete->r_child;
        }
        free(to_delete);
    }
    /* Deleted node has only left child */
    else if (to_delete->r_child == NULL) {
        if(to_delete == tree->root){    //SC: root
            tree->root = to_delete->l_child;
        }else if (to_delete->key < parent->key) {
            parent->l_child = to_delete->r_child;
        } else {
            parent->r_child = to_delete->r_child;
        }
        free(to_delete);
    }
    /* Deleted node has both children */
    else {
        /* Find next larger node (to replace to_delete) */
        pNode next_larger_parent = to_delete;
        pNode next_larger = to_delete->r_child;
        while (next_larger->l_child != NULL) {
            next_larger_parent = next_larger;
            next_larger = next_larger->l_child;
        }
        /* Next larger node is right child */
        if (next_larger == to_delete->l_child) {
            next_larger->l_child = to_delete->l_child;
        }
        /* Next larger node has a right child */
        else if (next_larger->r_child != NULL) {
            next_larger_parent->l_child = next_larger->r_child;
            next_larger->l_child = to_delete->l_child;
            next_larger->r_child = to_delete->r_child;
        } else {
            next_larger->l_child = to_delete->l_child;
            next_larger->r_child = to_delete->r_child;
        }
        /* Rearrange pointers. */
        if(to_delete == tree->root){    //SC: root
            tree->root = next_larger;
        }else if (to_delete->key < parent->key) {
            parent->l_child = next_larger;
        } else {
            parent->r_child = next_larger;
        }
    }
    tree->size--;
    return 1;
}

void removeAll(pBST tree) {
    if(tree->size != 0){
        recDeleting(tree->root);
        tree->root = NULL;
        tree->size = 0;
    }
}

void removeTree(pBST tree) {
    removeAll(tree);
    free(tree);
}

/*===== UTILITY ==============================================================*/
int search(int key, pBST tree) {
    pNode curr_parent = tree->root;
    do {
        if (key < curr_parent->key) {
            if (curr_parent->l_child == NULL) {
                return -1;
            }
            curr_parent = curr_parent->l_child;
        } else if (key > curr_parent->key) {
            if (curr_parent->r_child == NULL) {
                return -1;
            }
            curr_parent = curr_parent->r_child;
        } else {
            return 1;
        }
    } while (1);
}

int* traversal(int type, pBST tree){
    if(tree->size == 0) return NULL;

    int* out = malloc(4 * tree->size);
    if (out == NULL) return NULL;
    int* count = malloc(4);
    if (count == NULL) return NULL;
    *count = 0;

    if (type == 1) {
        inOrder(tree->root, out, count);
    }else if(type == 2){
        preOrder(tree->root, out, count);
    }else if(type == 3){
        postOrder(tree->root, out, count);
    }else{
        return NULL; 
    }
    free(count);
    return out;
}

void printInOrder(pBST tree){
    if(tree->size == 0){
        printf("The tree is empty: []\n");
        return;
    }

    int* a = traversal(1, tree);
    int sz = tree->size;

    printf("[");
    for (int i = 0; i < sz; i++) {
        if (i == sz - 1) {
            printf("%i", a[i]);
        } else {
            printf("%i, ", a[i]);
        }
    }
    printf("]\n");

    free(a);
}

int min(pBST tree){
    if(tree->size == 0){
        return -1;
    }
    pNode curr_node = tree->root;
    while(curr_node->l_child != NULL){
        curr_node = curr_node->l_child;
    }
    return curr_node->key;
}

int max(pBST tree){
    if(tree->size == 0){
        return -1;
    }
    pNode curr_node = tree->root;
    while(curr_node->r_child != NULL){
        curr_node = curr_node->r_child;
    }
    return curr_node->key;
}