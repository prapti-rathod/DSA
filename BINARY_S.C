#include<stdio.h>
#include<conio.h>

void main()
{
    int a[50], n, key, temp;
    int low, high, mid;
    int i, j, found = 0;
    clrscr();
    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements (sorted)
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++)
    {
	for(j=0; j<n-1; j++)
	{
	     if(a[j]>a[j+1])
	     {
		 temp=a[j];
		 a[j]=a[j+1];
		 a[j+1]=temp;
	     }
	}
    }

    printf("\n Sorted array are: ");
    for(i=0; i<n; i++)
    {
	printf("%d ", a[i]);
    }
    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Initialize search range
    low = 0;
    high = n - 1;

    // Binary Search Loop
    while (low <= high) {
	mid = (low + high) / 2;

	if (a[mid] == key) {
	    printf("Element %d found at position %d (index %d)\n", key, mid + 1, mid);
	    found = 1;
	    break;
	} else if (a[mid] < key) {
	    low = mid + 1;   // Search right half
	} else {
	    high = mid - 1;  // Search left half
	}
    }

    if (!found) {
	printf("Element %d not found in the array.\n", key);
    }

    getch();
}
