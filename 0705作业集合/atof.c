#include <stdio.h>

double atof(char *s)
{
    double total = 0;
    int n = 0;

    while ((*s != '\0') && (*s != '.'))
    {
        total = total * 10 + (*s - '0');
        s++;
    }
    //printf("%lf\n",total);
    if(*s == '.')
    {
        s++;
    }
    
    while (*s != '\0')
    {
        //printf("%c ",*s);
        total = total * 10 + (*s - '0');
        //printf("%lf ",total);
        s++;
        n++;
    }

    while (n > 0)
    {
        total = total * 0.1;
        n--;
    }

    return total;
}

double atof_2(char *s)
{
    double total = 0;
    double power = 0.1;

    while ((*s != '\0') && (*s != '.'))
    {
        total = total * 10 + (*s - '0');
        s++;
    }

    if(*s == '.')
    {
        s++;
    }

    while (*s >= '0' && *s <= '9')
    {
        total = total + (*s - '0')* power;
        power *= 0.1;
        s++;
    }

    return total;
}

int main ()
{
    char a[] = "123.375";
    
    printf("%lf\n",atof_2(a));
    return 0;
}
