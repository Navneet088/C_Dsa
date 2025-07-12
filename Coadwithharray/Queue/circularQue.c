#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int size;
    int f;
    int r;
    int *arr;
} Queue;

int isFull(Queue *q) {
    return ((q->r + 1) % q->size == q->f);
}

int isEmpty(Queue *q) {
    return (q->f == -1);
}

void enqueue(int data, Queue *q) {
    if (isFull(q)) {
        printf("Queue is overflow\n");
    } else {
        if (q->f == -1) {
            q->f = 0; // First insertion
        }
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
        printf("Enqueued: %d\n", data);
    }
}

int dequeue(Queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Empty queue\n");
    } else {
        a = q->arr[q->f];
        if (q->f == q->r) {
            // Reset queue if last element is dequeued
            q->f = -1;
            q->r = -1;
        } else {
            q->f = (q->f + 1) % q->size;
        }
        printf("Dequeued: %d\n", a);
    }
    return a;
}

int main() {
    Queue q;
    q.size = 4;
    q.f = -1;
    q.r = -1;

    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(8, &q);
    enqueue(12, &q);
    enqueue(14, &q);
    enqueue(16, &q);

    dequeue(&q);
    enqueue(18, &q);

    free(q.arr);
    return 0;
}
