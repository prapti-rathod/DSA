#include <stdio.h>
#include<conio.h>

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l-1, t, j;

    for( j=l;j<r;j++){
	if(a[j] < pivot){
	    i++;
	     t = a[i]; a[i]=a[j]; a[j]=t;
	}
    }
     t = a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
	int p = partition(a,l,r);
	quickSort(a,l,p-1);
	quickSort(a,p+1,r);
    }
}

void main(){
    int a[50];
    int n, i;
    clrscr();
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for(i=0; i<n; i++)
    {
	scanf("%d ", &a[i]);
    }
    quickSort(a,0,n-1);
    printf("\n Sorted elements are: ");
    for(i=0;i<n;i++)
	printf("%d ",a[i]);
	getch();
}
