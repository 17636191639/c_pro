#include <stdio.h>

int is_prime(int n)
{
    int i = 2;
    
    if (n == 1)
    {
        return 0;
    }

    while (i < n)
    {
        if(n % i == 0)
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int num_prime(int n)
{
    int i;
    int num = 0;

    for (i = 1; i < n; i++)
    {
        if (is_prime(i) == 1)
        {
            printf("%d ",i);
            num++;
        }
    }
    printf("\n");
    return num;
}

int main ()
{
    printf("there is %d primes in your num\n",num_prime(100));

    return 0;
}
