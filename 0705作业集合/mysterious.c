#include <stdio.h>

int factorial(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int is_mysterious(int n)
{
    int total = 0;
    int o_n = n;

    while (n > 0)
    {
        total += factorial(n % 10);
        n /= 10;
       // printf("%d ",total);
    }

    if (o_n == total)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int find_mysterious(int n)
{
    int i;
    int num = 0;

    for (i = 100; i < n; i++)
    {
        if (is_mysterious(i) == 1)
        {
            printf("%d ",i);
            num++;
        }
    }
    printf("\n");

    return num;
}

int main()
{
    printf("there is %d mysterious num in 100 - 1000\n",find_mysterious(1000));
    return 0;
}
