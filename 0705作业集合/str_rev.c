#include <stdio.h>

int str_len(char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }
    return len;
}

void swap(char *a, char *b)
{
    int temp ;

    temp = *a;
    *a = *b;
    *b = temp;
}

void str_rev_r(char *s,int len)
{
    if (len < 2)
    {
        return ;
    }
    swap(&s[0], &s[len-1]);

    str_rev_r(s + 1,len - 2);

}

char *str_rev(char *s, int len)
{
    int begin = 0;
    int end = len - 1;

    while (begin <end)
    {
        swap(&s[begin], &s[end]);
        begin++;
        end--;
    }

    return s;
}

int main ()
{
    char a[] = "hello";
    int len = str_len(a);

    printf("string length: %d\n",len);
    str_rev_r(a, len);
    printf("%s\n",a);
    printf("%s\n",str_rev(a,len));
    return 0;
}
