#include<stdio.h>
#include<conio.h>
int f=-1, r=-1, q[10], i, n, x, ch;
void Enque();
void Deque();
void Display();
void main()
{
   clrscr();
   printf(" Welcome to implementation of QUEUE!! ");
   printf("\n Enter the size of the Queue (MAX=10): ");
   scanf("%d", &n);
   do
   {
      printf("\n Operations to perform ");
      printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit ");
      printf("\n Enter your choice: ");
      scanf("%d", &ch);
      switch(ch)
      {
	 case 1: Enque();
		break;
	 case 2: Deque();
		break;
	 case 3: Display();
		break;
	 case 4: printf("\n Program is Executed");
		break;
	 default: printf("Enter the valid choice: ");
		break;
      }
   }while(ch!=4);
}

void Enque()
{
      if(r>n+1)
      {
	 printf("Queue is Overflow");
      }
      else
      {
	 if(f==-1)
	 {
	    f=0;
	 }
	 printf("Enter the element to be inserted: ");
	 scanf("%d", &x);
	 r++;
	 q[r]=x;
      }
}

void Deque()
{
  if(f==-1)
  {
     printf("Queue is Underflow");
  }
  else
  {
     printf("The deleted element is: %d",q[f]);
     f++;
  }
}

void Display()
{
   if(f==r)
   {
      printf("Queue is empty");
      f=r=-1;
   }
   else
   {
      printf("Elements of Queue: ");
      for(i=f; i<=r; i++)
      {
	 printf("%d ", q[i]);
      }
   }
}