// Program to reverse an array without using any extra space
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int *a;
    a = (int *) malloc (sizeof(int)*n);
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < n/2; i++)
    {
        a[i] = a[i] + a[n-i-1];
        a[n-i-1] = a[i] - a[n-i-1];
        a[i] = a[i] - a[n-i-1];
    }
    printf("Array in reverse is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
