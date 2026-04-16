#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;

} LinkedList;

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
void LinkedList_appendAt(LinkedList* linkedList, Node* newNode, int position) {
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
            return;
        }
        searchNode = searchNode->next;
    }
    newNode->next = searchNode->next;
    searchNode->next = newNode;
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

void LinkedList_deleteAt(LinkedList* linkedList, int position) {
    if (position == 0) {
        LinkedList_deleteFront(linkedList);
        return;
    }
    Node* searchNode = linkedList->head;
    //iterate through the list until we get to the Node before the desired position
    for (int i = 0; i < position - 1; i++) {
        if (searchNode->next == NULL) {
            printf("Position specified is greater than the size of the linked list.\n");
            return;
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



int main() {
    return 0;
}
