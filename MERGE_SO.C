#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[200]; // large size temporary array

    // merging two sorted halves
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // remaining elements
    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    // copy from temp to original
    for(i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void main() {
    int arr[50];
    int n;
    int i;
    clrscr();

    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for(i=0; i<n; i++)
    {
       scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for( i = 0; i < n; i++)
	printf("%d ", arr[i]);

    getch();
}
