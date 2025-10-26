///a menu driven program to program the following operations on a doubly linked list.
//a)Insert at the beginning
//b)Insert at the end
//c)Insert in sorted order
//d)Count the no. of nodes
//e)Reverse the linked list
//f)Delete from beginning
//g)Delete from the end
//h)Display the linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* head = NULL;
void insert_head(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node %d inserted at head successfully!\n", val);
}
void insert_end(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        newNode->prev = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void delete_head() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}
void delete_end() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}
void print_list() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void reverse_list() {
    if (head == NULL) {
        printf("List is empty! Cannot reverse.\n");
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully!\n");
}
void count_node() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}
void insert_sorted(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    if (head == NULL || val <= head->data) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next != NULL && curr->next->data < val) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
}
int main() {
    int choice;
    int val;
    while (1) {
        printf("---------------Menu--------------------\n");
        printf("1. Insert at head\n");
        printf("2. Insert at end\n");
        printf("3. Delete at head\n");
        printf("4. Delete at end\n");
        printf("5. Print List\n");
        printf("6. Reverse List\n");
        printf("7. Count Nodes\n");
        printf("8. Insert in sorted order\n");
        printf("9. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        printf("--------------Answers------------------\n");
        switch (choice) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &val);
                insert_head(val);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                delete_head();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                print_list();
                break;
            case 6:
                reverse_list();
                break;
            case 7:
                count_node();
                break;
            case 8:
                printf("Enter a value: ");
                scanf("%d", &val);
                insert_sorted(val);
                break;
            case 9:
                 printf("Exiting..\n");
                return 0;
            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }
    return 0;
}
