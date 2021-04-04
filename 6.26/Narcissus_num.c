#include <stdio.h>
int Nar_num(int n)
{
    int Bit_num=0;
    int total=0;
    int o_n=n;
        while (n>0)
        {
            Bit_num=n%10;
            total+=Bit_num*Bit_num*Bit_num;
            n/=10;
        }
        if(total==o_n)
            return 1;//narcissus number
        else
            return 0;
}
int main ()
{
    for (int i=100;i<1000;i++)
    {
        if(Nar_num(i)==1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}