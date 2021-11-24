/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct stack {
    int arr[SIZE];
    int top;
};

void initialing (struct stack*);
void push(struct stack*,int);
int pop(struct stack*);
void peek(struct stack*);

void initialing(struct stack *s) {
    s->top = -1;
}

void push(struct stack *s, int item) {
    if (s->top == SIZE-1) {
        printf("\nStack is full");
        return;
    }    
    s->top++;
    s->arr[s->top] = item;
}

int pop(struct stack *s) {
    
    int data;
    if (s->top == -1) {
        printf("\nStack is empty");
        return 0;   // return NULL;
    }
    
    data = s->arr[s->top];
    s->top--;
    return data;
}

void peek(struct stack *s) {
    printf("%d",s->arr[s->top]);
}

int main()
{
    struct stack s;
    
    initialing(&s);
    
    printf("\nPushing first element : ");
    push(&s,5);
    printf("\nPushing second element : ");
    push(&s,6);
    printf("\nPushing third element : ");
    push(&s,2);
    printf("\nPushing fourth element : ");
    push(&s,9);
    
	
    printf("\nElement in the peek : ");
    peek(&s);
    
    printf("\nPoping element : %d",pop(&s));
    printf("\nPoping element : %d",pop(&s));
    printf("\nPoping element : %d",pop(&s));
    printf("\nElement in the peek : ");
    peek(&s);
    printf("\nPoping element : %d",pop(&s));
    printf("\nPoping element : %d",pop(&s));

	getch();
    return 0;
}
