///a menu driven program to program the following operations on a circular singly linked list.
//a)Insert at the beginning
//b)Insert at the end
//c)Delete from beginning
//d)Delete from the end
//e)Display the linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head = NULL;
void insert_head(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
    printf("Node %d inserted at beginning successfully!\n", val);
}
void insert_end(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node %d inserted at end successfully!\n", val);
}
void delete_head() {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    int deletedValue = head->data;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
    printf("Node %d deleted from beginning successfully!\n", deletedValue);
}
void delete_end() {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    int deletedValue;
    if (head->next == head) {
        deletedValue = head->data;
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        deletedValue = temp->data;
        prev->next = head;
        free(temp);
    }
    printf("Node %d deleted from end successfully!\n", deletedValue);
}
void print_list() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
int main() {
    int choice, val;
    while (1) {
        printf("---------------------------------------------------------------------------------------------\n");
        printf("\n--Circular Linked List Menu--\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Print the list\n");
        printf("6. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        printf("-------------------------------------------------------------------------------------------------\n");
        switch (choice) {
            case 1:
                printf("Enter Value To Insert: ");
                scanf("%d", &val);
                insert_head(val);
                break;
            case 2:
                printf("Enter Value To Insert: ");
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
                printf("Exiting..\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}