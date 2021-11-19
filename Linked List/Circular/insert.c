// Insertion operations in  Circular Linked List.
// Insert at beginning, end and given position.


#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
};

struct node *tail;

void initialize(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
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

void insertBeginning(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (tail == 0) {
        tail = newnode;
        newnode->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertEnd(int num) {

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = 0;
    newnode->data = num;


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

void insertPosition(int num, int pos, int length) {

    int i = 1;

    if (pos == 1) {
        insertBeginning(num);
    }
    else if (pos == length) {
        insertEnd(num);
    }
    else {
        struct node *temp = tail->next, *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = 0;
        
        while (i < pos-1) {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void print() {

    if (tail == 0) {
        printf("List is empty\n");
    }
    else {

        struct node *temp = tail->next;

        while (temp->next != tail->next) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int noOfNodes() {

    int count = 0;

    if (tail == 0) {
        printf("List is empty");
    }
    else {

        struct node *temp = tail->next;

        while (temp->next != tail->next) {
            temp = temp->next;
            count++;
        }
        count++;
    }

    return count;
}

int main() {

    tail = 0;
    int length = noOfNodes();

    // initialize(10);
    // initialize(20);
    // initialize(30);
    // initialize(50);
    // print();
    // printf("Insert at beginning\n");
    // insertBeginning(33);
    // print();
    // printf("Insert at end\n");
    // insertEnd(43);
    // print();
    printf("Insert at position\n");
    insertPosition(12,1, length);
    print();
    printf("No of nodes in the list = %d\n", noOfNodes());
    return 0;
}