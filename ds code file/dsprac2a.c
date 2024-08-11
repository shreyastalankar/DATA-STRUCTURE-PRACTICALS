#include<stdio.h>
void main()
{
	int a[100] , n , i , index , num;
	printf("Enter the no. of element\n");
	scanf("%d", &n);
	printf("Enter the array elements\n");
	
	for (i=0 ; i<n ; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("at which index you want to insert the element\n");
	scanf("%d" , &num);
	for(i=n-1 ; i>=index ; i--)
	{
		a[i+1] = a[i];
	}
	a[index] = num;
	printf("new array : \n");
	for (i=0 ; i<n+1 ; i++)
	{
		printf("%d\n", a[i]);
	}
}