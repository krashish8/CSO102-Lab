// Program to reverse a string without using any extra space
#include<stdio.h>
int main()
{
    char a[100];
    printf("Enter the string: ");
    scanf("%s",a);
    int n = 0;
    while (a[n]!='\0')
    {
        n++;
    }
    for (int i = 0; i < n/2; i++)
    {
        a[i] = a[i] + a[n-i-1];
        a[n-i-1] = a[i] - a[n-i-1];
        a[i] = a[i] - a[n-i-1];
    }
    printf("String in reverse is: %s",a);
}
