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
int main ()
{
    char a[] = "123456789";
    int len = str_len(a);

    printf("string length: %d\n",len);
    str_rev_r(a, len);
    printf("%s\n",a);
    return 0;
}
