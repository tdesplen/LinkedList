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
BSTNode* BinarySearchTree_search(BinarySearchTree* bst, int data);
void BinarySearchTree_printNodeInOrder(BSTNode* node);
int BinarySearchTree_inOrderTraveral(BinarySearchTree* bst);
void BinarySearchTree_printNodePreOrder(BSTNode* node);
int BinarySearchTree_preOrderTraversal(BinarySearchTree* bst);
void BinarySearchTree_printNodePostOrder(BSTNode* node);
int BinarySearchTree_postOrderTraversal(BinarySearchTree* bst);
int BinarySearchTree_deleteNode(BinarySearchTree* bst, BSTNode** node);
void BinarySearchTree_destroyHelper(BSTNode* node);
int BinarySearchTree_destroy(BinarySearchTree** bst);
BSTNode* BinarySearchTree_minimumValue(BSTNode* bst);
BSTNode* BinarySearchTree_maximumValue(BSTNode* bst);
int BinarySearchTree_height(BinarySearchTree* height);


#endif