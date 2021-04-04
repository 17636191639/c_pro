#include <stdio.h>

void swap(int *a,int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

}

void print_arr(int *n, int len)
{
    int i;
    for (i = 0 ; i < len; i ++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void bobble_sort(int *a, int len)
{
    int i,j;
    int o_flag = 0;
    int swap_flag = 0;
    int times = 0;

    for (i = 0 ; i < len -1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (a[j]  > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap_flag++;
            }
             print_arr( a, len);
             times ++;
        }

          if(swap_flag > o_flag)
            {
                o_flag = swap_flag; 
            }else
            {
                break;
            }

    }
    printf("%d\n",times );
}

int main()
{
    int a[] = {2,1,4,3,5};// {1, 2 ,3, 4, 5,6}{6, 5,4, 3, 2,1}{2,1,3,4,6,5}
    int len = sizeof(a) / sizeof(a[0]);
    int i ;

    bobble_sort(a,len);
    print_arr(a, len);
    return 0;

}
