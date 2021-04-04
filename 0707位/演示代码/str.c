#include <stdio.h>

int my_strlen(char *s)
{
    int total = 0;

    while (*s++ != '\0')
    {
        total++;
    }

    return total;
}

int count_word_len(char *s)
{
    int total = 0;

    while (*s != '\0' && *s != ' ')
    {
        s++;
        total++;
    }

    return total;
}

char *my_strcpy(char *dest, char *src)
{
    char *o_dest = dest;

    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';

    return o_dest;
}

char *strrev(char *s)
{
    char *end = s;
    char *begin = s;
    char tmp;

    while (*end != '\0')
    {
        end++;
    }
    end--;

    while (begin < end)
    {
        tmp = *begin;
        *begin = *end;
        *end = tmp;

        begin++;
        end--;
    }

    return s;
}

void strrev_r(char *s, int len)
{
    char tmp;

    if (len < 2)
    {
        return;
    }
    
    tmp = s[0];
    s[0] = s[len - 1];
    s[len - 1] = tmp;

    strrev_r(s + 1, len - 2);
}

char *hex_str(char *buf, unsigned int n)
{
    int i = 0;

    while (n > 0)
    {
        if (n % 16 < 10)
        {
            buf[i] = n % 16 + '0';
        }else
        {
            buf[i] = n % 16 - 10 + 'A';
        }

        i++;
        n = n / 16;
    }
    buf[i++] = 'x';
    buf[i++] = '0';
    buf[i] = '\0';

    return strrev(buf);
}

char *reverse_sentence(char *s)
{
    char *o_s = s;
    int word_len;
    strrev(s);

    while (*s != '\0')
    {
        while (*s == ' ')
        {
            s++;
        }
        word_len = count_word_len(s);
        strrev_r(s, word_len);
        s += word_len;
    }

    return o_s;
}

int main()
{
    char buf[] = "   I am from China!   ";
    printf("###%s###\n", reverse_sentence(buf));

    return 0;
}
