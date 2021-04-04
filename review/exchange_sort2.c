#include <stdio.h>
void print_arr(int *a, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    // int tmp = *a;
    // *a = *b;
    // *b = tmp;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void bobble_sort(int *a, int len)
{
    int i, j;
    int change_flag = 1;//0ÎªÎ´¸Ä±ä
    for(i = 0; change_flag && i < len - 1; i ++)
    {
        change_flag = 0;
        for(j = 0; j < len -1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a + j, a + j + 1);
                change_flag = 1;
            }
        }
    }
}
void quick_sort(int *a, int begin, int end)
{
    if(begin >= end)
    {
        return ;
    }

    int i = begin;
    int j = end;
    int key = a[begin];

    while(i < j)
    {
        while((i < j) && (a[j] >= key))
        {
            j--;
        }
        while((i < j) && (a[i] <= key))
        {
            i++;
        }
        if(i < j)
        {
            swap(a + i, a + j);
            //printf("change %d, %d\n", a[i], a[j]);
            print_arr(a, 10);
        }
    }
    swap(a + i, a + begin);

    print_arr(a, 10);
    quick_sort(a, begin, i - 1);
    quick_sort(a, i + 1, end);
}
int main()
{
    int a[10] = {5, 20, 1, 6, 9, 4, 10, 50, 2, 3};
    int len = sizeof(a)/ sizeof(a[0]);
    print_arr(a, len);
    //bobble_sort(a, len);
    quick_sort(a, 0, len - 1);
    //swap(a + 1, a + 5);
    print_arr(a, len);
    return 0;    
}