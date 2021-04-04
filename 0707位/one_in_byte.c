#include <stdio.h>

int num_one(unsigned char n)
{
    int total = 0;
    while (n > 0)
    {
       total +=  n & 1;
       n >>= 1;
    }     
    return total;
}

int main ()
{
    printf("%d\n",num_one(200));
    return 0;
}
