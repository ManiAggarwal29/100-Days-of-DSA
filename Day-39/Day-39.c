/*
Implement a Min Heap using an array where the smallest element is always at the root.
*/
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify upward (used after insertion)
void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    while(index > 0 && heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Insert element into heap
void insert(int value)
{
    if(size == MAX)
    {
        printf("Heap is full\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Heapify downward (used after deletion)
void heapifyDown(int index)
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Delete root (minimum element)
void deleteMin()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// Display heap
void display()
{
    for(int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main()
{
    insert(20);
    insert(10);
    insert(30);
    insert(5);
    insert(15);

    printf("Min Heap: ");
    display();

    deleteMin();

    printf("Heap after deletion: ");
    display();

    return 0;
}
