#include <stdio.h>
#include <stdlib.h>

// Define node using typedef
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
struct     Node* root = NULL;
// Create a new node
Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a node
Node* insert(Node* root, int value) {
    if (root == NULL) 
    return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Find minimum value node
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int value) {
   
    if (root == NULL) 
     return root;

 //search element on bst 
    if (value < root->data) 
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
        //deletion strategy when the node is found
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //root node is delet
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search a node
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find Maximum
Node* findMax(Node* root) { 
    while (root->right != NULL)
        root = root->right;
    return root;
}
int main() {
    Node* root = NULL;

   root= insert(root, 50);

    root= insert(root, 30);
    root= insert(root, 70);
    root= insert(root, 20);
    root= insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root); printf("\n");

    printf("Preorder: ");
    preorder(root); printf("\n");

    printf("Postorder: ");
    postorder(root); printf("\n");

    deleteNode(root,50);
    printf("Preorder: ");
    preorder(root); printf("\n");
    printf("Inorder: ");
    inorder(root); printf("\n");


    findMin(root);
   printf("Minimum value in BST: %d\n", findMin(root)->data);
    

    return 0;
}
