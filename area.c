#include<stdio.h>

void findarea(double *a, int *b, int *h)
{
    *a = 0.5*(*b)*(*h);
}

int main()
{
    int b, h;
    scanf("%d %d", &b, &h);
    double a;
    findarea(&a, &b, &h);
    printf("%f", a);
}
