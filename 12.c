    #include <stdio.h>
    #include <stdlib.h>
    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* rear = NULL;
    void enqueue(int value) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = value;
        if (rear == NULL) {
            newNode->next = newNode;
            rear = newNode;
            printf("%d enqueued to the queue (first element).\n", value);
        } else {
            newNode->next = rear->next; 
            rear->next = newNode;        
            rear = newNode;             
            printf("%d enqueued to the queue.\n", value);
        }
    }
    void dequeue() {
        if (rear == NULL) {
            printf("Queue is empty. Cannot dequeue.\n");
            return;
        }
        struct Node* front = rear->next;

        if (rear == front) {
            printf("%d dequeued from the queue (queue now empty).\n", front->data);
            free(front);
            rear = NULL;
        } else {
            
            rear->next = front->next;  
            printf("%d dequeued from the queue.\n", front->data);
            free(front);
        }
    }
    void display() {
        if (rear == NULL) {
            printf("Queue is empty.\n");
            return;
        }
        struct Node* temp = rear->next;  
        printf("Queue elements (front to rear): ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != rear->next);  
        printf("\n");
    }
    int getSize() {
        if (rear == NULL) return 0;
        
        int count = 0;
        struct Node* temp = rear->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != rear->next);
        return count;
    }
    int peek() {
        if (rear == NULL) {
            printf("Queue is empty. No front element.\n");
            return -1;
        }
        return rear->next->data;
    }
    int main() {
        int choice, value;
        while (1) {
            printf("\n--- Queue using Circular Singly Linked List ---\n");
            printf("1. Enqueue (Add to rear)\n");
            printf("2. Dequeue (Remove from front)\n");
            printf("3. Display queue\n");
            printf("4. Peek front element\n");
            printf("5. Get queue size\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if (rear != NULL) {
                    printf("Front element: %d\n", peek());
                }
                break;
            case 5:
                printf("Queue size: %d\n", getSize());
                break;
            case 6:
                printf("Exiting program...\n");
                while (rear != NULL) {
                    dequeue();
                }
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-6.\n");
            }
        }
        return 0;
    }