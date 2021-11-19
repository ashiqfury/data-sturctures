#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = 0, *tail = 0;

void initialize(int num) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    
    if (head == 0) {
        head = tail = newnode;
        tail->next = head;
    }
    else {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void insertBegin(int num) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    if (head == 0) {
        head = tail = newnode;
        tail->next = head;
    }
    else {
        tail->next = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertEnd(int num) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    
    if (head == 0) {
        head = tail = newnode;
        tail->next = head;
    }
    else {
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertPosition(int num, int pos) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = num;
    int i = 1;

    if (pos == 1){
        insertBegin(num);
    }
    else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteBegin() {
    struct node *temp = head;

    if (head == 0) {
        printf("Underflow");
    }
    else if (head->next == head) {
        head = tail = 0;
        free(temp);
    }
    else {
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp = head, *prevnode;

    if (head == 0) {
        printf("Underflow");
    }
    else if (head->next = head) {
        head = tail = 0;
        free(temp);
    }
    else {
        while(temp->next != head) {
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = head;
        tail = prevnode;
        free(temp);
    }
}

void deletePosition(int pos) {
    struct node *temp = head, *nextnode;
    int i = 1;

    while (i < pos) {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    nextnode = nextnode->next;
    free(nextnode);
}

void print() {
    struct node *temp = head;

    while(temp != tail) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main() {

    initialize(2);
    initialize(3);
    initialize(4);
    initialize(5);
    insertBegin(10);
    insertEnd(20);
    insertPosition(30, 3);

    deleteBegin();
    // deleteEnd(); // Error
    // deletePosition(4); // Error

    print();

    return 0;
}