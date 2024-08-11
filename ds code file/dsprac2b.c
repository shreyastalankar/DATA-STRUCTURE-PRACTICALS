#include <stdio.h>

void main() {
    int a[100], n, i, index;
    
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    if (n > 100) {
        printf("The number of elements exceeds the maximum allowed (100).\n");
        return;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Which index do you want to delete?\n");
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid index.\n");
        return;
    }

    for (i = index; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    // Reduce the size of the array
    n--;

    printf("New array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
