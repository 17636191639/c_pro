#include <stdio.h>


void swap(char *a, char *b)
{
    int temp ;

    temp = *a;
    *a = *b;
    *b = temp;
}

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

int word_len(char *s)
{
    int len = 0;

    while (*s != ' ' && *s != '\0')
    {
        len++;
        s++;
    }

    return len;
}

void word_rev(char *s)
{
    int w_len = word_len(s);
    str_rev(s, w_len);    

    while (*s != '\0')
    {   
        
        if(*s == ' ')
        {   
            s++;
            w_len = word_len(s);    
            str_rev(s, w_len);        
        } else
        {
            s++;
        }

    }
}

int main ()
{
    char a[] = "i am from china!";
    char test[] = "hello i";
    int len = str_len(a);

    printf("%s\n",a);
    printf("%s\n",str_rev(a,len));
    word_rev(a);
    printf("%s\n",a);
    return 0;
}
