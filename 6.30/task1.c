#include <stdio.h>

double get_num (char *s)
{
    int total_front = 0;
    double total_after = 0.0;
    int style_flag = 0;

    while (*s != '\0')
    {

        if (*s == '.')
        {
            style_flag = 1;
            s++;
        }
        else if(style_flag == 0)
        {
            total_front = total_front * 10 +(*s - '0');
            s++;
        }
        else if (style_flag == 1)
        {
            total_after = total_after * 10 + (*s - '0');
            s++;
        }
    }

    return total_front+total_after/1000;
    
}

int main ()
{
    char *p = "123.375";
    double total = get_num(p);
    printf("%f\n",total);
    return 0;
}
