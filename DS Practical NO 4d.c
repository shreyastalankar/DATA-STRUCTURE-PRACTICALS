#include <stdio.h>
#include <stdlib.h> // Use stdlib.h instead of malloc.h

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data); 
        ptr = ptr->next;
    }
}

struct Node* deleteFirst(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocating memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Check if successful
    if (head == NULL || second == NULL || third == NULL || fourth == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize node data and link nodes
    head->data = 11;
    head->next = second;
    
    second->data = 12;
    second->next = third;
    
    third->data = 13;
    third->next = fourth;
    
    fourth->data = 14;
    fourth->next = NULL;

    printf("Linked list before deletion:\n");
    linkedListTraversal(head);
    
    head = deleteFirst(head);
    
    printf("Linked list after deletion:\n");
    linkedListTraversal(head);
    
    // Free remaining nodes
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
