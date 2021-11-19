// Inserting a node in doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;

void initialize(int num) {

    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;
    newnode->prev = 0;

    if (head == 0) {
        head = tail = newnode;
    }
    else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertBegin(int num) {

    struct node *newnode;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev = 0;

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

}

void insertEnd(int num) {

    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;

}

void insertPosition(int num, int pos) {

    int i = 1;
    struct node *newnode, *temp;
    temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    while(i < pos-1) {
        temp = temp->next;
        i++;
    }

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;

}

void deleteBegin() {

    struct node *temp;
    temp = head;

    head = head->next;
    head->prev = 0;

    temp->next = temp->prev = 0; // Not necessary
    free(temp);
}

void deleteEnd() {

    struct node *temp;
    temp = tail;

    tail = tail->prev;
    tail->next = 0;

    temp->next = temp->prev = 0; // Not necessary
    free(temp);
}

int nodeCount() {

    int count = 0;
    struct node *temp;
    temp = head;

    while (temp != 0) {
        temp = temp->next;
        count++;
    }

    return count;
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

int main() {

    head = tail = 0;

    initialize(10);
    initialize(20);
    initialize(30);
    print();

    initialize(10);
    initialize(20);
    initialize(30);
    print();

    insertBegin(22);
    insertBegin(12);
    print();

    insertEnd(4); 
    insertEnd(44);
    print(); 

    insertPosition(77,2);
    print();

    printf("Count = %d\n", nodeCount());

    deleteBegin();
    deleteBegin();
    deleteBegin();
    print();

    deleteEnd();
    deleteEnd();
    deleteEnd();
    deleteEnd();
    print();

    return 0;
}
