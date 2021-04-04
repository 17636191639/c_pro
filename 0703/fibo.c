#include <stdio.h>

int fibo(int n )
{
    int total = 0;
    if(n == 0)
    {
        return 0;
    }else if (n == 1)
    {
        return 1;
    }else
    {
        total = fibo(n - 1) +fibo(n - 2);
        return total;
    }

}

int fibo_2(int n)
{
    int i_0 = 0;
    int i_1 = 1;
    int i ;
    int total;

    if (n == 0 || n == 1) 
    {
        return n;
    }

    for (i = 1; i < n ; i++)
    {
        total = i_0 + i_1;
        i_0 = i_1;
        i_1 = total;
    }

    return total;
}

int main ()
{
   // fibo (3);
    int i ;
    for ( i = 0; i < 20; i++)
    {
         printf("%d\n",fibo_2(i) );
    }
   
    return 0;
}