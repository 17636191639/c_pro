#include <stdio.h>

void swap(char *a, char *b)
{
    int temp ;

    temp = *a;
    *a = *b;
    *b = temp;
}

char *str_rev(char *s)
{
    int begin = 0;
    int end = 0;
    char* o_s = s;

    while (*s != '\0')
    {
        end++;
        s++;
    }
    end--;
    while (begin <end)
    {
        swap(&o_s[begin], &o_s[end]);
        begin++;
        end--;
    }

    return o_s;
}

int checkbank(char *s)
{
    char *p;
    p = str_rev(s);
    int i = 1;
    int odd = 0;
    int ev_f = 0;
    int even = 0;
    //printf("%s\n",p);
    while(*p != '\0')
    {
        if(i % 2 == 1)
        {
            odd += *p - '0';
        }else
        {
            if((*p - '0') > 4)
            {
                ev_f = (*p - '0') * 2 - 9;
                
            }else
            {
                ev_f = (*p - '0') * 2;
            }
            even += ev_f;
        }
        p++;
        i++;
    }

    printf("odd:%d even:%d\n",odd,even);

    if((odd + even) % 10 == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main()
{
    char a[30];
    scanf("%s",a);
    //printf("%s\n",a);
    if(checkbank(a) == 1)
    {
        printf("校验成功！\n");
    }else
    {
        printf("校验失败！\n");
    }
    return 0;
}
