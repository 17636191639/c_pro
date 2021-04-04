#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int *a,int len)
{
    int i;

    for(i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void select_sort(int *a,int len)
{
    int i;
    int j;
    int buff;
    int max_value ;


    for (i = 0; i < len -1; i++)
    { 
        buff = 0;
        max_value = a[0];
        for (j = 1; j < len - i; j++)
        {
            if(a[j] > max_value)
            {
                max_value = a[j];
                buff = j;
            }
        }
        swap(&a[len - i -1] , &a[buff]);
        print_arr(a, len);
    }

}

int main ()
{
    int a[] = {6, 5, 3, 2, 4, 56, -15};
    int len = sizeof(a) / sizeof(a[0]);
    select_sort(a, len);
    print_arr(a,len);
    return 0;
}
