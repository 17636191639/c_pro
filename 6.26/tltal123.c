#include <stdio.h>

int main()
{
    int a = 1234556;
    int total = 0;
    while (a>0)
    {
    total+=a%10;
    a/=10;
    }
    printf("%d\n", total);

    return 0;
}
