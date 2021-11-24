// Adding two polynomials using linked list. 

// (2x2 + 3x + 5) + (4x3 + 3x2 + 3x + 4) = 4x3 + 5x2 + 6x + 9
// =>        2x2 + 3x + 5  
// =>  4x3 + 3x2 + 3x + 4 + 
//     --------------------
// =>  4x3 + 5x2 + 6x + 9 
//     --------------------


#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef; // Coefficient
    int expo; // Exponant
    struct node *next;
};  

struct node *head1 = 0, *head2 = 0, *head3 = 0; // 3 *head pointer for polynomial 1, polynomial 2 and added polynomial.

// Declaring all the functions.
struct node* initialize(int, int, struct node*);
struct node* addPolynoials();
void bubbleSort(struct node*);
void swap(struct node*, struct node*);
int length(struct node*);
void print(struct node*);


// Function for initializing and adding new element in the polynomial.
struct node* initialize(int coef, int expo, struct node *head) {
        
    struct node *temp = head;
    
	// If you want to add a new node, we need to check for the node's expo already exist or not.
	// If the expo already exist, just add the coef. Otherwise create a new node and append to it.
    while (temp != 0) {
        
        if (temp->expo == expo) {
            temp->coef += coef;
            return head;
        }
        temp = temp->next;
    }
    
	// Normal method of initializing a node.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    temp = head;
    
    newnode->coef = coef;
    newnode->expo = expo;
    newnode->next = 0;
    
    if (head == 0) {
        head = temp = newnode;
    }
    else {
        while (temp->next != 0) {
            temp = temp->next;            
        }
        temp->next = newnode;
        temp = newnode;
    }
    
	// After everytime adding a new node, sort the list, because newly added node always append at end of the list.
    bubbleSort(head);
    
    return head;
}

struct node* addPolynoials() {
    
    struct node *temp1 = head1, *temp2 = head2, *temp3 = head3;
	
	// If you recalling this function, you need to delete the existing all nodes in the list.
	// Otherwise *head is pointing existing node.
	// Without this code, newly created list is appended to first node of the existing list.
	struct node *delTemp = head3, *nextNode;
	while( nextNode != 0) {
			
			nextNode = delTemp;
			free(delTemp);
			delTemp = nextNode;
	}
	head3 = 0;
	
    // This loop ends if both the polynomials are completely traversed.
    while (temp1 != 0  && temp2 != 0) {
        
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
        if (temp1->expo > temp2->expo) {
        
            newnode->expo = temp1->expo;
            newnode->coef = temp1->coef;
            newnode->next = 0;
            temp1 = temp1->next;
            
            if (head3 == 0) {
                head3 = temp3 = newnode;    
            }
            else {
                temp3->next = newnode;
                temp3 = newnode;
            }
        }
        else if (temp1->expo < temp2->expo) {
        
            newnode->expo = temp2->expo;
            newnode->coef = temp2->coef;
            newnode->next = 0;
            temp2 = temp2->next;
            
            if (head3 == 0) {
                head3 = temp3 = newnode;    
            }
            else {
                temp3->next = newnode;
                temp3 = newnode;
            }
        }
        else if (temp1->expo == temp2->expo) {
        
            newnode->expo = temp1->expo;
            newnode->coef = temp1->coef + temp2->coef;
            newnode->next = 0;
            temp1 = temp1->next;
            temp2 = temp2->next;
            
            if (head3 == 0) {
                head3 = temp3 = newnode;
            }
            else {
                temp3->next = newnode;
                temp3 = newnode;
            }
        }
        else {
            printf("Something Wrong\n");
        }
    }
    
    return head3;
}

void bubbleSort(struct node *head)
{
    int swapped, i;
    struct node *temp;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (head == NULL)
        return;
  
    do
    {
        swapped = 0;
        temp = head;
  
        while (temp->next != lptr)
        {
            if (temp->expo < temp->next->expo)
            { 
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        lptr = temp;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->expo;
    a->expo = b->expo;
    b->expo = temp;
    
    temp = a->coef;
    a->coef = b->coef;
    b->coef = temp;
}

int length(struct node *head) {
    
    struct node *temp = head;
    int count = 0;
    
    while (temp != 0) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

void print(struct node *head) {
    
    struct node *temp = head;
    
    while(temp != 0) {
        printf("%dx%d ", temp->coef, temp->expo);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    
    
    head1 = initialize(3, 2, head1);
    head1 = initialize(2, 1, head1);
    head1 = initialize(4, 0, head1);
    print(head1);
    
    
    printf("Adding element with same expo\n");
    head1 = initialize(3,1, head1);
    print(head1);
    
    printf("Adding element with different expo\n");
    head1 = initialize(2,3, head1);
    print(head1);
    
    
    head2 = initialize(2, 3, head2);
    head2 = initialize(3, 2, head2);
    head2 = initialize(5, 1, head2);
    head2 = initialize(4, 0, head2);
    print(head2);
    
	printf("Adding the polynomials\n");
    head3 = addPolynoials();
    print(head3);
    
    printf("After adding new element\n");
    head1 = initialize(3, 3, head1);
    head3 = addPolynoials();
    print(head1);
    print(head2);
    print(head3);
    
    printf("Length of the polynomial 1 : %d\n", length(head1));
    printf("Length of the polynomial 2 : %d\n", length(head2));
    printf("Length of the polynomial 3 : %d\n", length(head3));
}