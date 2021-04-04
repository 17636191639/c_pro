#include <stdio.h>

void print_arr(int *a,int len)
{
    int i;

    for(i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insert_sort(int *a,int len)
{
    int i;
    int j;
    int to_insert;

    for( i = 1; i < len; i++)
    {
        to_insert = a[i];
        for(j = i - 1; j >= 0 && to_insert < a[j]; j--)
        {
            a[j + 1] = a[j];         
        }
        a[j +1] = to_insert;
    }
}

int main ()
{
    int a[] = {5, 1, 32, -10, 60, -50, 100};
    int len = sizeof(a) / sizeof(a[0]);

    insert_sort(a,len);
    print_arr(a,len);
    return 0;
}
