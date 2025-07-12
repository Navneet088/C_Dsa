#include <stdio.h>

#define MAX 10

int queue[MAX];
int size = 0;

// Ascending order enqueue
void enqueueAscending(int data) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    int i = size - 1;
    while (i >= 0 && queue[i] > data) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = data;
    size++;
}

// Descending order enqueue
void enqueueDescending(int data) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    int i = size - 1;
    while (i >= 0 && queue[i] < data) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = data;
    size++;
}

// Dequeue
void dequeue() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued: %d\n", queue[0]);
    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

// Display queue
void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main
int main() {
    printf("Inserting in Ascending Order:\n");
    enqueueAscending(30);
    enqueueAscending(10);
    enqueueAscending(20);
    enqueueAscending(40);
    display();  // Expected: 10 20 30 40

    dequeue();
    dequeue();
    display();  // Expected: 20 30 40

    printf("\nInserting in Descending Order:\n");
    size = 0;  // Reset queue
    enqueueDescending(30);
    enqueueDescending(10);
    enqueueDescending(20);
    enqueueDescending(40);
    display();  // Expected: 40 30 20 10

    dequeue();
    display();  // Expected: 30 20 10

    return 0;
}
