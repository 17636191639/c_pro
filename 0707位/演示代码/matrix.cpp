#include <stdio.h>

void reverse_matrix(int a[3][3])
{
    int i;
    int j;
    int tmp;

    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}

void print_matrix(int a[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    print_matrix(a);
    reverse_matrix(a);
    print_matrix(a);
   
    return 0;
}
