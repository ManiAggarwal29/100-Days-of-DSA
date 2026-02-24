/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
// Function to delete first occurrence of key
struct node* deleteKey(struct node* head, int key) {
    struct node *temp = head, *prev = NULL;
    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // If key not found
    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }
    // Unlink the node
    prev->next = temp->next;
    free(temp);
    return head;
}
// Function to insert at end
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
// Display list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct node* head = NULL;
    // Creating list
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 20);
    printf("Original List:\n");
    display(head);
    int key = 20;
    head = deleteKey(head, key);
    printf("After Deleting %d:\n", key);
    display(head);
    return 0;
}
