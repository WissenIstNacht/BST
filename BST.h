/******************************************************************************
    Author: WissenIstNacht
    Date: 12-08-2019

 * This Module implements a binary search tree. As the name "binary tree"
 * suggests this is a structure consisting of nodes where each parent has at
 * most two children attached. The children l and r have the following relation
 * to parent p: l < p and p < r. This allows for efficient searching, provided
 * that the tree remains balanced throughout the insertions of new children.
 * This will not always be the case, but for random insertions the tree is
 * expected to be balanced.
 *
******************************************************************************/

#ifndef _BST_H_
#define _BST_H_

typedef struct node node, *pNode;
struct node {
    int key;
    pNode l_child;
    pNode r_child;
};

typedef struct {
    int size;
    // int depth;
    pNode root;
} BST, *pBST;

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

/** Removes the tree and all its elements.
 *
 * param
 * -----
 * tree: pointer to tree.
 *
 * This method applies removeAll and then deletes the list structure itself,
 * freeing its memory.
 */
void removeTree(pBST tree);

/*===== UTILITY ==============================================================*/

/** Searches for an item in a tree.
 *
 * param
 * -----
 *  - key: key that's to be searched.
 *  - tree: pointer to tree.
 *
 * return
 * ------
 *  - {1} if key is present in the tree
 *  - {-1} if key was not found.
 *
 * This method searches the list item by item. This thakes O(n).
 * In case a key is in the list multiple times it output the position where the
 * key was first encountered.
 */
int search(int key, pBST tree);

/** Traverses each node of the tree in a certain order.
 *
 * param
 * -----
 *  - type: type of traversal to perform
 *          {1} in-order
 *          {2} pre-order
 *          {3} post-order
 *  - tree: pointer to tree.
 *
 * return
 * ------
 *  - array of integers holding the traversal order if tree is not empty
 *  - {null} if there was a problem (E.g. tree empty, not enough mem, etc.)
 *
 * This method returns an array represantation of the tree. How the array is
 * populated depends on the type of traversal. In-order, for example, first ads
 * the left child to an array, then the parent and then the node. Done
 * recursively this leads to a "flattened" representation of the tree. 
 */
int* traversal(int type, pBST tree);

/** Prints in-order representation of a tree.
 *
 * param
 * -----
 *  - tree: pointer to tree.
 *
 * This method simply formats and prints the array returned by the traversal
 * method. 
 */
void printInOrder(pBST tree);

int min(pBST tree);

int max(pBST tree);

#endif