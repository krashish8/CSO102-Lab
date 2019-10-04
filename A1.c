#include<stdio.h>
#include<math.h>

int main ()
{
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    printf("Odd Perfect squares between 1 and %d are: \n", N);
    int i = 1;
    while (i*i <= N)
    {
        printf("%d\n", i*i);
        i += 2;
    }
}


