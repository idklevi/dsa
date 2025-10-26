#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* createTree() {
    int data, choice;
    printf("\nEnter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    struct Node* newNode = createNode(data);
    printf("Does node %d have a left child? (1 for Yes / 0 for No): ", data);
    scanf("%d", &choice);
    if (choice == 1)
        newNode->left = createTree();
    printf("Does node %d have a right child? (1 for Yes / 0 for No): ", data);
    scanf("%d", &choice);
    if (choice == 1)
        newNode->right = createTree();

    return newNode;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct Node* root = NULL;
    printf("Create the Binary Tree:\n");
    root = createTree();
    printf("\nInorder Traversal: ");
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        inorder(root);
    }
    printf("\nPreorder Traversal: ");
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        preorder(root);
    }
    printf("\nPostorder Traversal: ");
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        postorder(root);
    }
    printf("\n");
    return 0;
}