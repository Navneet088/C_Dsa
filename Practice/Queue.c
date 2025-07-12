#include<stdio.h>
#include<stdlib.h>
// Queue implementation using arrays in C
#define MAX 5
int Queue[MAX];
int front =-1;
int rear=-1;

void enqueue(int val){
    if(rear==MAX-1){
        printf("que is full\n");
    }else{
        if(front==-1){
            front=0;

        }
        rear++;
        Queue[rear]=val;
        printf("%d is added to queue\n",val);
    }
}
void dequeue(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }else{
        printf("%d is removed from queue\n",Queue[front]);
        front++;
    }
}
void peek(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }else{
        printf("Front element is %d\n",Queue[front]);
    }
}
 void display(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }else{


        for(int i=front;i<=rear;i++){
            printf("%d ",Queue[i]);
        }
        printf("\n");
    }
}
// circular queue implementation using arrays in C
int isFull() {
    return (rear + 1) % MAX == front; // Check if the next position of rear is front
}

int isEmpty() {
    return front == -1; // Check if the queue is empty
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (isEmpty()) {
            front = 0; // Initialize front if queue was empty
        }
        rear = (rear + 1) % MAX; // Circular increment
        Queue[rear] = val;
        printf("%d is added to queue\n", val);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("%d is removed from queue\n", Queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % MAX; // Circular increment
        }
    }
}
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", Queue[front]);
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i = front;
        while (1) {
            printf("%d ", Queue[i]);
            if (i == rear) break; // Stop when we reach the rear
            i = (i + 1) % MAX; // Circular increment
        }
        printf("\n");
    }
}



// Queue implementation using linked list in C
typedef struct Node {
    int data;
    struct Node* next;
} Node; 
Node* f = NULL;
Node* r = NULL;  
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int value) {
    Node* newNode = createNode(value);
    if (r == NULL) {
        f = r = newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
    printf("%d is added to queue\n", value);
}   
void dequeue() {
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = f;
    printf("%d is removed from queue\n", f->data);
    f = f->next;
    if (f == NULL) {
        r = NULL; // If the queue becomes empty
    }
    free(temp);
}
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", f->data);
    }
}
void display() {
    if (f == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = f;
        printf("Queue elements are:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
// circular queue implementation using linked list in C
int isFull() {
    return (rear + 1) % MAX == front; // Check if the next position of rear is front
}
int isEmpty() {
    return front == -1; // Check if the queue is empty
}
void enqueue(int val) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (isEmpty()) {
            front = 0; // Initialize front if queue was empty
        }
        rear = (rear + 1) % MAX; // Circular increment
        Queue[rear] = val;
        printf("%d is added to queue\n", val);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("%d is removed from queue\n", Queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % MAX; // Circular increment
        }
    }
}
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", Queue[front]);
    }
}



int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    peek();
    dequeue();
    display();
    return 0;

}
   