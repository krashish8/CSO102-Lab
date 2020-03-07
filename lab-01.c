// Program to find mean, median, mode, standard deviation and variance of a given dataset in an array
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    freopen("input.txt", "r", stdin);
    int n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    //int a[n];
    int *a;
    a = (int *) malloc (sizeof(int)*n);
    printf("Enter the elements: \n");
    int s = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        s += a[i];
    }
    float mean = (float)s/n;
    printf("Mean: %f\n",mean);
    for (i = 0; i < n-1; i++)
    {
        for (j = 1; j < n-i; j++)
        {
            if(a[j]<a[j-1]) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    float median;
    if(n%2==0) median = (a[n/2-1] + a[n/2])/2.0;
    else median = a[n/2];
    printf("Median: %f\n",median);
    int mode, max = -1;
    for (i = 0; i < n; i++)
    {
        int c = 0;
        for (j = 0; j < n; j++)
        {
            if(a[i] == a[j]) c++;
        }
        if(c > max)
        {
            c = max;
            mode = a[i];
        }
    }
    printf("Mode: %d\n",mode);
    float var = 0;
    for (i = 0; i < n; i++)
    {
        var += (a[i]-mean)*(a[i]-mean);
    }
    var = var/n;
    float sd = sqrt(var);
    printf("Standard Deviation: %f\n",sd);
    printf("Variance: %f\n",var);
}
