#include <stdio.h>

void hano(int n,int from, int to,int aux)
{
    if(n == 1)
    {
        printf("move %d from %c to %c \n", n, from, to);
        return ;
    }
    hano(n - 1, from, aux, to);
    printf("move %d from %c to %c \n", n, from, to);
    hano(n - 1, aux, to, from);
}

int main ()
{
    hano(5,'A','B','C');
    return 0;
}
