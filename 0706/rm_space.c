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

char *rm_space(char *s)
{
    int i = 0;
    int j = 0;

    while(s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        s[j] = s[i];
        j++;
        i++;
    }
    s[j] = '\0';

    return s;
}

char *rm_space_p(char *s)
{
    int i = 0;
    int j = 0;
    int flag =0;

    while(s[i] != '\0')
    {
        if (s[i] == ' ' )
        {
            if(flag == 1)
            {
                i++;
            }else
            {
                flag = 1;
                s[j] = s[i];
                j++;
                i++;

            }

            continue;
        }

        s[j] = s[i];
        j++;
        i++;
        flag = 0;

    }
    s[j] = '\0';
    return s;
}

char *rm_space_pp(char *s)
{
    
    int i = 0;
    int j = 0;
    int space_flag =0;
    int f_flag = 0;
    int end_flag = 0;

    while(s[i] != '\0')
    {
        if (s[i] == ' ' && f_flag == 0)
        {
            i++;
            continue;
        }

        if (s[i] == ' ' )
        {
            if(space_flag == 1)
            {
                i++;
            }else
            {
                space_flag = 1;
                s[j] = s[i];
                j++;
                i++;
            }

            continue;
        }

        s[j] = s[i];
        j++;
        i++;
        //determine whether there is a space before the end
        if(s[i] == '\0' && space_flag == 1) 
        {
            end_flag = 1;
        }

        space_flag = 0;
        f_flag = 1;
        
    }
    if(end_flag == 1)
    {
        s[j - 1] = '\0';
    }else
    {
        s[j] = '\0';
    }
    return s;
}

int main ()
{

    char a[] = "i love china";
    char a_plus[] = "i love   china!";
    char a_pp[] = "   i  love   china!   ";
    printf("%s\n",rm_space(a));
    printf("%s\n",rm_space_p(a_plus));
    printf("%s\n",rm_space_pp(a_pp));
    printf("%d\n",str_len(rm_space_pp(a_pp)) );
    return 0;
}
