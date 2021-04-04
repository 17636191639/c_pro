#include <stdio.h>

void bubble_sort(int *a , int len)
{
    int i;
    int j;
    int temp;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    
}

int main ()
{
    int a[5] = { 5, 4, 3, 2, 1};
    int i;
    bubble_sort(a,5);
    for (i = 0 ;i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
