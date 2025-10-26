#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
void insert(int val){
    if ((rear+1)%MAX==front)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    queue[rear]=val;
}
void delete(){
    if (front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element is %d\n",queue[front]);
    if (front==rear)
    {
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}
void display(){
    if (front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i=front;
    while (1)
    {
        printf("%d ",queue[i]);
        if (i==rear)
        {
            break;
        }
        i=(i+1)%MAX;
    }
    printf("\n");
}
int main(){
    int choice,val;
    while (1)
    {
        printf("\n---Circular Queue Operations43---\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
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
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}