#include <stdio.h>
#include <math.h>
int sushu(int n)
{  
    int total=0;
    if (n==1)
        {
            return 0;
        }
    total=sqrt(n);
    for(int i=2;i<=total;i++)
    {
        if(n%i==0)
        {
            return 0;//this is not a prime
        }
    }
    return 1;//this is a prime
}

int main ()
{
      int prime_num=0;
      for (int i =1;i<100;i++)
      {
        if(sushu(i)==1)
        {
            prime_num++;
             printf("%d ",i);
        }
      }
      printf("\n%d\n",prime_num );
      return 0;
}