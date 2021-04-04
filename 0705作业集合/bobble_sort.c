#include<stdio.h>

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


void bobble_sort(int *a, int len)
{
    int i;
    int j;
    int flag;

    for(i = 0; i < len - 1; i++)
    {
        flag = 0;

        for (j = 0 ;j < len -1 - i; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            break;
        }

    }
}

int main ()
{
    int a[] ={1, 5, 9, 8, 4, 1};
    int len = sizeof(a) / sizeof(a[0]);
    printf("%d\n",len);
    bobble_sort(a, len);
    print_arr(a,len);
    return 0;
}
