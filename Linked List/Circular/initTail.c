
#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
};

struct node *tail;

void initialize (int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (tail == 0) {
        tail = newnode;
        tail->next = newnode;
        printf("%d\n", tail->data);
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
        printf("%d\n", tail->data);
    }
}

void print() {

    struct node *temp;
    temp = tail->next;

    while (temp->next != tail->next) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}

void printDoWhile() {

    struct node *temp;
    temp = tail->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;

    } while (temp->next != tail->next);
    printf("%d \n", temp->data); // This statement is needed for both while and do while loops.
    
}

int main() {

    tail = 0;

    initialize(10);
    initialize(20);
    initialize(30);
    initialize(140);
    initialize(40);
    initialize(50);

    printf("\nPrinting using while loop : \n");
    print();
    printf("\nPrinting using do while loop : \n");
    printDoWhile();

    return 0;
}