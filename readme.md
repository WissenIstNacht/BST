# BST

## What

This Module implements a binary search tree. As the name "binary tree" suggests
this is a structure consisting of nodes where each any given node, called a
parent p has at most two children attached. The left and right children, called
l and r, respectively, always respect the following relationship to p: 

- l < p 
- p < r
  
These rules are sometimes called the tree invariant. They allow for efficient
insertion, searching, and deleting, provided that the tree remains balanced
throughout these operations. This will not always be the case, but for random
insertions the tree is expected to be balanced.

## How

The module is designed such that one works with a pointer to a BST structure.
That pointer can be obtained by creating a BST using the corresponding function:

`pBST ptr_to_tree = createBST();`

This tree contains a pointer to the root of the actual tree as well as the
number of elements currently contained in the tree:

`pNode ptr_to_roor = ptr_to_tree->root`
`int sz = ptr_to_tree->size`

The elements of the tree are called nodes. Each node holds two pointers to its
children. Functions usually require to pass the pointer to the tree. For
example, when inserting and element:

`insert(42, ptr_to_tree);`

It is possible to delete either individual elements, or all elements. If the
tree is no longer used, one should free the memory used by the tree. This can be
done using removeTree, which frees every node as well as the tree structure
itself.