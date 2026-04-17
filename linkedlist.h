#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

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
void LinkedList_appendAt(LinkedList* linkedList, Node* newNode, int position);
void LinkedList_deleteFront(LinkedList* linkedList);
void LinkedList_deleteEnd(LinkedList* linkedList);
void LinkedList_deleteAt(LinkedList* linkedList, int position);
void LinkedList_displayList(LinkedList* linkedList);


#endif 