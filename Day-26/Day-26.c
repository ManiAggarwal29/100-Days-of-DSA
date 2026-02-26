/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at Beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode; // new head
}

// Insert at End
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Traverse Forward
void traverseForward(struct Node* head) {
    struct Node* temp = head;

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse Backward
void traverseBackward(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) return;

    // go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main Function
int main() {
    struct Node* head = NULL;

    // Insertion
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    // Traversal
    traverseForward(head);
    traverseBackward(head);

    return 0;
}
