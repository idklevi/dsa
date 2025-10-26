#include<stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void insert(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
    } else {
        queue[++rear] = val;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front++]);
        if(front > rear) {
            front = rear = -1; // Reset queue after last deletion
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n---Queue Menu---\n");
        printf("1. Insert an element \n2. Delete an element\n3. Display elements\n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}