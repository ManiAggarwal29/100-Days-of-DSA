/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if(front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != front);
}

int main()
{
    int n, x, i;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    printf("Circular Queue elements are:\n");
    display();

    return 0;
}
