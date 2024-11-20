#include <stdio.h>
#include <stdlib.h>

// Structure of the node
struct node {
    int data;
    struct node* next;
};

// Global variables for the front and rear of the queue
struct node* front = NULL;
struct node* rear = NULL;

// Enqueue function: Adds an element to the queue
int enqueue() {
    // Creating a new node
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        // Checking if the queue is overflowed
        printf("The Queue is overflow.\n");
        return -1;
    }
    printf("Enter the data:\t");
    scanf("%d", &p->data);
    p->next = NULL; // Initialize new node's next to NULL
    if (front == NULL && rear == NULL) {
        // First element in queue
        front = rear = p;
    } else {
        // Add to the end of the queue
        rear->next = p;
        rear = p;
    }
    return 0;
}

// Dequeue function: Removes an element from the queue
int dequeue() {
    if (front == NULL) {
        // Checking if the queue is empty
        printf("The Queue is underflow.\n");
        return -1;
    }
    struct node* p = front;
    printf("The deleting data is %d.\n", front->data);
    front = front->next; // Move the front to the next element
    free(p); // Free the memory of the dequeued node
    if (front == NULL) {
        // If the queue becomes empty, update rear to NULL
        rear = NULL;
    }
    return 0;
}

// Display function: Prints the elements in the queue
void display() {
    if (front == NULL) {
        // Checking if the queue is empty
        printf("The Queue is empty; no elements to print.\n");
        return;
    }
    struct node* display = front;
    printf("The data in the Queue:\t\n");
    while (display != NULL) {
        printf("%d\t", display->data);
        display = display->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    printf("Queue Implementation using Linked List\n");
    printf("Choices:\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
    do {
        printf("Enter the choice:\t");
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
