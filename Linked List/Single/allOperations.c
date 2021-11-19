/*
    Developed : Fury Phoenix.
    Date : 16 March 2021.
    Time : 11.00 PM
    Concept : All Operations of Linked List : 
                * Initialize.
                * Insertion : At beginning, at ending and given position.
                * Deletion : At beginning, at ending and given position.
                * Count the nodes.
                * Reverse the nodes. 
                * Printing the nodes.
    Language : C.

    ** All the functions are tested and safe to use.
    I am not good at documentation.
    You will understand the concepts when reading the documentations.
===========================================================================================================================>
*/


// Linked list operations like insertion, deletion and reverse.

// When we use dynamic memory, nust include "stdlib" headerfile.
#include<stdio.h>
#include<stdlib.h>

// Node declaration.
struct node {

    int data;
    struct node *next;

}; // End of structure.

// Global variables and pointers.
struct node *head;
struct node *temp; // This temp is used for initialize function only.
// int nodeCounter = 0; Test purpose.

// Initialize the linked list. This function can't be used once initialized when *temp is declared in the fuction.
// But in this function *temp pointer is declared globally, so we can use this function infinitely.
void initialize(int num) {
    
    // Creating a *newnode pointer to access the dynamically allocated memory.
    struct node *newnode;

    // Creating a memory using malloc function and assign it to *newnode pointer.
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num; // Assigning the data to data part of the newly allocated node.
    newnode->next = 0; // Assigning the link part to NULL. NULL is also defined as '0'.

    // The frst node in the list is directly link to the *head pointer.
    if (head == 0) {
        head = temp = newnode;
    }
    else {
        temp->next = newnode; // The *temp always points last element in the node. Coz this *temp pointer is globally declared.
        temp = newnode; // Linking the newly allocated node to the existing node (last node).
    }

} // End initialize() function.

// Inserting the node at beginning of the linked list.
void insertBeginning(int num) {

    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = head; // Linking the link part in newly allocated node to next node using *head pointer.
    head = newnode; // Assigning the address of *newnode to *head.

} // End of insertBegining() function.

// Inserting the node at end of the linked list.
void insertEnding(int num){

    struct node *newnode, *temp;
    temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;

    if (head == 0) { // If head is NULL, no nodes is there. So this is the first node. Directly link this to *head pointer.
        head = newnode;
    }
    else { // Else more than one nodes are available.
        while(temp->next != 0) { // Traverse till last node in the list.
            temp = temp->next;
        }
        temp->next = newnode; // After the loop terminated, *temp contains address of last node. Link the *newnode to *link part of the *temp.
    }

} // End of insertEnd() function.

