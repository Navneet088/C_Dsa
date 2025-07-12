#include<stdio.h>
#include<stdlib.h>

// Stack implementation using arrays in C
// #define max 5
// int stack[max];
// int top = -1;
// int isFull() {
//     if (top == max - 1) {
//         return 1; // Stack is full
//     }
//     return 0; // Stack is not full
// }

// int isEmpty() {
//     if (top == -1) {
//         return 1; // Stack is empty
//     }
//     return 0; // Stack is not empty
// }
// void push(int value) {
//     if (isFull()) {
//         printf("Stack overflow\n");
//     } else {
//         top++;
//         stack[top] = value;
//         printf("%d pushed to stack\n", value);
//     }
// }

// void pop() {
//     if (isEmpty()) {
//         printf("Stack underflow\n");
//     } else {
//         printf("%d popped from stack\n", stack[top]);
//         top--;
//     }
// }
// void peek() {
//     if (isEmpty()) {
//         printf("Stack is empty\n");
//     } else {
//         printf("Top element is %d\n", stack[top]);
//     }
// }
// void display() {
//     if (isEmpty()) {
//         printf("Stack is empty\n");
//     } else {
//         printf("Stack elements are:\n");
//         for (int i = top; i >= 0; i--) {
//             printf("%d\n", stack[i]);
//         }
//     }
// }
// // Stack implementation using linked list in C
 typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

int isEmpty() {
    return top == NULL;
}
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value) {
    Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}




void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        Node* temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        Node* current = top;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}