#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node* next;
}Node;
struct Node*top=NULL;


void push(){
    int data;
    printf("Enter Data: ");
    scanf("%d",&data);
    Node *newNode=(Node*)malloc(sizeof(Node));

    if (top==NULL)
    {newNode->data=data;
        newNode->next=NULL;
        top=newNode;
        
    }
    else
    {
        newNode->data=data;
        newNode->next=top;
        top=newNode;
    }
    
}
void pop(){
    if(top==NULL){
        printf("stack is empty");

    }else{
        Node *newNode=top;
        top=top->next;
        int x=newNode->data;
        free(newNode);
        printf("Deleted element: %d\n",x);
    }
}
void display(){
    Node *newNode=top;
    if(top==NULL){
        printf("stack is empty");

    }else{
        while(newNode!=NULL){
            printf("Element: %d\n",newNode->data);
            newNode=newNode->next;
        }
      
    }

}
void peek(){
    if(top==NULL){
        printf("stack is empty");

    }else{
        Node *newNode=top;
        top=top->next;
       printf("peeked element: %d\n",newNode->data);
    //    newNode=newNode->next;
    }

}
int main(){
    push();
    push();
    push();
   
    display();
   
    peek();
    peek();
    peek();
    
    return 0;
}
