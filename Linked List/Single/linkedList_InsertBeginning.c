// Inserting node at beginning of the linked list.
// Code from : FreeCodeCamp - mycodeschools.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head; // Global pointer "head".

// For creating and inserting a new node at beginning of the linked list.
void InsertBeginning(int x) {
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;		// Alternative syntax : newnode->next = NULL; if(head != NULL) temp->next = head;
    head = newnode;				
}

void Print() {
    struct node *traver = head;
    printf("List is : ");
    while(traver != NULL) {
		printf("%d ",traver->data);
        traver = traver->next;
    }
    printf("\n");
}

int main() {
    
    int num, input, i;
    head = NULL;
    printf("Enter how many numbers? ");
    scanf("%d",&num);
    for(i=0; i<num; i++) {
        printf("\nEnter the number : ");
        scanf("%d",&input);
        InsertBeginning(input);
        Print();
    }
    printf("\nProgram ended..");
    
    
    return 0;
}