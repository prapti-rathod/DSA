#include <stdio.h>
#include <conio.h>
#define SIZE 5

int main() 
{
    int deque[SIZE];
    int front = -1, rear = -1;
    int choice, item, i;

    while (1) 
	{
        printf("\n--- Double-Ended Queue Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
	{
            case 1: // Insert at Front
                if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) 
		{
                    printf("Deque is Full\n");
                } else 
		{
                    printf("Enter the item: ");
                    scanf("%d", &item);
                    if (front == -1) 
			{
                        front = rear = 0;
                   	 } 
			else if (front == 0) 
			{
                        front = SIZE - 1;
                    	} 
			else 
			{
                        front--;
                    }
                    deque[front] = item;
                }
                break;

            case 2: // Insert at Rear
                if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) 
		{
                    printf("Deque is Full\n");
                } else 
		{
                    printf("Enter the item: ");
                    scanf("%d", &item);
                    if (front == -1) 
			{
                        front = rear = 0;
                    } 
			else if (rear == SIZE - 1) 
			{
                        rear = 0;
                    } 
			else 
			{
                        rear++;
                    }
                    deque[rear] = item;
                }
                break;

            case 3: // Delete from Front
                if (front == -1) 
		{
                    printf("Deque is Empty\n");
                } else 
		{
                    printf("Deleted item: %d\n", deque[front]);
                    if (front == rear) 
			{
                        front = rear = -1;
                    } 
			else if (front == SIZE - 1) 
			{
                        front = 0;
                    }
			else 
			{
                        front++;
                    }
                }
                break;

            case 4: // Delete from Rear
                if (front == -1) 
		{
                    printf("Deque is Empty\n");
                } 
		else 
			{
                    printf("Deleted item: %d\n", deque[rear]);
                    if (front == rear) 
			{
                        front = rear = -1;
                    } 
			else if (rear == 0) 
			{
                        rear = SIZE - 1;
                    } 
		else 
		{
                        rear--;
                    }
                }
                break;

            case 5: // Display
                if (front == -1) 
		{
                    printf("Deque is Empty\n");
                }
		else 
		{
                    printf("Deque elements: ");
                    i = front;
                    while (1) 
			{
                        printf("%d ", deque[i]);
                        if (i == rear)
                            break;
                        i = (i + 1) % SIZE;
                    }
                    printf("\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    getch();
}

