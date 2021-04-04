#include <stdio.h>

#define N 5

void print_matrix(int m[N][N])
{
    int i;
    int j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
}
void  inverse_matrix(int a[N][N])
{
    int n = N*N;
    int row;
    int col;
    int i;
    for(i = 0; i < N/2 +1;i++)
    {
        row = i;
        col = i;
        for( ; row < N - 1 -i; row++)
        {
            a[row][col] = n--;
        }
        for ( ;col < N - i - 1; col++)
        {
            a[row][col] = n--;
        }
        for( ; row > i; row--)
        {
            a[row][col] = n--;
        }
        for (; col >i; col--)
        {
            a[row][col] = n--;
        }
        if(n == 1)
        {
            a[row + 1][col + 1] = 1;
        }
    } 
}
int main()
{
    int a[N][N];

    inverse_matrix(a);
    print_matrix(a);

    return 0;
}