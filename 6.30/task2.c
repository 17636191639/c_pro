#include <stdio.h>


char * revers_str(char *dest , char *src)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        dest[i] = src[9-i]; 
    }
    dest[10] = '\0'; 
    return dest;
}

int main ()
{
    char *h = "helloworld";
    char a[10];
    printf ("%s\n",revers_str(a,h));
    return 0;
}
