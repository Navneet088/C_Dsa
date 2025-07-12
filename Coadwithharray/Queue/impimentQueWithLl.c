#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global front (f) and rear (r) pointers
Node *f = NULL;
Node *r = NULL;

// Insert a node at the end of the queue
void enQue(int data) {
    Node *n = (Node *)malloc(sizeof(Node)); // Correct memory allocation
    if (n == NULL) {
        printf("Queue is full!\n");
    } else {
        n->data = data;
        n->next = NULL;
        if (f == NULL) {
            f = r = n; // If the queue is empty, both f and r point to the new node
        } else {
            r->next = n; // Add new node to the end of the queue
            r = n;       // Move rear to the new node
        }
    }
}

// Remove a node from the front of the queue
void deQue() {
    if (f == NULL) {
        printf("Queue is empty!\n");
    } else {
        Node *ptr = f;
        int val = ptr->data;
        f = f->next; // Move front to the next node
        if (f == NULL) {
            r = NULL; // If the queue becomes empty, update rear to NULL
        }
        printf("Deleted node: %d\n", val);
        free(ptr); // Free the memory of the deleted node
    }
}

// Display the queue
void display() {
    Node *ptr = f;
    if (ptr == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    // Add elements to the queue
    enQue(1);
    enQue(2);
    enQue(3);
    enQue(4);

    // Display the queue
    display();

    // Delete elements from the queue
    deQue();
    deQue();

    // Display the updated queue
    display();

    return 0;
}
