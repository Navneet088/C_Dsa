#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack variables
#define MAX 100  
char stack[MAX];
int top = -1;

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to return top element of stack
char stackTop() {
    return isEmpty() ? '\0' : stack[top];
}

// Function to push element onto stack
void push(char val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

// Function to pop element from stack
char pop() {
    return isEmpty() ? '\0' : stack[top--];
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Function to check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix to postfix
char* infixToPostfix(char* infix) {
    int len = strlen(infix);
    char *postfix = (char*) malloc((len + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        // If operand, add to postfix
        if (!isOperator(infix[i])) {
            postfix[j++] = infix[i++];
        }
        // If operator, manage precedence
        else {
            while (!isEmpty() && precedence(infix[i]) <= precedence(stackTop())) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    // Pop remaining operators from stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

// Main function
int main() {
    char infix[] = "a+b*c-d";
    char* postfix = infixToPostfix(infix);
    printf("Postfix: %s\n", postfix);
    free(postfix); // Free allocated memory
    return 0;
}
