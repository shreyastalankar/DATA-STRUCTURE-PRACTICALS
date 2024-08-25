#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    char ch;
    struct node *p, *q, *s, *temp;
    
    // Initialize the first node
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the value of the first node:\n");
    scanf("%d", &p->data);
    p->next = NULL;
    
    s = p;  // s will be used to print the list later

    
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
        scanf(" %c", &ch);  
    } while (ch == 'y');
    
    printf("The linked list is:\n");
    temp = s;  // Use temp to traverse the list
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    // Free the allocated memory
    temp = s;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
