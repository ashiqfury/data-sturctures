// Online C compiler to run C program online


#include <stdio.h>
#include <conio.h>

// Global variables.
int size = 5;
int a[50] = { 1, 2, 4, 5, 6 };
int i;

void insertBeginning(int);
void insertEnding(int);
void insertPosition(int,int);
void insertPositionBest(int,int);

void deleteBeginning();
void deleteEnding();
void deletePosition(int);
void deletePositionBest(int);

void display();
void arraySize();

int main() {
    
    int pos, num;
    int *ptr;
    
    /* Lets use this later..
    
    // Getting size of the list.
    printf("Enter size of the list : ");
    scanf("%d",&size);
    
    // Getting elements of the list.
    printf("\nEnter the elements of the list ");
    for(i=0; i<size; i++) {
        scanf("%d",&a[i]);
    } */


    display();
    insertPosition(2, 8);
    display();
    insertEnding(32);
    display();
    insertBeginning(10);
    display();
    arraySize();
    deletePosition(3);
    display();
    deleteEnding();
    display();
    deleteBeginning();
    display();
    arraySize();
    insertPositionBest(3,12);
    display();
    deletePositionBest(4);
    display();
    
    // Some random practices.. Ignore it ;) 
    ptr = a;
    printf("Size of array a : %d\n", sizeof(a));
    printf("Size of integer : %d\n", sizeof(int));
    printf("Value of *ptr : %d\n", *(ptr));
    printf("Value of a[12] : %d\n",a[12]); // No garbage value
	
	getch();
    return 0;
}


void insertPosition(int pos, int num) {
    for(i = size-1; i >= pos-1; i--) {
        a[i+1] = a[i];
    }
    a[pos-1] = num;
    size++;
}

void insertEnding(int num) {
    a[size] = num;
    size++;
}

void insertBeginning(int num) {
    for(i = size-1; i >= 0; i--) {
        a[i+1] = a[i];
    }
    a[0] = num;
    size++;
}

void insertPositionBest(int pos, int num) {
    a[size] = a[pos-1] ;
    a[pos-1] = num;
    size++;
}

void deletePosition(int pos) {
    for(i = pos-1; i < size; i++) {
        a[i] = a[i+1];
    }
    size--;
}

void deleteEnding() {
    size--;
}

void deleteBeginning() {
    for(i = 0; i < size; i++) {
        a[i] = a[i+1];
    }
    size--;
}

void deletePositionBest(int pos) {
    a[pos-1] = a[size-1];
    size--;
}

void arraySize() {
    printf("Size = %d\n", size);
}

void display() {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}