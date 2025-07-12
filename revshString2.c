#include<stdio.h>
#include<string.h>
#define MAX 100
char Stack[MAX];
int top=-1;
 void push( char str[]){
    int l=strlen(str);
        if(l>MAX){
            printf("string is large to the stack");
        }
    for(int i=0; i<l; i++){
        if(top==MAX){
            printf(" Stack is full");
            return;
        }
        top++;
        Stack[top]=str[i];
    }

 }
 void display(){
    while(top!=-1){
        printf( "%c", Stack[top]);
        top--;
    }
 }
int main(){
    char str[]="Navneet";
    push(str);
    display();
    return 0;
}