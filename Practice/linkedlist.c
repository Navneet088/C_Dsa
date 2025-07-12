#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head = NULL;
Node* tail = NULL;
 Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
 }
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
   
}   
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    
}       
void insertAtPosition(int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0) {
        insertAtBeginning(value);
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position %d is out of bounds\n", position);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == NULL) {
        tail = newNode; // Update tail if inserted at the end
    }
    printf("%d is added at position %d\n", value, position);
}
void deletefromBeginning() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL; // If the list becomes empty
    }
    printf("%d is removed from the beginning of the linked list\n", temp->data);
    free(temp);
}

void deletefromEnd() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL; // If there's only one node
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    }
    printf("%d is removed from the end of the linked list\n", tail->data);
    free(tail);
}
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (position == 0) {
        deletefromBeginning();
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position %d is out of bounds\n", position);
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    if (temp == tail) {
        tail = current; // Update tail if deleted from the end
    }
    printf("%d is removed from position %d\n", temp->data, position);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }   
    Node* current = head;
    printf("Linked list elements are: ");
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("\n");
}
// circular linked list implementation in C
void insertAtBeginningCircular(int value) {     
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head; // Point tail to head to make it circular
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head; // Update tail's next to point to new head
    }
}
void insertAtEndCircular(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head; // Point tail to head to make it circular
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // Point tail to head to maintain circularity
    }
}
void displayCircular() {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    Node* current = head;
    printf("Circular linked list elements are: ");
    do {
        printf("%d-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to head)\n");
}
void deleteFromBeginningCircular() {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL; // If there's only one node
    } else {
        head = head->next;
        tail->next = head; // Update tail's next to new head
    }
    printf("%d is removed from the beginning of the circular linked list\n", temp->data);
    free(temp);
}
void deleteFromEndCircular() {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL; // If there's only one node
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head; // Update temp's next to point to head
        tail = temp; // Update tail
    }
    printf("%d is removed from the end of the circular linked list\n", tail->data);
    free(tail);
}


int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(5);
    insertAtEnd(30);
    insertAtEnd(40);
     insertAtPosition(15, 4);
    display();
    deleteAtPosition(4);
    display();
    deleteAtPosition(4);
    display();
    deletefromBeginning();
    display();  

    return 0;
}