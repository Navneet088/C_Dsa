#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Display the list forward
void displayForward(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Display the list backward
void displayBackward(struct Node* head) {
    if (head == NULL) return;
    while (head->next != NULL) {
        head = head->next;
    }
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Doubly Linked List (Forward): ");
    displayForward(head);

    printf("Doubly Linked List (Backward): ");
    displayBackward(head);

    deleteNode(&head, 20);

    printf("After Deletion (Forward): ");
    displayForward(head);

    return 0;
}
