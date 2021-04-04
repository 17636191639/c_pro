#include <stdio.h>

int * get()
{
    int n = 100;
    return &n;
}

int main()
{
    printf("%d\n",*(get()));
}
