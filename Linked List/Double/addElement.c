// Implementing elements to the linked list.


#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;

void insert(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;
    newnode->prev = 0;

    if (head == 0) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void print() {
    
    struct node *temp;
    temp = head;

    while (temp != 0) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {

    head = tail = 0;

    insert(55);
    print();
}