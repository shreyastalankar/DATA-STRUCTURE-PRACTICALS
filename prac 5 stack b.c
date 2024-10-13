#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the stack
struct node {
    int data;
    struct node *next;
};
struct node *Top = NULL;  // Initialize Top pointer to NULL

// Function to push an element onto the stack
void push(int x) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));  // Allocate memory for the new node

    if (newNode == NULL) {  // Check if memory allocation was successful
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = Top;
    Top = newNode;  // Now the new node is at the top of the stack
}

// Function to pop an element from the stack
void pop() {
    struct node *temp;
    if (Top == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = Top;
        Top = Top->next;  // Move Top to the next node
        printf("Popped element: %d\n", temp->data);
        free(temp);  // Free memory of the popped node
    }
}

// Function to display the elements of the stack
void display() {
    struct node *temp = Top;
    if (Top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choose;
    int value;

    do {
        printf("\nChoose the operation: \n1) Push\n2) Pop\n3) Display\n4) Exit\n");
        scanf("%d", &choose);  // Correctly scan input

        switch (choose) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choose != 4);  // Continue the loop until the user chooses to exit (4)

    return 0;
}
