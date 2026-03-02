/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of polynomial node
struct node
{
    int coeff;         // coefficient
    int power;         // power of x
    struct node *next; // pointer to next node
};

// Function to create polynomial
struct node* create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and power: ");
        scanf("%d %d", &newnode->coeff, &newnode->power);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Function to display polynomial
void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->power);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct node* add(struct node *p1, struct node *p2)
{
    struct node *head = NULL, *temp = NULL, *newnode;

    while(p1 != NULL && p2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;

        // If powers are equal, add coefficients
        if(p1->power == p2->power)
        {
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->power = p1->power;

            p1 = p1->next;
            p2 = p2->next;
        }
        // If p1 power is greater
        else if(p1->power > p2->power)
        {
            newnode->coeff = p1->coeff;
            newnode->power = p1->power;

            p1 = p1->next;
        }
        // If p2 power is greater
        else
        {
            newnode->coeff = p2->coeff;
            newnode->power = p2->power;

            p2 = p2->next;
        }

        // Insert node in result list
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Copy remaining terms of p1
    while(p1 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = p1->coeff;
        newnode->power = p1->power;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        p1 = p1->next;
    }

    // Copy remaining terms of p2
    while(p2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = p2->coeff;
        newnode->power = p2->power;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        p2 = p2->next;
    }

    return head;
}

// Main function
int main()
{
    struct node *p1, *p2, *result;

    printf("Enter first polynomial:\n");
    p1 = create();

    printf("Enter second polynomial:\n");
    p2 = create();

    printf("\nFirst polynomial: ");
    display(p1);

    printf("Second polynomial: ");
    display(p2);

    result = add(p1, p2);

    printf("Resultant polynomial: ");
    display(result);

    return 0;
}
