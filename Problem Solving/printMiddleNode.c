// Printing the middle node of the given linked list.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *tail;

void insert(int num) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (head == 0) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
} 

void printMiddle(int mid) {

    int i = 1;
    struct node *temp = head;

    while (i < mid) {
        temp = temp->next;
        i++;
    }
    printf("Middle number = %d", temp->data);
}
 
int noOfNodes() {

    int count = 0;
    struct node *temp = head;

    while (temp != 0) {
        count++;
        temp = temp->next;
    }
    return count;
}

void main() {

    head = tail = 0;

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    if (noOfNodes() % 2 == 0) {
        printMiddle(noOfNodes() / 2);
    }
    else {
        printMiddle((noOfNodes() + 1) / 2);
    }
}