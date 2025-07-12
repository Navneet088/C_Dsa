#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;

}Node;
Node*creatNode(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void displayForward(Node *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node*addFirst(Node*head,int data){
    Node*newNode=creatNode(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;

}
int main(){
    Node*head=5;
    addFirst(&head,10);
    displayForward(head);
    return 0;
}