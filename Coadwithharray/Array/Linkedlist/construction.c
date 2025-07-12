#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct  Node* head;
    struct  Node*next;

    
   
};
void travsal(struct Node*ptr){
while (ptr!=NULL)
{
    printf("Element:%d\n",ptr->data);
    ptr=ptr->next;
}

}

int main(){
    struct  Node* head;
    struct  Node* second;
    struct  Node* third;
    struct  Node* four; 
    struct  Node* five;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node)); 
    head=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    four=(struct Node*)malloc(sizeof(struct Node));
    five=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=6;
    second->next=third;
    third->data=5;
    third->next=four;
    four->data=4;
    four ->next=five;
    five->data=3;
    five->next=NULL;
    travsal(head);

    return 0;
}