#include <stdio.h>

int fibo(int n)
{
    if(n < 2)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main ()
{
    int i;

    for(i = 0; i < 20; i++)
    {
        printf("%d ",fibo(i)); 
    }   
    printf("\n");

    return 0;
}
