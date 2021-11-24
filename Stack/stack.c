#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int);
void pop();
int isEmpty();
int isFull();
void print();

void push(int num) {
    if(top == MAX_SIZE-1) {
        printf("Stack is full\n");
    }
    else
	{
		stack[++top] = num;
	}
}

void pop() {
    if(top == -1) {
        printf("Stack is empty\n");
    }
    else
	{
		top--;
	}
}

int isEmpty() {
    if (top == -1){
        return 1;
    }
    else return 0;
}

int isFull() {
    if(top == MAX_SIZE-1) {
        return 1;
    }
    else return 0;
}

int peek() {
    return stack[top];
}


void print() {
	int i;
    for (i=0; i<=stack[top]; i++) {
        printf("%d\n",stack[i]);
    }
}


int main() {

	int i;

    push(5);
    push(10);
    push(15);
    push(20);
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
	push(100);
	printf("%d\n", peek());

	for (i=0; i<100; i++) {
		push(35);
	}

	printf("%d\n", peek());
    print();

	return 0;

}