// Inserting the node at given position in the linked list.
void insertPosition(int num, int pos) {

    int i = 1; // For loop iteration.
    struct node *newnode, *temp;
    temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;

    // Counts the position, not index value. ( For index : while(i < pos){} ).
    while(i < pos-1) { // Traverse till the position to access the node.
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next; // Linking link part of *newnode to next node.
    temp->next = newnode; // Linking the link part of *temp to address of *newnode.

} // End of insertPosition() function.

// Deleting a node at beginning of the linked list.
void deleteBeginning() {
    
    struct node *temp;
    temp = head;

    if (head == 0) { // If head is NULL, list has no nodes. No sense to delete.
        printf("\nList is empty!\n");
    }
    else { // Else list has some nodes.
        head = temp->next; // Linking the second node to the* head pointer.
        temp->next = 0; // Not necessary to link the deleting node to NULL.
        free(temp); // Free up the allocated memory of deleted node.
        printf("\nFirst node has been deleted!\n");
    }

} // End of deleteBeginning() function.

// Deleting a node at end of the linked list.
void deleteEnd() {

    struct node *temp, *prevnode; // Two pointer is needed for delete at end, one for linking and another for free up the memory.
    temp = head;

    if (head == 0) {
        printf("\nList is empty!\n");
    }
    else {
        while(temp->next != 0) { // Traversal till end node of the list.
            prevnode = temp;    
            temp = temp->next;
        }
        // After the loop terminated, *temp points last node and *prevnode points second last node in the list.

        // After traversal: if the temp is head, that means linked list nad only one node. So simply link the head to NULL.
        if(temp == head) {
            head = 0;
        }
        else { // Else the linked list had more than one nodes.
            prevnode->next = 0; // Assigning the link part of *prevnode to NULL, so no longer it points any node.
        }

        free(temp); // Free up the allocated memory of deleted node.
        printf("\nEnd node has been deleted!\n");
    }

} // End of deleteEnd() function.

// Delete a node at given position of the linked list.
void deletePosition(int pos) {
    
    int i = 1; // For loop iteration.
    struct node *temp, *prevnode; // Same as logic in deleteEnd() function.
    temp = head;

    while (i < pos) { // Traversal till the given position.
        prevnode = temp;
        temp = temp->next;
        i++;
    }

    prevnode->next = temp->next;
    temp->next = 0; // Not necessary to link the deleting node to NULL.

    free(temp); // Free up the allocated memory of deleted node.
    printf("Node in given position has been deleted!");

} // End of deletePosition() function.

/* Another method to delete a node at given position.
void deletePosition(int pos) {
    
    int i = 1;
    struct node *temp, *nextnode; // Instead of *prevnode, it uses *nextnode. *nextnode pointer points deleting node.
    temp = head;

    while (i < pos-1) {
        temp = temp->next;
        i++;
    }

    nextnode = temp->next; // Now *nextnode points next nodes of *temp node.
    temp->next = nextnode->next;

    free(nextnode); // Free up the allocated memory of deleted node.
    printf("Node in given position has been deleted!");
}
*/

// Reverse the linked list.
void reverse() {

    // For reversal we need three pointers.
    struct node *prevnode, *currentnode, *nextnode; // temp is renamed as currentnode, use *temp if you mess up.

    prevnode = 0; // Initialize the *prevnode to NULL.
    currentnode = nextnode = head; // Initialize the *currentnode and *nextnode to *head pointer.

    while (nextnode != 0) {
        nextnode = currentnode->next; // nextnode = nextnode->next; 
        currentnode->next = prevnode; // Linking the node to points previous node instead of next node.
        prevnode = currentnode; // Moving *prevnode to *currentnode.
        currentnode = nextnode; // Moving *currentnode to *nextnode.
    }

    head = prevnode; // Finally link the *head pointer to *prevnode, that means last node.
    printf("\nThe nodes has been reversed!\n");

} // End of reverse() function.

// Printing number of nodes in the linked list.
int noOfNodes() {

    int count = 0; // For counting the nodes.
    struct node *temp; // For traversal the nodes.
    temp = head;

    while (temp != 0) {
        temp = temp->next;
        count++;
    }

    return count; // Returning the count value to the calling function.

    // printf("\nNumber of Nodes in the linked list : %d\n", count); // Test purpose.

} // End of noOfNodes() function.

// Printing the data in the linked list.
void print() {
    
    struct node *temp; // For traversal the nodes.
    temp = head;

    while(temp != 0) {
        printf("%d ", temp->data); // Printing the data everytime, when *temp points to next node, till end of the list.
        temp = temp->next;
    }
    printf("\n"); // For decorative purpose only.

} // End of print() function.

// Program will execute from the main() function.
void main() {

    int choice = 11; // Used for user enter the choice from the menu.
    int size = 0; // Used in initialize function to calculate number of nodes to initialize.
    int num = 0; // Getting the value of data part of the node to passing to the insert functions.
    int pos = 0; // User for inserting and deleting the nodes as given position.
    int i = 0; // For loop iterations.

    head = 0; // Initially head points to NULL.

/* For test uses : 
    printf("Initialize the data and printing : \n");
    initialize(2);
    initialize(5);
    initialize(7);
    initialize(3);
    initialize(9);
    print();

    printf("Insert at beginning : \n");
    insertBeginning(1);
    print();

    printf("Insert at ending : \n");
    insertEnding(10);
    print() ;

    printf("Insert at given position : 3\n");
    insertPosition(4, 3);
    print();

    printf("Delete st beginning : \n");
    deleteBeginning();
    print();

    printf("Delete st ending : \n");
    deleteEnd();
    print();

    printf("Delete at given position : 4\n");
    deletePosition(4);
    print();

    printf("Reversing a linked list : \n");
    reverse();
    print();

    noOfNodes();
*/

    while (choice != 0) { // When the user enter '0', the program will terminated. Because value '0' has no functionalities to do something.

        printf("\n\n************************************************************\n"); // For decorative purpose only.

        // List of menu will appear. User can choose any function they want.
        printf("1. Initialize\n2. Insert Beginning\n3. Insert Ending\n4. Insert Position\n5. Delete Beginning\n6. Delete End\n7. Delete Position\n8. Reverse\n9. Number of Nodes\n10. Print\n0. Exit\n");

        printf("************************************************************\n\n"); // For decorative purpose only.
        scanf("%d", &choice);

        // Initialize function.
        if (choice == 1) { 
            printf("\nHow many number you want to initialize : \n");
            scanf("%d", &size); // Getting numeber of inputs to insert.

            printf("Enter your numbers one by one : \n");
            for(i = 0; i < size; i++) { // Loop execute till the size value of meeted.
                scanf("%d", &num); // Getting the value of data part of the node.
                initialize(num); // Passing the data to initialize() function.
            }
        }

        // Insert beginning function.
        if (choice == 2) { 
            printf("\nEnter the number you want to insert at beginning : \n");
            scanf("%d", &num); // Getting the value of data part of the node.
            insertBeginning(num); // Passing the data to insertBeginning() function.
        }

        // Insert end function.
        if (choice == 3) {
            printf("\nEnter the number you want to insert at ending : \n");
            scanf("%d", &num); // Getting the value of data part of the node.
            insertEnding(num); // Passing the data to insertEnd() function.
        }

        // Insert at given position function.
        if (choice == 4) {
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
        }

        // Delete beginning function.
        if (choice == 5) {
            deleteBeginning(); // Calling delete beginning function.
        }

        // Delete end function.
        if (choice == 6) {
            deleteEnd(); // Calling delete end function.
        }

        // Delete at given position function.
        if (choice == 7) {
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

        // Reverse the list function.
        if (choice == 8) {

            if (noOfNodes() == 0) { // If list has no nodes, then no need to reverse. Error message will print.
                printf("\nList is empty!\n");
            }
            else { // Else list contains some nodes.
                reverse(); // Calling the reverse() function to reverse the nodes of the list.
            }
        }

        // Calculating the number of nodes in the list function.
        if (choice == 9) {
            // noOfNodes() function return count value. Count value will print with this print message.
            printf("\nNumber of Nodes in the linked list : %d\n", noOfNodes()); // Count value contains total number of nodes in the list.
        }

        // Printing the data in the list function.
        if (choice == 10) {
            printf("\nPrinting the data in the linked list : \n");
            print(); // Calling the print() function to print the data in the list.
        }

        // If the user enter the value not contains in the menu, this error message will print.
        if (choice > 10 || choice < 0) {
            printf("\nInvalid entry! Try again.\n");
        }

    } // End of while() loop.
    
    // When the program is terminated, this print message is executed.
    printf("\nProgram finished!\n"); 

} // End of main() function.


/* Updates bending : 
    1. Change the choice from menu from int to string. - Still bending.
    2. Validate the functions. - Done.
    3. Adding overwrite() function.
        - at begin.
        - at end.
        - at given position.
*/

/* <== <== <== <== <== <== <== <== <== Developed By Fury Phoenix ==> ==> ==> ==> ==> ==> ==> ==> ==> */ 


