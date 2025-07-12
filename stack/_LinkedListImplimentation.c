#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*link;//or next
    
};
struct node*top=0;
void push(int x){
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;

}
void display(){
    struct node*temp;
    temp=top;
    if (top==0)
    {
     printf("stack is empty");
    }
    else{
        while (temp!=0)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
             
        }
        
    }
    
}
void peek(){
    if(top==0){
        printf("Stack is empty");

    }
    else{
        printf("\npeeked element is= %d",top->data);
        top=top->link;
    }
}


int main (){
    push(1);
    push(10);  push(12);  push(13);  push(14);
    display();
peek();
peek();
peek();
peek();
    return 0;
}