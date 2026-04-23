#include <stdlib.h> //malloc, free
#include <stdio.h>
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
		if (newNode != NULL) {
			bst->root = newNode;
			return 0;
		}
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


void BinarySearchTree_printNodeInOrder(BSTNode* node) {
	if (node == NULL) return;
	BinarySearchTree_printNodeInOrder(node->left);
	printf("%d\n", node->data);
	BinarySearchTree_printNodeInOrder(node->right);
}

int BinarySearchTree_inOrderTraversal(BinarySearchTree* bst) {
	if (bst == NULL) return 1;
	BinarySearchTree_printNodeInOrder(bst->root);
	return 0;
}

void BinarySearchTree_printNodePreOrder(BSTNode* node) {
	if (node == NULL) return;
	printf("%d\n", node->data);
	BinarySearchTree_printNodePreOrder(node->left);
	BinarySearchTree_printNodePreOrder(node->right);
}

int BinarySearchTree_preOrderTraversal(BinarySearchTree* bst) {
	if (bst == NULL) return 1;
	BinarySearchTree_printNodePreOrder(bst->root);
	return 0;
}

void BinarySearchTree_printNodePostOrder(BSTNode* node) {
	if (node == NULL) return;
	BinarySearchTree_printNodePostOrder(node->left);
	BinarySearchTree_printNodePostOrder(node->right);
	printf("%d\n", node->data);
}

int BinarySearchTree_postOrderTraversal(BinarySearchTree* bst) {
	if (bst == NULL) return 1;
	BinarySearchTree_printNodePostOrder(bst->root);
	return 0;
}

int BinarySearchTree_deleteNode(BinarySearchTree* bst, BSTNode** node) {
	if (node == NULL || *node == NULL) return 1;
	//three cases: leaf, one child, two children
	//leaf first
	if ((*node)->left == NULL && (*node)->right == NULL) {
		free(*node);
		*node = NULL;
		return 0;
	}
	//one child
	if ((*node)->left == NULL || (*node)->right == NULL) {
		BSTNode* temp = *node;
		if ((*node)->left == NULL) {
			*node = (*node)->right;
		}
		else if ((*node)->right == NULL) {
			*node = (*node)->left;
		}
		free(temp);
		return 0;
	}
	//two children
	BSTNode** replacement = &(*node)->right;
	while ((*replacement)->left != NULL) {
		replacement = &(*replacement)->left;
	}
	(*node)->data = (*replacement)->data;
	BinarySearchTree_deleteNode(bst, replacement);
	return 0;
}

void BinarySearchTree_destroyHelper(BSTNode* node) {
	if (node == NULL) return;
	BinarySearchTree_destroyHelper(node->left);
	BinarySearchTree_destroyHelper(node->right);
	free(node);
}

int BinarySearchTree_destroy(BinarySearchTree** bst) {
	if (bst == NULL || *bst == NULL) return 1;
	BinarySearchTree_destroyHelper((*bst)->root);
	free(*bst);
	*bst = NULL;
	return 0;
}

BSTNode* BinarySearchTree_minimumValue(BSTNode* node) {
	if (node == NULL) return NULL;
	if (node->left != NULL) {
		return BinarySearchTree_minimumValue(node->left);
	}
	return node;
}

BSTNode* BinarySearchTree_maximumValue(BSTNode* node) {
	if (node == NULL) return NULL;
	if (node->right != NULL) {
		return BinarySearchTree_maximumValue(node->right);
	}
	return node;
}

int BinarySearchTree_heightHelper(BSTNode* node) {
	if (node == NULL) return 0;
	int leftHeight = BinarySearchTree_heightHelper(node->left);
	int rightHeight = BinarySearchTree_heightHelper(node->right);
	if (leftHeight >= rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
}

int BinarySearchTree_height(BinarySearchTree* bst) {
	if (bst == NULL) return 0;
	return BinarySearchTree_heightHelper(bst->root);
}

int BinarySearchTree_sizeHelper(BSTNode* node) {
	if (node == NULL) return 0;
	return 1 + BinarySearchTree_sizeHelper(node->left) + BinarySearchTree_sizeHelper(node->right);
}

int BinarySearchTree_size(BinarySearchTree* bst) {
	if (bst == NULL) return 0;
	return BinarySearchTree_sizeHelper(bst->root);
}

BSTNode* BinarySearchTree_kthSmallestHelper(BSTNode* node, int* visits, int k) {
	if (node == NULL || visits == NULL) return NULL;

	BSTNode* left = BinarySearchTree_kthSmallestHelper(node->left, visits, k);
	if (left != NULL) return left;

	*visits = *visits + 1;
	if (*visits == k) return node;
	
	return BinarySearchTree_kthSmallestHelper(node->right, visits, k);
}

//for now: assume k is not bigger than the size of the BST
BSTNode* BinarySearchTree_kthSmallestValue(BinarySearchTree* bst, int k) {
	if (bst == NULL) return NULL;
	if (k <= 0) return NULL;
	if (k > BinarySearchTree_size(bst)) return NULL;
	int visits = 0;
	return BinarySearchTree_kthSmallestHelper(bst->root, &visits, k);
}