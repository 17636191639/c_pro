#include <stdio.h>

void print_arr(int *n, int len);
int  hand_arr(int *a, int *dest, int len);

int main ()
{
    int a[] = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4,5,5,6};
    int len = sizeof(a) / sizeof(a[0]);
    int max = a[len - 1];
    int dest[max];
    int num = hand_arr(a, dest, len);

    print_arr(dest, num);

    return 0;
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

int  hand_arr(int *a, int *dest, int len)
{ 
    int i;
    int j = 0;
    int max = a[len-1];
    int num = 0;

    for(i = 0; i < len - 1;i++)
    {
        if (a[i] == a[i + 1])
        {

        }else
        {
            dest[j] = a[i];
            j++;
            num++;
        }

    }
    dest[j] = max;
    num++;

    return num;
}
