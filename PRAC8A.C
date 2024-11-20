#include <stdio.h>

// Creating array globally
int Queue[5];
int front = -1, rear = -1, data;

// FUNCTION FOR ENQUEUE
int enqueue() {
    if ((rear + 1) % 5 == front) {
        printf("The Queue is Overflow.\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        printf("Enter the data: ");
        scanf("%d", &data);
        Queue[rear] = data;
    } else {
        printf("Enter the data: ");
        scanf("%d", &data);
        rear = (rear + 1) % 5;
        Queue[rear] = data;
    }
    return 0;
}

// FUNCTION FOR DEQUEUE
int dequeue() {
    if (front == -1 && rear == -1) {
        printf("The Queue is Underflow.\n");
    } else if (front == rear) {
        printf("The deleting element is %d.\n", Queue[front]);
        front = rear = -1; // Reset the queue
    } else {
        printf("The deleting element is %d.\n", Queue[front]);
        front = (front + 1) % 5; // Move to the next element
    }
    return 0;
}

// FUNCTION TO DISPLAY THE QUEUE
void display() {
    if (front == -1) {
        // Checking if the queue is empty
        printf("The Queue is empty; no elements to print.\n");
    } else {
        // Printing the elements in the queue
        int i = front;
        printf("Queue elements are: ");
        while (1) {
            printf("%d\t", Queue[i]);
            if (i == rear)
                break; // Stop when we reach the rear
            i = (i + 1) % 5; // Move to the next index in a circular manner
        }
        printf("\n");
    }
}

// MAIN FUNCTION
int main() {
    int choice;
    printf("Queue Implementation\n");
    printf("Choices:\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");

    do {
        printf("Enter a valid choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("You exited the program successfully.\n");
                break;
            default:
                printf("Please enter a valid choice as mentioned!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
