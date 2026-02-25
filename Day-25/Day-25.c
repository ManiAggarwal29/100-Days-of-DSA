/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure
struct node {
    int data;
    struct node* next;
};

// Insert at end
struct node* insert(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Count occurrences
int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}

// Display list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    struct node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 20);

    printf("Linked List:\n");
    display(head);

    int key = 20;
    int count = countOccurrences(head, key);

    printf("Occurrences of %d = %d\n", key, count);

    return 0;
}
