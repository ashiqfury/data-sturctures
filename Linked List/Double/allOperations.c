// All operations of doubly linked list.

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
    newnode->prev = 0;
    newnode->next = 0;

    if (head == 0) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertBeginning(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev = 0;
    newnode->next = 0;

    if (head == 0) {
        head = tail = newnode;
    }
    else {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertEnd(int num) {

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (head == 0) {
        head = tail = 0;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
} 

void insertPosition(int num, int pos) {

    int i = 1;
    struct node *newnode, *temp;
    temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;
    newnode->prev = 0;

    // if (pos == 1) {
    //     insertBeginning(num);
    // }
    // else if (pos == noOfNodes()) {
    //     insertEnd(num);
    // }
    // else {

        while (i < pos-1) {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode; // Alter : temp->next = newnode;
        temp->next = newnode;   // Alter : newnode->next->prev = newnode;

    // }
}

void deleteBeginning() {

    struct node *temp;

    if (head == 0) {
        printf("List is empty\n");
    }
    else {
        temp = head;
        head = head->next;
        head->prev = 0;
        temp->prev = 0;
        temp->next = 0;
        free(temp);
    
    }
}

void deleteEnd() {

    struct node *temp;

    if (head == 0) {
        printf("List is empty\n");
    }
    else {
        temp = tail;
        tail = tail->prev;
        tail->next = 0;
        temp->prev = 0;
        temp->next = 0;
        free(temp);
    }
}

void deletePosition(int pos) {

    int i = 1;
    struct node *temp;
    temp = head;

    while (i < pos) {
        temp = temp->next;
        i++;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = 0;
    temp->next = 0;
    free(temp);
}

void reverse() {

    struct node *temp, *nextnode;
    temp = head;

    while (temp != 0) {
        nextnode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextnode;
        temp = nextnode;
    }

    // Swapping *head and *tail pointers.
    temp = head;
    head = tail;
    tail = temp;

}

void reversePrint() {

    struct node *temp;
    temp = tail;

    while (temp != 0) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
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

int noOfNodes() {

    int count = 0;
    struct node *temp;
    temp = head;

    while (temp != 0) {
        count++;
        temp = temp->next;
    }

    return count;
}

void menu() {

    int subchoice = -1;
    int choice = -1;
    int size = 0;
    int num = 0;
    int pos = 0;
    int i = 0;

    while (choice != 0) {

        printf("\n\n************************************************************\n"); // For decorative purpose only.

        // List of menu will appear. User can choose any function they want.
        printf("1. Initialize\n2. Insert Operations\n3. Delete Operations\n4. Reverse the list\n5. Print in reverse order\n6. Print the list\n7. Number of Nodes\n0. Exit\n");

        printf("************************************************************\n\n"); // For decorative purpose only.
        scanf("%d", &choice);

        if (choice == 1) { 
            printf("\nHow many number you want to initialize : \n");
            scanf("%d", &size); // Getting numeber of inputs to insert.

            if (size < 1) {
                printf("\nInvalid size\n");
            }
            else {
                printf("Enter your numbers one by one : \n");
                for(i = 0; i < size; i++) { // Loop execute till the size value of meeted.
                    scanf("%d", &num); // Getting the value of data part of the node.
                    initialize(num); // Passing the data to initialize() function.
                }
            }
        }

        if (choice == 2) {

            printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at given position\n0. Exit\n");
            scanf("%d\n", &subchoice);

            if (subchoice == 1) {

                printf("\nEnter the number you want to insert at beginning : \n");
                scanf("%d", &num); // Getting the value of data part of the node.
                insertBeginning(num); // Passing the data to insertBeginning() function.

            } // End of insert begininng condition.

            // Insert end function.
            if (subchoice == 2) {
                
                printf("\nEnter the number you want to insert at ending : \n");
                scanf("%d", &num); // Getting the value of data part of the node.
                insertEnd(num); // Passing the data to insertEnd() function.

            } // End of insert end condition.

            // Insert at given position function.
            if (subchoice == 3) {
                printf("\nEnter the position you want to insert the number : \n");
                scanf("%d", &pos); // Getting the position to insert the node.

                // Data validation.
                if (pos > noOfNodes() || pos < 1) { // If user enter invalid position, error message will print.
                    printf("Invalid position\n");
                }
                else { // Else the user entered valid position.
                    printf("Enter the number you want to insert at position : \n");
                    scanf("%d", &num); // Getting the value of data part of the node.
                    insertPosition(num, pos); // Passing the data and position to insertPosition() function.
                }

            } // End of insert position condition.

            if (choice == 0) {
                menu();
            }

            if (choice > 3 || choice < 0) {
                printf("\nInvalid choice\n");
            }

        } // End of if statement for parent insert condition.

        if (choice == 3) {

            printf("1. Delete at Beginning\n2. Delete at End\n3. Delete at given position\n0. Exit\n");
            scanf("%d", &subchoice);

            // Delete beginning function.
        if (subchoice == 1) {
            deleteBeginning(); // Calling delete beginning function.
        }

        // Delete end function.
        if (subchoice == 2) {
            deleteEnd(); // Calling delete end function.
        }

        // Delete at given position function.
        if (subchoice == 3) {
            printf("\nEnter the position you want to delete the node : \n");
            scanf("%d", &pos); // Getting the position to delete the node.

            // Data validation.
            if (pos > noOfNodes() || pos < 1) { // If user enter invalid position, error message will print.
                printf("Invalid position\n");
            }
            else { // Else the user entered valid position.
                deletePosition(pos); // Passing the position to deletePosition() function.
            }
        }
            
        } // End of if statement for parent delete condition.

        if (choice == 4) {
            reverse();
        }

        if (choice == 5) {
            reversePrint();
        }

        if (choice == 6) {
            print();
        }

        if (choice == 7) {
            printf("\nNumber of Nodes in the linked list : %d\n", noOfNodes());
        }

        if (choice > 7 || choice < 0) {
            printf("Invalid choice! Try again.\n");
        }

    } // End of while loop.

}

int main() {


    head = tail = 0;
    
    menu();

    // menu() function romba manda kaaya vaikiran...

    return 0;
} 