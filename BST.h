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
/** Create empty tree with ptr to root NULL and size 0.
 *
 * return
 * ------
 *  - Pointer to (empty) list structure.
 */
pBST createBST();

/** Insert item into the tree.
 *
 * param
 * -----
 *  - key:  new key to be inserted in tree.
 *  - tree:   pointer to tree.
 *
 * return
 * ------
 *  - {1} if the insertion was successful,
 *  - {-1} if not (e.g. no more mem, etc,)
 *
 * Since the the right spot for the node has to be searched before inserting,
 * this runs in O(log n).
 */
int insert(int key, pBST tree);

/** Removes an and deletes an item form the list.
 * 
 * param
 * -----
 *  - key: Key of element that's to be deleted.
 *  - tree:  Pointer to tree.
 *
 * This method first searches the tree for the element with the specified key.
 * In order to preserve the tree invariant deletion leads to a potential
 * rearrangement of the tree structure. Afterwards, the memory allocated for the
 * element is then.
 */
void removeNode(int key, pBST tree);

/** Removes and deletes all items fromm the tree.
 * 
 * param
 * -----
 *  - tree:  pointer to tree.
 *
 * This method iterates through the tree (recursively), deleting each element.
 * It frees the memory of the allocated elements, sets the root null and the
 * size 0.
 */
void removeAll(pBST tree);

/** Removes the tree and all its items.
 *
 * param
 * -----
 * tree: pointer to list.
 *
 * This method applies removeAll and then deletes the list structure itself,
 * freeing its memory. 
 */
void removeTree(pBST tree);

/*===== UTILITY ==============================================================*/

int search(int key, pBST tree);

int* traversal(int type, pBST tree);

void printInOrder(pBST tree);

int min(pBST tree);

int max(pBST tree);

#endif