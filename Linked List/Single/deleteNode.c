// Deletion operations in linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head, *temp;

void insert(int x) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    
    if (head == NULL) {
        head = temp = newnode;
    }
    else {
        temp->next = newnode;
        temp = newnode;
    }
    
}

void deleteBeg() {
    temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    struct node *prevnode;
    temp = head;
    
    while(temp->next != NULL) {
        prevnode = temp;
        temp = temp->next;
    }
    
    if (temp == head) {
        head = NULL;
    }
    else {
        prevnode->next = NULL;
    }
    free(temp);
}

void deletePos(int pos) {
    int i;
    struct node *nextnode;
    struct node *temp;
    temp = head;
    
    for(i=1; i<pos-1; i++) {
        temp = temp->next;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

void display() {
    struct node *temp;
    temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    printf(" Count = %d", count);
    printf("\n");
}

int main() {
    head = NULL;
    
    // Inserting the nodes.
    printf("\nInserting nodes : \n");
    insert(3);
    insert(5);
    display();
    insert(7);
    insert(1);
    insert(9);
    insert(2);
    insert(8);
    display();
    
    // Deleteing the nodes.
    printf("\nDelete a node at beginning : \n");
    deleteBeg();
    display();
    
    printf("\nDelete a node at ending : \n");
    deleteEnd();
    display();
    
    printf("\nDelete a node at given position : \n");
    deletePos(3);
    display();

    return 0;
}