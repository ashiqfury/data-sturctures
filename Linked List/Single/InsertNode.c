// Inserting a node at end of the linked list.

#include <stdio.h>
#include <stdlib.h>

// Node structure declaration.
struct node {
  int data;
  struct node *next;
};

// Declaration of variable and node pointers.
// int count = 0;
struct node *head;
// struct node *temp;
// struct node *newnode;

// Adding the nodes at beginning of the program.
void Insert(int x) {
    struct node *newnode;
    struct node *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL) {
        head = temp = newnode;
    }
    else {
        temp->next = newnode;
        temp = newnode;
    }
}

// Inserting the node at end of the linked list.
void insEnd(int x) {
    struct node *newnode;
    struct node *temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    temp = newnode;
}

// Inserting the node at beginning of the linked list.
void insBegin(int x) {
    struct node *newnode;
    struct node *temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;
}

// Inserting the node at specific index in the linked list.
void insPos(int x, int index) {
    struct node *temp = head;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    int i;
    for (i = 0; i < index-1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// Printing the nodes in the linked list.
void printing() {
    struct node *temp;
    int count = 0;
    temp = head;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nCount = %d", count);
    printf("\n\n");
}

// Main function that calling the insert functions.
int main() {
    head = NULL;
    
    printf("Creating the nodes : \n");
    Insert(5);
    Insert(7);
    Insert(10);
    Insert(3);
    printing();
    
    printf("Inserting a node at end of the linked list : \n");
    insEnd(20);
    printing();
    
    printf("Inserting a node at beginning of the linked list : \n");
    insBegin(4);
    printing();
    
    printf("Inserting a node at specific position in the linked list : \n");
    insPos(15,3); // Inserting at index 3
    printing();
    
    return 0;
}