#include <stdio.h>

void reverse_matrix(int *a, int row, int col)
{
    int i;
    int j;
    int tmp;

    for (i = 0; i < row; i++)
    {
        for (j = i + 1; j < col; j++)
        {
            tmp = a[i * col + j];
            a[i * col + j] = a[j * col + i];
            a[j * col + i] = tmp;
        }
    }
}

void print_matrix(int *a, int row, int col)
{
    int i;
    int j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", a[i * col + j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[4 * 4] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int col = 4;
    int row = 4;

    print_matrix(a, row, col);
    reverse_matrix(a, row, col);
    print_matrix(a, row, col);

    return 0;
}
