// Initialization of doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *temp;

void initialize(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;
    newnode->prev = 0;

    if (head == 0) {
        head = temp = newnode;
    }
    else {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}

// Not official, Own trying. But it works well.
void insertBeginning(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev = 0;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

// Not official, Own trying. But it works well.
void insertEnd(int num) {

    struct node *newnode, *temp;
    temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    while(temp->next != 0) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

}

// Not official, Own trying. But it works well.
void insertPosition(int num, int pos) {

    int i = 1;
    struct node *newnode, *temp;
    struct node *nextnode; // For solving the below problem.
    temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    while (i < pos-1) {
        temp = temp->next;
        i++;
    }

    // In doubly linked list, 4 links is needed.
    // But only 3 links is linked, remaining 1 link is not linked to any node.
    // It causes error in some cases.
    newnode->prev = temp; // Link 1
    newnode->next = temp->next; // Link 2
    // temp->next = newnode; // Link 3

    // By doing this, we can achieve our goal.
    nextnode = temp->next;
    temp->next = newnode; // Link 3
    nextnode->prev = newnode; // Link 4
}

void print() {

    struct node *temp;
    temp = head;

    while (temp != 0) {
        
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {

    head = 0;

    initialize(3);
    initialize(5);
    initialize(7);
    initialize(9);
    print();
    initialize(1);
    initialize(2);
    initialize(6);
    print();

    insertBeginning(19);
    insertBeginning(13);
    print();

    insertEnd(33);
    insertEnd(10);
    print();

    insertPosition(20,4);
    print();
}