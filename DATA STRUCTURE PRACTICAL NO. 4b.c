#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *s;

void insert_beg(struct node **s) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the value of the new node at the beginning:\n");
    scanf("%d", &p->data);
    p->next = *s;
    *s = p;
}

int main() {
    char ch;
    struct node *p, *q, *first;
    
    // Initialize the first node
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the value of the first node:\n");
    scanf("%d", &p->data);
    p->next = NULL;
    
    first = p;  // Save the start of the list
    s = p;  // Initialize s to the start of the list
    
    do {
        q = (struct node *)malloc(sizeof(struct node));
        if (q == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the value of the next node:\n");
        scanf("%d", &q->data);
        q->next = NULL;
        p->next = q;
        p = q;
        printf("Press y to add another node, any other key to stop:\n");
        scanf(" %c", &ch);  // Use scanf with a space to consume newline
    } while (ch == 'y');
    
    insert_beg(&s);
    
    printf("The linked list after insertion at the beginning:\n");
    p = s;  // Start printing from the new head of the list
    
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    
    // Free allocated memory
    p = s;
    struct node *temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    
    return 0;
}
