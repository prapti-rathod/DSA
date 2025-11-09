#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
   int data;
   struct node *next;
}node;

node *createList();
node *insert_beg(node *head, int x);
node *insert_end(node *head, int x);
void printList(node *head);

void main()
{
  int ch, insert_option, x;
  node *head = NULL;
  clrscr();
  do
  {
    printf("\n Select an operatio");
    printf("\n 1.Create a lIst \n 2.Insert a node \n 3.Print a node \n 4.Exit");
    printf(" Enter your choice: ");
    scanf("%d", &ch);
    printf("\n");
    switch(ch)
    {
       case 1: // Create a node
		head = createList();
		break;
       case 2: // Insert a node
		do
		{
		   printf("Select a position to insert an element");
		   printf("\n1.Beginning \n2.At the End \n3.Exit");
		   printf(" Enter your choice: ");
		   scanf("%d", &insert_option);
		   switch(insert_option)
		   {
		      case 1: // Insert at Beginning
				printf("Enter the data to be inserted: ");
				scanf("%d", &x);
				head = insert_beg(head, x);
				break;
		      case 2: // Insert at the End
				printf("Enter the data to be inserted: ");
				scanf("%d", &x);
				head = insert_end(head, x);
				break;
		      case 3: // Exit
				printf("\n Exit the Insertion");
				break;
		      default: printf("Enter the valid choice: ");
				break;
		   }
		}while(insert_option!=3);
		case 3: // Print the list
			printList(head);
			break;
		case 4: // Exit
			printf("Exit the Progam");
			break;
		default: printf("Enter the valid choice: ");
			break;
       }
    }while(ch!=4);
  getch();
}

 node *createList()
 {
    node *head, *p;
    int i, n;
    head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    for(i=0; i<=n-1; i++)
    {
       if(head==NULL)
       {
	   p = head = (node *)malloc(sizeof(node));
       }
       else
       {
	  p->next = (node *)malloc(sizeof(node));
	  p= p->next;
       }
       p->next = NULL;
       scanf("%d", &(p->data));
    }
    printf("\n \n");
    return(head);
 }

node *insert_beg(node *head, int x)
{
   node *p;
   p = (node *)malloc(sizeof(node));
   p->data = x;
   p->next = head;
   head = p;
   return(head);
}

node * insert_end(node * head, int x)
{
   node *p, *q;
   p = (node *)malloc(sizeof(node));
   p->data=x;
   p->next=NULL;
   if(head==NULL)
      return(p);
   for(q = head; q->next != NULL; q = q->next);
   q->next = p;
   return(head);
}

void printList(node *head)
{
   node *p;
   printf("[ ");
   for(p = head; p != NULL; p = p->next);
   {
      printf("%d \t", p->data);
   }
   printf(" ]");
   printf("\n \n");
}