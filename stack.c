#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Stack[MAX];
int top = -1;

// Push
void push() {
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        Stack[top] = data;
    }
}

// Pop
void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped: %d\n", Stack[top]);
        top--;
    }
}

// Display
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", Stack[i]);
        }
        printf("\n");
    }
}

// Peek
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", Stack[top]);
    }
}


int main() {
    int choice, flag = 1;

    while (flag) {
        printf("1- Insertion\t2- Deletion\t3- Display\t4- Peek\t5- Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: 
                printf("Exiting...\n");
                flag = 0; 
                break;
            default: 
                printf("Invalid choice\n");
        }
    }

    return 0;
}
// #include<stdio.h>
// #include<stdlib.h>

// #define MAX 5
// int Stack[MAX];
// int top=-1;
// //push
// void push(){
//     int data;
//     printf("enter Data");
//     scanf("%d",&data);
//     if(top==MAX-1){
//         printf("stack is full");
//     }
//     else{
//         top++;
//         Stack[top]=data;

//     }
// }
// //pop
// void pop(){
   
//     if(top!=-1){
//         printf("stack is empty");
//     }else{
//         top--;

//     }
// }
// //disply
//  void display(){
//     if(top==-1){
//         printf("all data is print");

//     }else{
//         printf("%d",Stack[top]);
//         top--;
//     }
//  }
//  //peek
//  void peek(){
//     if(top==-1){
//         printf("stack is empty");

//     }else{
//         printf("%d",Stack[top]);
//         top--;
//     }
//  }
 
// int main(){

// int choice,data,flag=1;

// while (flag){{
    
//     printf("1-Insertion\t 2- Deletion\t3-disply\t4-peek\t 5-exit\n");
//     printf("enter a Choice\n");
//     scanf("%d",&choice);
// }
// switch (choice){
//     case 1: push(data);
//     break;
//     case 2: pop();
//     break;
//     case 3: display();
//     break;
//     case 4: peek();
//     break;
//     case 5:
//     printf("exit");
//     return 0;
//     default : printf("Invalid choice ");
    
// }   
// }
// return 0;
// }