#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head = NULL;
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end
void appendNode( int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function for linear search in linked list
int linearSearch(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1; // Not found
}

int main() {
    
    int i, num, key,size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n",size);
    for (i = 0; i <size; i++) {
        scanf("%d", &num);
        appendNode(num);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int result = linearSearch(head, key);
    if (result != -1)
        printf("Element %d found at position %d\n", key, result);
    else
        printf("Element %d not found in the list\n", key);

 

    return 0;
}