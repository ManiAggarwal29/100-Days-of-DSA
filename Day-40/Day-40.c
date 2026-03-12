/*
Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, 
then repeatedly extract the maximum element and place it at the end of the array.
*/
#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;        // Initialize largest as root
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child
    int temp;

    // If left child is larger than root
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort Function
void heapSort(int arr[], int n)
{
    int i, temp;

    // Build Max Heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for(i = n-1; i > 0; i--)
    {
        // Move current root to end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array (Ascending): ");
    printArray(arr, n);

    return 0;
}
