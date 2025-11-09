#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    struct Node* newNode;
    int choice, value;

    do {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Insert at End
                newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter value: ");
                scanf("%d", &value);
                newNode->data = value;
                newNode->next = NULL;

                if (head == NULL) {
                    head = newNode;
                    newNode->next = head; // circular link
                } else {
                    temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    temp->next = newNode;
                    newNode->next = head;
                }
                printf("%d inserted.\n", value);
                break;

            case 2: // Display
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    temp = head;
                    printf("Circular List: ");
                    do {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    } while (temp != head);
                    printf("(back to head)\n");
                }
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 3);

    return 0;
}
