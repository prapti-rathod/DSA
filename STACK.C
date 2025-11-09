#include<stdio.h>
#include<conio.h>
int STK[100], top=-1, i, n, x, ch;
void Push();
void Pop();
void Peep();
void Display();

void main()
{
   clrscr();
   printf(" Welcome to implement of STACK using array!! ");
   printf("\n Enter the size of Stack (MAX=100): ");
   scanf("%d", &n);
   do
   {
      printf("\n Stack Operations ");
      printf("\n 1.Push \n 2.Pop \n 3.Peep \n 4.Display \n 5.Exit \n");
      printf("\n Enter you choice: ");
      scanf("%d", &ch);
      switch(ch)
      {
	case 1: Push();
		break;
	case 2: Pop();
		break;
	case 3: Peep();
		break;
	case 4: Display();
		break;
	case 5: printf("Program Finished.");
		break;
	default: printf("Please enter a valid choice: ");
		break;
      }
   }while(ch!=5);
}

void Push()
{
    if(top>=n-1)
    {
	printf("Stack Overflow");
    }
    else
    {
       printf("Enter the element to be pushed: ");
       scanf("%d", &x);
       top++;
       STK[top] = x;
    }
}

void Pop()
{
   if(top<0)
   {
      printf("Stack Underflow");
   }
   else
   {
      printf("The popped element is: %d",STK[top]);
      top--;
   }
}

void Peep()
{
   printf("Enter the position of the element which you want to peep: ");
   scanf("%d", &i);
   if(top-i+1 < 0)
   {
      printf("Stack Underflow  on peep");
   }
   else
   {
      printf("The %d element from the top is: %d ",i ,STK[top-i+1]);
   }
}

void Display()
{
   if(top<0)
   {
     printf("Stack is empty");
   }
   else
   {
      printf("The element in the stack are: ");
      for(i=top; i>-1; i--)
      {
	 printf("\n %d \n ", STK[i]);
      }
   }
}

