///a menu driven program to program the following operations on a singly linked list.
//a)Insert at the beginning
//b)Insert at the end
//c)Insert in sorted order
//d)Count the no. of nodes
//e)Reverse the linked list
//f)Delete from beginning
//g)Delete from the end
//h)Display the linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node*head= NULL;

void insert_head(int val){
	Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->data=val;
        newNode->next=head;
        head=newNode;
}

void insert_end(int val){
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
    	head=newNode;
    	return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
    	temp=temp->next;
    }
    temp->next=newNode;  // This line was missing!
}

void insert_sorted(int val){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=val;
	newNode->next=NULL;
	
	if(head==NULL || head->data>=val){
		newNode->next=head;
		head=newNode;
		return;
	}
	Node* temp=head;
    	while(temp->next!=NULL && temp->next->data<val){
    		temp=temp->next;	
	}
	newNode->next=temp->next;
	temp->next=newNode;
}

int count_nodes(){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void reverse_list(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    head=prev;
}

void delete_head(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp =head;
    head= head->next;
    free(temp);
}

void delete_end(){
    if(head==NULL){
        printf("Empty list\n");
        return;
    }
    if(head->next==NULL){
    	free(head);
    	head=NULL;
    	return;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL){
    	prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void print_list(){
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
	int choice,val;
	while(1){
		printf("\n--Singly Linked List Menu--\n");
		printf("1. Insert at beginning\n");
	    	printf("2. Insert at end\n");
	    	printf("3. Inserted in sorted order\n");
	    	printf("4. Count the node\n");
	    	printf("5. Reverse the list\n");
	    	printf("6. Delete from beginning\n");
	    	printf("7. Delete from end\n");  
	    	printf("8. Print the list\n");  
	    	printf("9. EXIT\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		printf("--------------------------------------------------------------\n");
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
				printf("Enter Value To Insert: ");
				scanf("%d", &val);
				insert_sorted(val);
				break;
			case 4:
				printf("No. of nodes= %d\n",count_nodes());
				break;
			case 5:
				reverse_list();
				printf("List reversed successfully!\n");
				break;
			case 6:
				delete_head();
				break;    
			case 7:
				delete_end();
				break;
			case 8:
				print_list();
				break;
			case 9:
                printf("Exiting...\n");
                return 0;
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}