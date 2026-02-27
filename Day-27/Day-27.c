/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to find length of list
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    // Find difference
    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2) {
            return ptr1; // intersection node
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // no intersection
}

// Main function
int main() {
    // Create common part
    struct Node* common = newNode(30);
    common->next = newNode(40);
    common->next->next = newNode(50);

    // First list
    struct Node* head1 = newNode(10);
    head1->next = newNode(20);
    head1->next->next = common;

    // Second list
    struct Node* head2 = newNode(15);
    head2->next = common;

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("Intersection point: %d\n", intersection->data);
    else
        printf("No intersection\n");

    return 0;
}
