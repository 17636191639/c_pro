#include <stdio.h>

int bin_num(int n)
{
    int num = 0;

    while(n > 0)
    {
        if(n % 2 == 1)
        {
            num++;
        }
        n /= 2;
    }
    return num;
}

int main()
{
    printf("%d\n",bin_num(123));
    return 0;
}
