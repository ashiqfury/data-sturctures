// Trying own deletion operations in circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
};

struct node *tail;

void initialize(int num) {

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (tail == 0) {
        tail = newnode;
        newnode->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteBeginning() {

    if (tail == 0) {
        printf("List is empty\n");
    }
    else {

        struct node *temp = tail->next;
        tail->next = temp->next;
        temp->next = 0;
        free(temp);
    }
}

void deleteEnd() {

    if (tail == 0) {
        printf("List is empty\n");
    }
    else {
        struct node *temp = tail;
        
    }
}

void print() {

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = tail->next;

    while (temp->next != tail->next) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void main () {

    tail = 0;

    initialize(10);
    initialize(20);
    initialize(30);
    initialize(40);
    initialize(50);
    print();
    deleteBeginning();
    print();
}
