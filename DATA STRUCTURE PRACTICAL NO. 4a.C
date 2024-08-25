//insert at end
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void insert_end(struct node *s) {
    struct node *p =s;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));   
    printf("Enter the value of the new node at the end:\n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new_node;
}

int main() {
    char ch;
    struct node *p, *s, *q;
    struct node *first;
    
    p = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the value of the first node:\n");
    scanf("%d", &p->data);
    p->next = NULL;
    
    first = p; 
    s = p;
    
    do {
        q = (struct node*)malloc(sizeof(struct node));
        
        
        printf("Enter the value of the next node:\n");
        scanf("%d", &q->data);
        q->next = NULL;
        
        p->next = q;
        p = q;
        
        printf("Press y for another node:\n");
        scanf(" %c", &ch);
    } while (ch == 'y');
    
    insert_end(first);
    
    printf("The linked list after insertion at the end:\n");
    p = first;
    
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    
    return 0;
}
