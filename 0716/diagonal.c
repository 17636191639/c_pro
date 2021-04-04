#include <stdio.h>
#define  N 3

int dia_total(int a[N][N])
{
    int i;
    int total = 0;
    for (i = 0; i < N; i++) 
    {
        total += a[i][i];
    }   
    return total;
}

int main ()
{
    int a[N][N] = {{1, 2, 3},{4, 5, 6}, {7, 8, 9}};
    printf("%d\n", dia_total(a));
    return 0;
}
