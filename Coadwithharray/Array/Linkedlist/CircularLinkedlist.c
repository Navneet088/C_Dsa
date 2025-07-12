// #include<stdio.h>
// #include<stdlib.h>
// struct Node
// {
//     int data;
//     struct  Node* head;
//     struct  Node*next;

    
   
// };
// // void travsal(struct Node*ptr){
// // while (ptr!=NULL)
// // {
// //     printf("Element:%d\n",ptr->data);
// //     ptr=ptr->next;
// // }

// // }
// void print (struct Node * head){
//     struct Node *ptr= head;
//     do{
//         printf("element is:%d\n",ptr->data);
//         ptr=ptr->next;
//     }

//     while(ptr!=head);
// }
// //circualar
// struct Node *addfirst(struct Node *head ,int data){
//     struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
//     ptr->data=data;
// if(head==NULL){
//     ptr->next=ptr;
//     return ptr;
// }
//     struct Node *p=head->next;
//     while (p->next!=head){
//         p=p->next;

//     }
// p->next=ptr;
// ptr->next=head;
// head=ptr;
//     return head;
// }
// int main(){
//     struct  Node* head;
//     struct  Node* second;
//     struct  Node* third;
//     struct  Node* four; 
//     struct  Node* five;

//     head=(struct Node*)malloc(sizeof(struct Node));
//     second=(struct Node*)malloc(sizeof(struct Node)); 
//     head=(struct Node*)malloc(sizeof(struct Node));
//     third=(struct Node*)malloc(sizeof(struct Node));
//     four=(struct Node*)malloc(sizeof(struct Node));
//     five=(struct Node*)malloc(sizeof(struct Node));
//     head->data=7;
//     head->next=second;
//     second->data=6;
//     second->next=third;
//     third->data=5;
//     third->next=four;
//     four->data=4;
//     four ->next=five;
//     five->data=3;
//     five->next=NULL;
//   print(head);
//   printf("\n");
//   head=addfirst(head,41);
//   print(head);
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next; // Removed the extra 'head' pointer
};

// Function to print a circular linked list
void print(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *ptr = head;
    do {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Function to add a new node at the beginning of a circular linked list
struct Node *addfirst(struct Node *head, int data) {
    // Allocate memory for the new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    // If the list is empty, create a self-referencing node
    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    // Find the last node in the circular linked list
    struct Node *p = head;
    while (p->next != head) {
        p = p->next;
    }

    // Insert the new node at the beginning
    p->next = ptr;  // Last node points to the new node
    ptr->next = head; // New node points to the old head
    head = ptr;      // Update the head to the new node

    return head;
}

// Function to create a circular linked list
struct Node *createCircularLinkedList() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *four = (struct Node *)malloc(sizeof(struct Node));
    struct Node *five = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 5;
    third->next = four;

    four->data = 4;
    four->next = five;

    five->data = 3;
    five->next = head; // Makes the list circular

    return head;
}

int main() {
    // Create circular linked list
    struct Node *head = createCircularLinkedList();

    printf("Original Circular Linked List:\n");
    print(head);

    // Add a new node at the beginning
    head = addfirst(head, 41);
    printf("\nAfter Adding 41 at the Beginning:\n");
    print(head);

    return 0;
}
