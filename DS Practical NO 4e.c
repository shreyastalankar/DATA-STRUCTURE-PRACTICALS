#include <stdio.h>
#include <stdlib.h> // Use stdlib.h instead of malloc.h

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data); // Corrected typo
        ptr = ptr->next;
    }
}

struct Node *deleteAtLast(struct Node *head) {
    if (head == NULL) {
        // List is empty, nothing to delete
        return NULL;
    }
    
    if (head->next == NULL) {
        // List has only one node
        free(head);
        return NULL;
    }
    
    struct Node *p = head;
    struct Node *q = head->next;

    // Traverse to the second last node
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    
    // Delete the last node
    p->next = NULL;
    free(q);
    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Initialize node data and link nodes
    head->data = 11;
    head->next = second;
    
    second->data = 12;
    second->next = third;
    
    third->data = 13;
    third->next = fourth;
    
    fourth->data = 14;
    fourth->next = NULL;

    // Print list before deletion
    printf("Linked list before deletion:\n");
    linkedListTraversal(head);
    
    // Delete the last node
    head = deleteAtLast(head);
    
    // Print list after deletion
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
