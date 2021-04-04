#include <stdio.h>

int num_cube(int n)
{
    return n*n*n;
}

int is_nar(int n)
{
    int total = 0;
    int o_n = n;
    
    while (n > 0)
    {
        total = total + num_cube(n % 10);
        n /= 10; 
    }

    if (total == o_n)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int nar_num(int n)
{
    int i;
    int num = 0;

    for(i = 100; i < n; i++)
    {
        if(is_nar(i) == 1)
        {
            num++;
            printf("%d ",i);
        }
    }
    printf("\n");
    return num;
}

int main ()
{
    printf("the nar num in your rang is %d\n",nar_num(1000));
    return 0;
}
