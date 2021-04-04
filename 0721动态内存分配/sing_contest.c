#include <stdio.h>
#include <stdlib.h>

int total_value(int *a, int len)
{
    int i;
    int total = 0;
    for(i = 0; i < len; i++)
    {
        total += a[i];
    }    
    return total ;
}

int is_ridiculous(int *a, int len)
{
    int i;
    int total = total_value(a, len);
    int max  = a[0];
    int average;
    for(i = 1; i < len ; i++)
    {
        average = (total - a[i]) / (len - 1);

        if(abs(max - (total - max) / (len - 1)) < abs (a[i] - average))
        {
            max = a[i];
        }
    }
    return max;
}

int main()
{
    int a[] = {111,121,131,112,132,119,130,129,130,126};
    int len = sizeof(a) / sizeof(a[0]) ;
    printf("%d\n", is_ridiculous(a, len));
    return 0;
}
