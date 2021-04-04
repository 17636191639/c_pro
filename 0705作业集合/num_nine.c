#include <stdio.h>

int nine_in_one(int n)
{
    int num =0;

    while (n > 0)
    {
        if (n % 9 == 0)
        {
            num++;
        }
        n /= 10;
    }
    return num;
}

int num_nine(int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    {
        total += nine_in_one(i);     
    }
    return total;

}

int main ()
{
    printf("%d\n",num_nine(99));

    return 0;
}
