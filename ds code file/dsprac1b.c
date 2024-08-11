#include<stdio.h>
int main(){
    int a[100], n, i, j, update, item, pos=0, found=0, new_element;
    printf("enter the no of element\n");
    scanf("%d", &n);
    printf("enter the array elements\n");
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("how many element do want to update\n");
    scanf("%d", &update);
    for( j=0 ; j<update ; j++){
        printf("enter the element you want to update\n");
        scanf("%d", &item);
        for (i=0; i<n; i++)
        {
            if (item==a[i])
            {
                pos=i;
                found=1;
                printf("item is found at %d position\n",pos+1);
                printf("enter the new element\n");
                scanf("%d", &new_element);
                a[i]=new_element;
            }
        }
        if(found==0)
        {
            printf("item is not in array\n");
        }
    
        printf("updated array :\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
    }
}