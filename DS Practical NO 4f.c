#include <stdio.h>
#include <stdlib.h> 

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

struct Node *deleteByValue(struct Node *head, int value) {
    struct Node *p = head;
    struct Node *q = NULL;
    
    
    if (head != NULL && head->data == value) {
        q = head;
        head = head->next;
        free(q);
        return head;
    }

    // Traverse the list to find the node with the value
    while (p != NULL && p->next != NULL) {
        if (p->next->data == value) {
            q = p->next;
            p->next = q->next;
            free(q);
            return head;
        }
        p = p->next;
    }

    
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
    
    second->data = 22;
    second->next = third;
    
    third->data =33;
    third->next = fourth;
    
    fourth->data =44;
    fourth->next = NULL;

    // Print list before deletion
    printf("Linked list before deletion:\n");
    linkedListTraversal(head);
    
    // Delete node with value 11
    head = deleteByValue(head, 33);
    
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
