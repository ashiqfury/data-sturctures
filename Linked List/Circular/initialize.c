// Initialize and printing the circular linked list.

#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node *next;
};

struct node *head, *temp;

void initialize(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (head == 0) {
       head = temp = newnode;
    }
    else {
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
}

void print() {

    struct node *temp;
    temp = head;

    while (temp->next != head) { // We cannot write while(temp != head). Because temp == head.
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

int main() {

    head = 0;

    initialize(10);
    initialize(20);
    initialize(30);
    initialize(40);
    initialize(50);
    print();

    return 0;
}