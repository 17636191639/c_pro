#include <stdio.h>
int Factorial(int n)
{
    int total=1;
    if(n==0)
        return 1;
    for (int i=1;i<=n;i++)
    {
        total*=i;
    }
    return total;
}
int three_num(int n)
{
    int total=0;
    int bit_num=0;
    int o_n=n;
    while(n>0)
    {
       bit_num= n%10;
       total+=Factorial(bit_num);
       n/=10;
    }
   //return total;
    if(o_n==total)
    {
        return 1 ;
    }
    else
        return 0;
}

int main()
{
    for (int i=100;i<1000;i++)
    {
        if(three_num(i)==1)
            printf("%d\n",i);
   }
    //printf("%d\n",three_num(666));
    return 0;
}