#include<stdio.h>
#include<string.h>
#define MAX 10
char Stack[MAX];
int top=-1;
//push
void push(char data){
    

    if(top==MAX){
        printf("stack is full");
    }
    else{
        top++;
        Stack[top]=data;

    }
}
//pop
void pop(){
   
    if(top!=-1){
        printf("stack is empty");
    }else{
        top--;

    }
}
//disply
 void display(){
    if(top==-1){
        printf("all data is print");

    }else{
        printf("%c ",Stack[top]);
        top--;
    }
}
int main(){
    push('n');
    push('a');
    push('v');
    push('n');
    push('e');
    push('e');
    push('t');
    push('a');
    push('v');
    push('n');
    push('e');
    push('e');
    push('t');



    display();
    display();
    display();
    display();
    display();
    display();
    display();
    display();
    display();
    display();
    display();
    



    return 0;
}