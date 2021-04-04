#include <stdio.h>

void print_arr(int *n, int len)
{
    int i;
    for (i = 0 ; i < len; i ++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void swap(int *a,int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void select_sort(int *a, int len)
{
    int i,j;
    int min ;

    for (i = 0 ; i < len -1; i++)
     {
        min = i;

        for( j = i + 1; j < len ; j++)
        {
           if (a[j] < a[min])
           {
              swap(&a[min], &a[j]);
           }
        }

        print_arr(a,len);
      }
}

int main()
{
    int a[] = {2,1,3,4,6,5};//{2,1,3,4,6,5}{11, 15 ,25, -10, -40, 60}
    int len = sizeof(a) / sizeof(a[0]);
    int i ;

    select_sort(a,len);
    print_arr(a,len);
    return 0;

}