// Program to display sine wave of given amplitude and no. of asterisks per 180 degree phase
#include <stdio.h>
#include <math.h>
int main ()
{
	float amp, num, i, j;
	printf("The amplitude of the sine wave: ");
	scanf("%f",&amp);
	printf("The no. of asterisks per 180 degree phase: ");
	scanf("%f",&num);
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < amp+amp*(sin((2*3.14*i)/num)); j++)
			printf(" ");
		printf("*\n");
	}
}
