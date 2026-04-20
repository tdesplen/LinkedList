#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node* Node_create(int data) {
    Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList* LinkedList_create() {
    LinkedList* linkedList = malloc(sizeof(struct LinkedList));
    if (linkedList == NULL) return NULL;
    linkedList->head = NULL;
    return linkedList;
}

void LinkedList_delete(LinkedList** linkedList) {
    if (linkedList == NULL || *linkedList == NULL) return;
    //grab the head
    Node* node = (*linkedList)->head;
    //while there are more nodes
    while (node != NULL) {
        Node* nextNode = node->next; //store the next node
        free(node); //free the current node
        node = nextNode; //set the current node to the next node
    }
    //release the linkedlist object
    free(*linkedList);
    *linkedList = NULL;
}

void LinkedList_appendFront(LinkedList* linkedList, Node* newNode) {
    newNode->next = linkedList->head;
    linkedList->head = newNode;
}

void LinkedList_appendEnd(LinkedList* linkedList, Node* newNode) {
    //check for empty list first
    if (linkedList->head == NULL) {
        linkedList->head = newNode;
        return;
    }
    //then search for the end
    Node* searchNode = linkedList->head;
    while (searchNode->next != NULL) {
        searchNode = searchNode->next;
    }
    searchNode->next = newNode;
}

//start position from 0, like an array
int LinkedList_appendAt(LinkedList* linkedList, Node* newNode, int position) {
    if (position < 0) {
        printf("Position is invalid\n");
        return 1;
    }
    //check for empty list
    if (linkedList->head == NULL && position > 0) {
        printf("List is empty and position greater than 0.\n");
        return 1;
    }
    if (position == 0) {
        LinkedList_appendFront(linkedList, newNode);
        return 0;
    }
    Node* searchNode = linkedList->head;
    //iteratre through the list until we get to the Node before the desired position
    for (int i = 0; i < position-1; i++) {
        if (searchNode->next == NULL) {
            printf("Position specified is greater than the size of the linked list.\n");
            return 1;
        }
        searchNode = searchNode->next;
    }
    newNode->next = searchNode->next;
    searchNode->next = newNode;
    return 0;
}

void LinkedList_deleteFront(LinkedList* linkedList) {
    if (linkedList->head == NULL) {
        printf("List is already empty");
        return;
    }
    Node* nextNode = linkedList->head->next;
    free(linkedList->head);
    linkedList->head = nextNode;
}

void LinkedList_deleteEnd(LinkedList* linkedList) {
    //case 1: empty list
    if (linkedList->head == NULL) return;
    //case 2: list with 1 item
    if (linkedList->head->next == NULL) {
        free(linkedList->head);
        linkedList->head = NULL;
        return;
    }
    //case 3: list with 2+ items
    Node* searchNode = linkedList->head;
    Node* newLastNode = NULL;
    while (searchNode->next != NULL) {
        newLastNode = searchNode;
        searchNode = searchNode->next;
    }
    free(searchNode);
    newLastNode->next = NULL;
}

int LinkedList_deleteAt(LinkedList* linkedList, int position) {
    if (position == 0) {
        LinkedList_deleteFront(linkedList);
        return 0;
    }
    Node* searchNode = linkedList->head;
    //iterate through the list until we get to the Node before the desired position
    for (int i = 0; i < position - 1; i++) {
        if (searchNode->next == NULL) {
            printf("Position specified is greater than the size of the linked list.\n");
            return 1;
        }
        searchNode = searchNode->next;
    }
    //case 1: searchNode -> desiredPosition -> nextNode
    //case 2: searchNode -> desiredPosition -> NULL
    //if there is a node after the one we want to delete
    if (searchNode->next->next != NULL) {
        Node* nextNext = searchNode->next->next;
        free(searchNode->next);
        searchNode->next = nextNext;
    }
    else if (searchNode->next->next == NULL) {
        free(searchNode->next);
        searchNode->next = NULL;
    }    
    return 0;
}

void LinkedList_displayList(LinkedList* linkedList) {
    if (linkedList == NULL) return;
    Node* node = linkedList->head;
    int counter = 0;
    while (node != NULL) {
        printf("%d. %d\n", counter, node->data);
        node = node->next;
        counter++;           
    }
}

