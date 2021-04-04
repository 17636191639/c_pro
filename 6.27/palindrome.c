#include <stdio.h>

int is_palin_num(int n)
{
    if((n % 10) == (n / 10000 % 10))
    {
        if((n / 10 % 10) == (n / 1000 % 10))
        {
            return 1;
        }
    }else
    {
        return 0;
    }
}

int main()
{
    int i;
    int total = 0;

    for ( i = 10000; i < 100000; i++ )
    {
        if(is_palin_num(i) == 1)
        {
           // printf("%d\n",i);
           total++;
        }
    }
    printf("%d\n",total);
    return 0;
}
