/*
Implement a Priority Queue using an array. An element with smaller value has higher priority.
*/
#include <stdio.h>

#define MAX 50

int pq[MAX];
int size = -1;

// Insert element
void insert(int value)
{
    if(size == MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }

    size++;
    pq[size] = value;
}

// Delete element (highest priority = smallest number)
int delete()
{
    if(size == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int minIndex = 0;

    for(int i=1;i<=size;i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    int item = pq[minIndex];

    for(int i=minIndex;i<size;i++)
    {
        pq[i] = pq[i+1];
    }

    size--;

    return item;
}

// Display queue
void display()
{
    if(size == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue elements:\n");

    for(int i=0;i<=size;i++)
    {
        printf("%d ",pq[i]);
    }

    printf("\n");
}

int main()
{
    insert(30);
    insert(10);
    insert(40);
    insert(20);

    display();

    printf("Deleted element: %d\n", delete());

    display();

    return 0;
}
