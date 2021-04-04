#include <stdio.h>

int get_num(int n)
{
    int total = 0;
    while (n > 0)
    {
        if(n % 2 == 1)
        {
            total++;
        }
        n /= 2;
    }

    return total;
}

int main ()
{
    printf("%d\n",get_num(123));
    return 0;
}
