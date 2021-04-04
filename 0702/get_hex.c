#include <stdio.h>

char *get_hex(int n)
{
    static char a[5];
    int total = 0;
    int num = 3;

    a[4] = '\0';

    while (n > 0)
    {
        total = n%16;
        if(total > 9)
        {
             a[num] = (n % 16) + 55;
             num--;
        }else
        {
            a[num] = n % 16 + '0';
            num--;
        }

        n /= 16;
    }
    a[0] = '0';
    a[1] = 'x';
    return a;

}

int main()
{

    printf("%s\n",get_hex(123));
    return 0;
}
