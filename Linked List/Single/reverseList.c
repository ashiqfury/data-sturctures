// Reverse a linked list.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

void insert(int x) {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    temp = head;

    if (head == 0) {
        head = newnode;
    }
    else {
        while(temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void reverse() {
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode != 0) {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

void print() {
    struct node *temp;
    temp = head;
    while(temp != 0) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {

    head = 0;

    printf("Inserting data and printing the inserted data : \n");
    insert(3);
    insert(5);
    insert(2);
    insert(8);
    insert(6);
    print();

    printf("Reverse the list and the print the data : \n");
    reverse();
    print();

    printf("Inserting a new data and print the data : \n");
    insert(9);
    print();

    getch();
    
}
