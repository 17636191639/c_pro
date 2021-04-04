#include <stdio.h>

int gcd(int a,int b)
{
    if(a == b)
    {
        return a;
    }
    if(a > b)
    {
        return gcd(a - b, b);
    }else
    {
        return gcd(a, b - a);
    }
}

int main()
{
    printf("%d\n",gcd(8,9));
    return 0;
}
