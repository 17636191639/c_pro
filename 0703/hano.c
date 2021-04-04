#include <stdio.h>
int i = 0;
void hano(int n, int from, int to ,int aux) //n is the num of dish 
{
    if( n == 1)
    {
        printf("move %d plate from %c to %c\n", n, from, to );
        i++;
        return ;
    }

    hano(n - 1, from, aux, to );
    printf("move %d plate from %c to %c\n", n, from, to );
    i++;
    hano( n - 1,aux, to, from);

}

int main ()
{

    hano(5, 'A', 'B', 'C');
    printf("%d\n",i  );
    return 0;
}