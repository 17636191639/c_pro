#include <stdio.h>

double pi(int n)
{
    double total = 0;
    int i;
    int flag;

    for (i = 1; i < n; i++)
    {
        if(i % 2 == 0)
        {
            flag = -1;
        }else
        {
            flag = 1;
        }

        total += flag * (1.0) / (2 * i - 1); 
    }

    return (4 * total);

}

int main ()
{
    printf("%lf\n",pi(10000000));
    return 0;
}
