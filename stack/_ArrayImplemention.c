#include<stdio.h>
#include<stdlib.h>
#define N  5
int stack[N];
int top=-1;
void push(){
    int x;
    printf("ENTER A NUMER OR DATA: ");
    scanf("%d",&x);
    if(top==N-1){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        top--;
        
        
    }
}
void peek(){
    
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        top--;
        printf("%d",stack[top]);
        
    }
}
void display(){
    
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        for(int i=top; i>=0;i--){
        printf("%d",stack[top]);
        top--;
        }
        
    }
}


int main (){
push();
display();
    return 0;
}