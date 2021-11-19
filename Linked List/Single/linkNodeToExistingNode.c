// Linking new node to the existing node.
// Jenny lectures.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;
struct node *temp;
int count = 0;
void insert(int x) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    
    if (head == NULL) {
        head = temp = newnode;        
    }
    else {
        temp->next = newnode;
        temp = newnode;
    }
}

void printing() {
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
}
int main() {
    
    head = NULL;
    insert(7);
    insert(6);
    insert(2);
    insert(8);
    insert(1);
    printing();
    printf("\nNumber of nodes in the linkedlist : %d", count);
    return 0;
}