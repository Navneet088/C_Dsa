#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue Underflow\n");
    else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void peek() {
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Front Element: %d\n", queue[front]);
}

void display() {
    if (front == -1)
        printf("Queue is Empty\n");
    else {
        printf("Queue Elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
