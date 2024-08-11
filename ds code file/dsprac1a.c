#include <stdio.h>

int main() {
    int n, i, item, found = 0;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements should be greater than 0.\n");
        return 1; 
    }

    
    int a[n]; // Declare the array with size n

    
    printf("Enter the %d array elements:\n", n); //Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

   
    printf("Enter the element you want to search: "); // Input the item to search
    scanf("%d", &item);

 
    for (i = 0; i < n; i++)    // Search for the item
    {
        if (item == a[i]) {
            found = 1;
            printf("%d is found at position %d\n", item, i + 1);
            break; 
        }
    }

    if (found == 0) {
        printf("Item %d is not found \n", item);
    }

    return 0;
}
