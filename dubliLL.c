#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

// Add at beginning
void addfirst() {
    int x;
    printf("Enter Data: ");
    scanf("%d", &x);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }
}

// Add at end
void addlast() {
    int x;
    printf("Enter Data: ");
    scanf("%d", &x);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    }
    tail = newNode;

    if (head == NULL) {
        head = newNode;
    }
}

// Add at specific position
void add_Specific() {
    int x, pos;
    printf("Enter Data and Position: ");
    scanf("%d %d", &x, &pos);

    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;

    if (pos == 0) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        if (tail == NULL) tail = newNode;
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
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }
}

// Display list forward
void display() {
    Node *temp = head;
    printf("Linked list (forward):\n");
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
}

// Optional: Display list backward using tail
void display_reverse() {
    Node *temp = tail;
    printf("Linked list (reverse):\n");
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->prev;
    }
}

int main() {
    int x;
    char ch;

    // Initial data input loop
    do {
        printf("Enter Data: ");
        scanf("%d", &x);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == NULL) {
            head = newNode;
        }

        printf("Enter Y to continue or any other key to exit: ");
        scanf(" %c", &ch); // space before %c to consume leftover newline

    } while (ch == 'Y' || ch == 'y');

    // Demonstrate operations
    printf("\nAdding elements at the beginning:\n");
    addfirst();
    addfirst();

    printf("\nAdding element at a specific position:\n");
    add_Specific();

    printf("\nFinal linked list:\n");
    display();

    // Uncomment to test reverse traversal
    // display_reverse();

    return 0;
}
