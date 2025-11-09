#include <stdio.h>
#include<conio.h>
void main() {
    int arr[100]; // Declare an array to store elements
    int n;        // Variable to store the number of elements
    int i, j, key; // Loop counters and temporary variable for insertion
    clrscr();
    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the array elements from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    // Perform insertion sort
    // The outer loop iterates from the second element (index 1)
    for (i = 1; i < n; i++) {
	key = arr[i]; // Store the current element to be inserted
	j = i - 1;    // Initialize j to the last element of the sorted sub-array

	// Move elements of arr[0..i-1], that are greater than key,
	// to one position ahead of their current position
	while (j >= 0 && arr[j] > key) {
	    arr[j + 1] = arr[j]; // Shift element to the right
	    j = j - 1;           // Move to the next element on the left
	}
	arr[j + 1] = key; // Place the key in its correct sorted position
    }

    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");

    getch();
}