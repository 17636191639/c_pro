#include <stdio.h>

int is_per_num(int n)
{
    int total = 0;
    int i;

    for (i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            total += i;
        }
    }

    if (total == n)
    {
        return 1;
    }else
    {
        return 0;
    }
    
}

int num_per(int n)
{
    int i;
    int num = 0;

    for (i = 1; i < n; i++)
    {
        if(is_per_num(i) == 1)
        {
            num++;
            printf("%d ",i);
        }
    }
    printf("\n");
    return num;
}

int main ()
{
    printf("there is %d perfect num in your range\n",num_per(100));
    return 0;
}
