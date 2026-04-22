#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;


//Node Functions
Node* Node_create(int data);

//LinkedList Functions
LinkedList* LinkedList_create();
void LinkedList_delete(LinkedList** linkedList);
void LinkedList_appendFront(LinkedList* linkedList, Node* newNode);
void LinkedList_appendEnd(LinkedList* linkedList, Node* newNode);
int LinkedList_appendAt(LinkedList* linkedList, Node* newNode, int position);
void LinkedList_deleteFront(LinkedList* linkedList);
void LinkedList_deleteEnd(LinkedList* linkedList);
int LinkedList_deleteAt(LinkedList* linkedList, int position);
void LinkedList_displayList(LinkedList* linkedList);
int LinkedList_deleteValue(LinkedList* linkedList, int value);
int LinkedList_reverseInPlace(LinkedList* linkedList);
int LinkedList_removeDuplicates(LinkedList* linkedList);
Node* LinkedList_findNthNodeFromEnd(LinkedList* linkedList, int n);
int LinkedList_mergeSortedLists(LinkedList** sortedList1, LinkedList* sortedList2);
int LinkedList_detectCycle(LinkedList* linkedList, int* error, Node** entryPoint);

#endif 