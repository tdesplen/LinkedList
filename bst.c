#include <stdlib.h> //malloc, free
#include "bst.h"

BSTNode* BSTNode_create(int data) {
	BSTNode* node = malloc(sizeof(BSTNode));
	if (node == NULL) return NULL;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BinarySearchTree* BinarySearchTree_create() {
	BinarySearchTree* bst = malloc(sizeof(BinarySearchTree));
	if (bst == NULL) return NULL;
	return bst;
}

int BinarySearchTree_insert(BinarySearchTree* bst, int data) {
	if (bst == NULL) return 1;
	BSTNode* newNode = BSTNode_create(data);
	if (bst->root == NULL) {
		bst->root = newNode;
		return 0;
	}
	BSTNode* parent = bst->root;
	int placed = 0;
	while (!placed) {
		if (newNode->data <= parent->data) {
			if (parent->left == NULL) {
				parent->left = newNode;
				placed = 1;
			}
			else {
				parent = parent->left;
			}
		}
		else {
			if (parent->right == NULL) {
				parent->right = newNode;
				placed = 1;
			}
			else {
				parent = parent->right;
			}
		}
	}
	return 0;
}

BSTNode* BinarySearchTree_insertHelper(BSTNode* bstNode, int data) {
	if (bstNode == NULL) return BSTNode_create(data);
	if (data <= bstNode->data) {
		bstNode->left = BinarySearchTree_insertHelper(bstNode->left, data);
	}
	else {
		bstNode->right = BinarySearchTree_insertHelper(bstNode->right, data);
	}
	return bstNode;

}

int BinarySearchTree_insertRecursive(BinarySearchTree* bst, int data) {
	if (bst == NULL) return 1;
	bst->root = BinarySearchTree_insertHelper(bst->root, data);
	return 0;
}

BSTNode* BinarySearchTree_searchHelper(BSTNode* searchNode, int data) {
	if (searchNode == NULL) return NULL;
	if (data < searchNode->data) {
		return BinarySearchTree_searchHelper(searchNode->left, data);
	}
	else if (data > searchNode->data) {
		return BinarySearchTree_searchHelper(searchNode->right, data);
	}
	return searchNode;
}

BSTNode* BinarySearchTree_search(BinarySearchTree* bst, int data) {
	if (bst == NULL) return NULL;
	return BinarySearchTree_searchHelper(bst->root, data);
}