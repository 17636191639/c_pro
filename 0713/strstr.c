#include <stdio.h>
#include <string.h>

char *my_strstr(char *s1, char *s2)
{
    int i = 0;
    int len = strlen(s2);
    char* o_s2 = s2;

    while (*s1 != '\0')
    {
        if(*s1 == *s2)
        {
            i++;
            s2++;
        }else
        {
            i = 0;
            s2 = o_s2;
        }
        if(i == len)
        {
            return (s1 - len + 1);
        }
        
        s1++;
    }
    return NULL;
}

int main()
{
    char *src = "i clove china forever!";
    char *a = "china";
    char *p = my_strstr(src, a);

    if(p == NULL)
    {
        printf("can't find\n");
    }else
    {
        printf("%s\n",p);
    }

    return 0;
}
