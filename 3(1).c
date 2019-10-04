// Program to find second largest element in an array
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    //int a[n];
    int *a;
    a = (int *) malloc (sizeof(int)*n);
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int max1 = -1, max2 = -1;
    for (i = 0; i < n; i++)
    {
        if(a[i] > max1) max1 = a[i];
    }
    for (i = 0; i < n; i++)
    {
        if(a[i] > max2 && a[i] != max1) max2 = a[i];
    }
    printf("The second largest element of the array: %d\n", max2);
}
