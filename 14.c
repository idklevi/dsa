#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate value not allowed!\n");
    return root;
}
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
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
    int choice, data;
    struct Node* temp;
    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            if (search(root, data)) {
                printf("Value %d inserted successfully!\n", data);
            }
            break;
        case 2:
            if (root == NULL) {
                printf("Tree is empty! Nothing to delete.\n");
                break;
            }
            printf("Enter value to delete: ");
            scanf("%d", &data);
            if (search(root, data)) {
                root = deleteNode(root, data);
                printf("Value %d deleted successfully!\n", data);
            } else {
                printf("Value %d not found in the BST.\n", data);
            }
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &data);
            temp = search(root, data);
            if (temp)
                printf("Value %d found in the BST.\n", data);
            else
                printf("Value %d not found in the BST.\n", data);
            break;
        case 4:
            if (root == NULL) {
                printf("Tree is empty!\n");
                break;
            }
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}