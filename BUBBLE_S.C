#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, a[50], n, temp;
    clrscr();
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for(i=0; i<n; i++)
   {
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
   getch();
}
    