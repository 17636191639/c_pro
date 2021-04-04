#include <stdio.h>

void del_c(char *s, char a)
{
    char *p = s;

    while(*p != '\0')
    {
        if(*p == a)
        {
            p++;
            continue;
        }
        *s = *p;
        s++;
        p++;
    }
    *s = *p;
}


int main()
{
    char a[] = "abcdccefgch";
    del_c(a, 'c');
    printf("%s\n", a);
    return 0;
}
