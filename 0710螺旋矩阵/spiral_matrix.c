#include <stdio.h>
#define N 3

void sprial_matrix(int a[N][N]);
void print_arr(int a[N][N]);


int main ()
{
    //int a[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int a[N][N];
    sprial_matrix(a);
    print_arr(a);
    return 0;

}

void print_arr(int a[N][N])
{
    int i;
    int j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void sprial_matrix(int a[N][N])
{
    int i = 0;
    int j;
    int n = 1;
    int times;

    if(N % 2 == 0)
    {
        times = N / 2;
    }else
    {
        times = N / 2 + 1;
    }

    for(i = 0;i < times; i++) 
    {
        for(j = i; j <= N - i - 1; j++) //top
        {
            a[i][j] = n++;
        }

        for(j = i + 1; j <= N - i - 1; j++) //right
        {
            a[j][N-i-1] = n++;
        }

        for(j = N - i - 2; j >= i; j--) //line
        {
            a[N - i - 1][j] = n++;
        }

        for(j = N - i - 2; j >= i + 1; j--) //left
        {
            a[j][i] = n++;
        }
    }

}             
