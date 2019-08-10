/******************************************************************************
    Author: WissenIstNacht
    Date:

 * This Module implements a binary search tree. As the name "binary tree"
 * suggests this is a structure consisting of nodes where each parent has at
 * most two children attached. The children l and r have the following relation
 * to parent p: l < p and p < r. This allows for efficient searching, provided
 * that the tree remains balanced throughout the insertions of new children.
 *
 *
******************************************************************************/

#ifndef _BST_H_
#define _BST_H_

typedef struct node node, *pNode;
struct node{
    int key;
    pNode l_child;
    pNode r_child;
};

typedef struct{
    int size;
    // int depth;
    pNode root;
}BST, *pBST;

/*===== STRUCTURE ============================================================*/
pBST createBST();

int insert(int key, pBST tree);

void removeNode();

void removeAll();

void removeTree();

/*===== UTILITY ==============================================================*/

int search();


#endif