#include<stdio.h>
#include<math.h>
int main()
{
    float amp = 5, ast = 10, k;
    printf("The amplitude of the sine wave: ");
	scanf("%f",&amp);
	printf("The no. of asterisks for 180 phase is: ");
	scanf("%f",&ast);
	for (int i = 0; i < ast; i++)
    {
        k = 20 + (amp*sin(6.28*i/(ast+1)));
        for (int j = 1; j < k; j++)
            printf(" ");
        printf("*\n");
    }
}
