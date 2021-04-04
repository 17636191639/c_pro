#include <stdio.h>

char *my_strcpy (char *dest, char *src)
{
    int i;
    char *o_dest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return o_dest;

}

int main()
{
    char *p = "helloworld";
    char a[11];
    
    printf ("%s\n",my_strcpy(a,p));
    return 0;
}
