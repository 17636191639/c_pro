#include <stdio.h>

int my_bin_serch(int *a, int begin , int end, int target)//Recursion is used
{
    int mid = (begin + end) / 2;

    if (begin >end)
    {
        return -1;
    }

    if (a[mid] == target)
    {
        return mid;
    }
    else if (a[mid] > target)
    {
        my_bin_serch(a, begin, (mid - 1),target);
    }else 
    {
        my_bin_serch(a, (mid + 1),end,target);
    }
}

int bin_serch(int *a, int begin , int end, int target) // iteration
{
    int mid;

    while(begin <= end)
    {
        mid = (begin + end) / 2;
        if(a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] >target)
        {
            end = mid - 1;
        }else
        {
            begin = mid + 1;
        }

    }
    return -1;
}
void swap(int *a,int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

}

void bobble_sort(int *a, int len)
{
    int i,j;
    for (i = 0 ; i < len -1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (a[j]  > a[j + 1])
            {
                     swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main()
{
    int a[] = {11, 15 ,25, -10, -40, 60,};
    int len = sizeof(a) / sizeof(a[0]);
    int i;
    int ret;
    int target =  -10;

    bobble_sort(a, len);
    for (i = 0; i < len ;i++)
     {
        printf("%d ",a[i] );
     }
     printf("\n");
    
    ret = my_bin_serch(a, 0 , len - 1, target);
    if (ret >= 0)
    {
        printf("%d %d \n",ret,  a[ret] );
    }else
    {
        printf("can not find the num\n");
    }

    return 0;

}