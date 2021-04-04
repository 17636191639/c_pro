#include <stdio.h>

char * str_upper(char *dest,char *src)
{
    char *o_dest = dest;

    while(*src != '\0')
    {
        if ((*src >= 'A') && (*src <= 'Z' ))
        {
            *dest = *src;
            dest++;
            src++;
        }
        else
        {
             *dest = *src + ('A'-'a');
             dest++;
             src++;
        }
    }

    return o_dest;
}

int main ()
{
    char *p = "HelloWorld";
    char a[10];
    printf("%s\n",str_upper(a,p));
    return 0;
}
