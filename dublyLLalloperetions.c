#include <stdio.h>
#include <stdlib.h>

// Define Node with typedef
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Global head and tail pointers
Node* head = NULL;
Node* tail = NULL;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Add at beginning
void addAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Add at end
void addAtEnd(int data) {
    Node* newNode = createNode(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Add at specific position
void addAtPosition(int data, int position) {
    if (position <= 1) {
        addAtBeginning(data);
        return;
    }

    Node* temp = head;
    int i;
    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        addAtEnd(data);
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head == NULL)
        tail = NULL;
    else
        head->prev = NULL;

    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail == NULL)
        head = NULL;
    else
        tail->next = NULL;

    free(temp);
}

// Delete from specific position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    int i;
    for (i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp == tail) {
        deleteFromEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
//delete node 
void deleteNode(int val){
    Node*node=head;
     while (node != NULL && node->data != val) {
        node = node->next;
    }

if(node==NULL){
    return;

}
if(node->prev==NULL){
    head=node->next;

}
if(node->next==NULL){
    tail=node->prev;
    
}
if(node->next!=NULL){
    node->next->prev=node->prev;

    
}
if(node->prev!=NULL){
    node->prev->next=node->next;
    
}
free(node);

}

// Display list forward
void displayList() {
    Node* temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display list in reverse
void displayReverse() {
    Node* temp = tail;
    printf("Reverse List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    // int choice, data, position;

    // while (1) {
    //     printf("\n---- Doubly Linked List (Typedef Style) Menu ----\n");
    //     printf("1. Add at beginning\n");
    //     printf("2. Add at end\n");
    //     printf("3. Add at specific position\n");
    //     printf("4. Delete from beginning\n");
    //     printf("5. Delete from end\n");
    //     printf("6. Delete from specific position\n");
    //     printf("7. Display list\n");
    //     printf("8. Display reverse\n");
    //     printf("9. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1:
    //             printf("Enter data: ");
    //             scanf("%d", &data);
    //             addAtBeginning(data);
    //             break;
    //         case 2:
    //             printf("Enter data: ");
    //             scanf("%d", &data);
    //             addAtEnd(data);
    //             break;
    //         case 3:
    //             printf("Enter data: ");
    //             scanf("%d", &data);
    //             printf("Enter position: ");
    //             scanf("%d", &position);
    //             addAtPosition(data, position);
    //             break;
    //         case 4:
    //             deleteFromBeginning();
    //             break;
    //         case 5:
    //             deleteFromEnd();
    //             break;
    //         case 6:
    //             printf("Enter position to delete: ");
    //             scanf("%d", &position);
    //             deleteFromPosition(position);
    //             break;
    //         case 7:
    //             displayList();
    //             break;
    //         case 8:
    //             displayReverse();
    //             break;
    //         case 9:
    //             printf("Exiting program.\n");
    //             exit(0);
    //         default:
    //             printf("Invalid choice! Try again.\n");
    //     }
    // }
    addAtEnd(10);
    addAtEnd(15);
    addAtEnd(120);
    addAtEnd(112);
    addAtEnd(100);
    displayList();
    deleteNode(120);
  displayList();
    return 0;
}
