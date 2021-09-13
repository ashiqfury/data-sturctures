// Fury Phoenix
#include<stdio.h>
#include<conio.h>

void main() {

    int arr[] = {2, 3, 5, 1, 7, 9, 44, 6, 8, 99,22, 43};
    int size = sizeof(arr)/sizeof(int);

    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                arr[i] += arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }

    for (int i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    getch();

}
