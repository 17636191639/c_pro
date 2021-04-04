#include <stdio.h>

void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

char *str_rev(char *s)
{
    char *begin = s;
    char *end = s;

    while (*end != '\0')
    {
        end++;
    }

    end--;

    while (begin < end)
    {
        swap(begin, end);
        begin++;
        end--;
    }

    return s;
}

char *get_hex(int n, char *a)
{
    int i = 0;

    while(n > 0)
    {
        if(n % 16 > 9)
        {
            a[i] = n % 16 - 10 + 'A'; 
        }
        else if (n % 16 < 10)
        {
            a[i] =  n % 16 + '0';
        }

        n /= 16;
        i++;
    }
    a[i++] = 'x';
    a[i++] = '0';
    a[i] = '\0';
    return str_rev(a);
}

int main ()
{
    char a[20];
    printf("%s\n", get_hex(123,a));
    return 0;
}
