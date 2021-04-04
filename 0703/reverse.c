#include <stdio.h>

void swap(char  *a,char *b )
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int str_len(char *s)
{
    int  num = 0;

    while (*s != '\0')
    {
        num ++;
        s++;
    }
    printf("%d\n",num );
    return num;
}


char *str_rev(char *a,char first,char end)
{
    if (first > end)
    {
        return a;
    }
    swap ( &a[first], &a[end] );
    return str_rev(a, first + 1, end - 1);
}

int main ()
{
    char a[] = "1234567890";
    int len = str_len(a);

    str_rev(a,0,len-1);
    printf("%s\n",a);

    return 0;
}