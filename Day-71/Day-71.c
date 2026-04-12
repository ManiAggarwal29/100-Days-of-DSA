/*
Implement a hash table using quadratic probing with formula:
*/
#include <stdio.h>

#define SIZE 10

int table[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (table[(index + i*i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            printf("Table is full\n");
            return;
        }
    }

    table[(index + i*i) % SIZE] = key;
}

// Display hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }
}

// Search element
void search(int key) {
    int index = hash(key);
    int i = 0;

    while (table[(index + i*i) % SIZE] != -1) {
        if (table[(index + i*i) % SIZE] == key) {
            printf("Element found at index %d\n", (index + i*i) % SIZE);
            return;
        }
        i++;
        if (i == SIZE)
            break;
    }

    printf("Element not found\n");
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    search(25);
    search(99);

    return 0;
}
