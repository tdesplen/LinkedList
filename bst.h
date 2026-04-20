#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


//design choice: less than or equalt to -> left, greater than -> right

typedef struct BinarySearchTree {
	BSTNode* root;
} BinarySearchTree;

typedef struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
} BSTNode;

// BSTNode functions
BSTNode* BSTNode_create(int data);

//BST functions
BinarySearchTree* BinarySearchTree_create();
int BinarySearchTree_insert(BinarySearchTree* bst, int data);
BSTNode* BinarySearchTree_insertHelper(BSTNode* bstNode, int data);
int BinarySearchTree_insertRecursive(BinarySearchTree* bst, int data);
int BinarySearchTree_delete(BinarySearchTree* bste, int data);
int BinarySearchTree_destroy(BinarySearchTree* bst);
BSTNode* BinarySearchTree_search(BinarySearchTree* bst, int data);


#endif