//deletes all values in the list that match
int LinkedList_deleteValue(LinkedList* linkedList, int data) {
    if (linkedList == NULL) return 1;
    //check for empty list
    if (linkedList->head == NULL) return 1;
    //head -> node -> node
    Node** searchNode = &linkedList->head;
    while (*searchNode != NULL) {
        if ((*searchNode)->data == data) { //found one to delete
            Node* temp = *searchNode;
            *searchNode = (*searchNode)->next;
            free(temp);
        }
        else {
            searchNode = &(*searchNode)->next;
        }
    }
    return 0;
}

int LinkedList_reverseInPlace(LinkedList* linkedList) {
    if (linkedList == NULL || linkedList->head == NULL) return 1;
    Node* node = linkedList->head;
    Node* previousNode = NULL;
    while (node != NULL) {
        Node* temp = node->next;
        node->next = previousNode;
        previousNode = node;
        node = temp; 
    }
    linkedList->head = node;
    return 0;
}

int LinkedList_removeDuplicates(LinkedList* linkedList) {
    if (linkedList == NULL || linkedList->head == NULL) return 1;
    //loop through each node
    Node** currentNode = &linkedList->head;
    while (*currentNode != NULL) {
        Node** nextNode = &(*currentNode)->next;
        while (*nextNode != NULL) {
            if ((*nextNode)->data == (*currentNode)->data) {
                Node* temp = *nextNode;
                *nextNode = temp->next;

                free(temp);
            }
            else {
                nextNode = &(*nextNode)->next;

            }
        }
        currentNode = &(*currentNode)->next;
    }
    return 0;
}

Node* LinkedList_findNthNodeFromEnd(LinkedList* linkedList, int n) {
    if (linkedList == NULL || linkedList->head == NULL) return NULL;
    Node* targetNode = linkedList->head;
    Node* leadNode = linkedList->head;
    //loop until there are 'n' nodes between the target and lead
    for (int i = 0; i < n; i++) {
        if (leadNode->next == NULL) return NULL;
        else {
            leadNode = leadNode->next;
        }
    }
    //advance both at the same rate
    while (leadNode != NULL) {
        targetNode = targetNode->next;
        leadNode = leadNode->next;
    }
    return targetNode;
}

int LinkedList_mergeSortedLists(LinkedList** sortedList1, LinkedList* sortedList2) {
    if (sortedList1 == NULL || (*sortedList1)->head == NULL) return 1;
    if (sortedList2 == NULL || sortedList2->head == NULL) return 1;

    Node* newHead = NULL;
    Node* newTail = NULL;
    Node* node1 = NULL;
    Node* node2 = NULL;
    if ((*sortedList1)->head->data < sortedList2->head->data) {
        newHead = (*sortedList1)->head;
        newTail = (*sortedList1)->head;
        node1 = (*sortedList1)->head->next;
        node2 = sortedList2->head;
    }
    else {
        newHead = sortedList2->head;
        newTail = sortedList2->head;
        node2 = sortedList2->head->next;
        node1 = (*sortedList1)->head;
    }

    while (node1 != NULL && node2 != NULL) {
        if (node1->data < node2->data) {
            newTail->next = node1;
            node1 = node1->next;
        }
        else {
            newTail->next = node2;
            node2 = node2->next;
        }
        newTail = newTail->next;
    }

    if (node1 == NULL) {
        newTail->next = node2;
    }
    if (node2 == NULL) {
        newTail->next = node1;
    }
    
    (*sortedList1)->head = newHead;
    return 0;
}

//returns 0 is no cycle and 1 is cycle is present
int LinkedList_detectCycle(LinkedList* linkedList, int* error, Node** entryPoint) {
    int isCyclePresent = 0;
    if (error == NULL) return 0;
    if (entryPoint == NULL) {
        *error = 1;
        return 0;
    }
    *entryPoint = NULL;
    if (linkedList == NULL || linkedList->head == NULL) {
        *error = 1;
        return 0;
    }
    Node* slowPointer = linkedList->head;
    Node* fastPointer = linkedList->head;

    while (fastPointer != NULL && fastPointer->next != NULL) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer) {
            isCyclePresent = 1;
            break;
        }
    }
    if (isCyclePresent) {
        slowPointer = linkedList->head;
        while (slowPointer != fastPointer) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
        *entryPoint = fastPointer;
    }
    *error = 0;
    return isCyclePresent;
}
