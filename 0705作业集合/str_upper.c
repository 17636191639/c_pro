#include <stdio.h>

char *str_upper(char *s)
{
    char *o_s = s;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            s++;
        } 
        else if(*s >= 'a' && *s <= 'z')
        {
            *s = *s + 'A' - 'a';
            s++;
        }
        else
        {
            s++;
        }
    }

    return o_s;

}

int main ()
{
    char a[] = "Hello *World";
    
    printf("%s\n",str_upper(a));
    return 0;
}
