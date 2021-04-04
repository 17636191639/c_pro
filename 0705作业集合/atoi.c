#include <stdio.h>

int  atoi(char *s)
{
    int total = 0;
    int sub_flag = 1;

    while (*s != '\0')
    {
        if(*s == ' ')
        {
            s++;
        }
        else if(*s == '-')
        {
            sub_flag = -1;
            s++;
        }
        else if (*s >= '0' && *s <= '9')
        {
            total = (total* 10) + (*s - '0');
            s++;
        }
        else 
        {
            break;
        }

    }

    return sub_flag * total;
}

int main()
{

    char a[] = "   -123abc123";
    printf("%d\n",atoi(a));

    return 0;
}
