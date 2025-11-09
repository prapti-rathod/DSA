#include <stdio.h>
#include<conio.h>

void main() {
    int a[50],n;
    int i, j, min_idx, temp;
    clrscr();
    printf("\n Enter the number of elemnets: ");
    scanf("%d", &n);


    printf("Original array: ");
    for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
    }
    printf("\n");

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
	// Find the minimum element in the unsorted part of the array
	min_idx = i;
	for (j = i + 1; j < n; j++) {
	    if (a[j] < a[min_idx]) {
		min_idx = j;
	    }
	}

	// Swap the found minimum element with the first element of the unsorted part
	temp = a[min_idx];
	a[min_idx] = a[i];
	a[i] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
    }
    printf("\n");

    getch();
}