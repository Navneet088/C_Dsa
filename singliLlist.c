// #include<stdio.h>
// #include<stdlib.h>
// typedef struct Node
// {int data;
//     struct Node *next;

   
// }Node;
// struct  Node *head=NULL;
// struct  Node *tail=NULL;

// void addfirst(){
//     int x;
//     Node *new=(Node*)malloc(sizeof(Node));
//     if(new==NULL){
//         printf("Memory allocation failed\n");
//         return;
//     }
//     printf("Enter Data: ");
//     scanf("%d",&x);
//     new->data=x;
//     new->next=head;
//     head=new;
    
// }
// void addlast(){
//     int x;
//     Node *new=(Node*)malloc(sizeof(Node));
//     if(new==NULL){
//         printf("Memory allocation failed\n");
//         return;
//     }
//     printf("Enter Data: ");
//     scanf("%d",&x);
//     new->data=x;
//     tail->next=NULL;
//     if (head == NULL) {
//         head = new;
//         tail = new;
//     } else {
//         tail->next = new;
//         tail = new;
//     }
    
// }
// void add_Specific(){
//     int x ,pos;
//     Node *new=(Node*)malloc(sizeof(Node));
//     printf("Enter Data and position: ");
//     scanf("%d%d",&x,&pos);
//     new->data=x;
//     Node*temp=head;
//     for(int i=0; i<pos-1; i++){
//         temp=temp->next;
//     }
//     new->next=temp->next;
//     temp->next=new;
  
    
// }
// void display(){
//     Node *temp=head;
//     while (temp!=NULL)
// {
//     printf("Element:%d\n",head->data);
//     head=head->next;
// }
// }

// int main(){
// int x;
// char ch;
// do
// {
//     Node *new=(Node*)malloc(sizeof(Node));
//     printf("Enter Data: ");
//     scanf("%d",&x);
//     new->data=x;
//     new->next=tail;
//     if(head==NULL){
//         head=new;
//         tail=new;
//     }
//     else{
//         tail->next=new;
//         tail=new;
//     }
//     printf("Enter Y for Continue and E for exit");
//     scanf("%c",&ch);    
// } while (ch=='y');

// addfirst();
// addfirst();
// addfirst();
// add_Specific();
// display();


//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void addfirst() {
    int x;
    Node *newNode = (Node *)malloc(sizeof(Node));
    // if (newNode == NULL) {
    //     printf("Memory allocation failed\n");
    //     return;
    // }
    printf("Enter Data: ");
    scanf("%d", &x);
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}

void addlast() {
    int x;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter Data: ");
    scanf("%d", &x);
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void add_Specific() {
    int x, pos;
    printf("Enter Data and Position: ");
    scanf("%d %d", &x, &pos);

    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
        return;
    }

    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == NULL) {
        tail = newNode;
    }
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int x;
    char ch;

    do {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            break;
        }
        printf("Enter Data: ");
        scanf("%d", &x);
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Enter Y to continue or any other key to exit: ");
        scanf(" %c", &ch); // Added space before %c to consume newline

    } while (ch == 'Y' || ch == 'y');

    // You can test the functions like this:
    printf("\nAdding elements at the beginning:\n");
    addfirst();
    addfirst();

    printf("\nAdding element at a specific position:\n");
    add_Specific();

    printf("\nFinal linked list:\n");
    display();

    return 0;
}
