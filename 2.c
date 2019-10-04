// Program to find highest number in a given matrix
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r, c, i, j;
    printf("Enter the no. of rows and columns of the matrix: \n");
    scanf("%d %d",&r,&c);
    //int a[m][n];
    int **a = (int **)malloc(r*sizeof(int *));
    for (i = 0; i < r; i++)
        a[i] = (int *)malloc(c*sizeof(int));
    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int max = a[0][0];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if(max < a[i][j]) max = a[i][j];
        }
    }
    printf("The highest number in the matrix: %d\n",max);
}
