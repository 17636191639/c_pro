#include<stdio.h>

int gcd_ea(int a,int b)
{
    if(a % b == 0)
    {
        return b;
    }else if (a > b)
    {
        return gcd_ea(b,a % b);
    }
}

int main ()
{
    printf("%d\n",gcd_ea(1997,615));
    return 0;
}
