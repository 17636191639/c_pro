#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 200
typedef struct String
{
    char str[MAXSIZE];
    int length;
}String;

void string_init(String *str);

void str_assign(String *str,char *chars);
int is_empty(String *str);
void str_cpy(String *dest, String *src);
void str_join(String *dest, String *src);
int str_length(String *p);

//////////////////////////////////////////////////字符串模式匹配/////////////////////////////////
int pattern_match(String *main_str, String *sub_str, int pos);//从pos位置开始寻找

int main()
{
    char *s = "he dfs hhheleo hello helesf";
    char *sub = "hello";
    String *p = (String *)malloc(sizeof(String));
    string_init(p);
    str_assign(p, s);

    String copy;
    string_init(&copy);
    //str_cpy(&copy, p);
    str_assign(&copy, sub);
    printf("string: %s\n", p->str);
    printf("copy: %s\n", copy.str);
    int pos = 0;
    pos = pattern_match(p, &copy, 5);
    printf("from %s\n", p->str + pos);

    // 
    // str_join(&copy, p);
    
    free(p);
    return 0;
}
//////////////////////////////////////////////////字符串模式匹配/////////////////////////////////
int pattern_match(String *main_str, String *sub_str, int pos)
{
    int i , j;
    i = pos;
    j = 0;

    while((i < main_str->length) && (j < sub_str->length))
    {
        if(main_str->str[i] == sub_str->str[j])
        {
            i++;
            j++;
        }else
        {
            i = i - j + 1;//重新设置匹配位置
            j = 0;
        }
    }
    if(j == sub_str->length)
    {
        printf("match sucess ! \n");
        return (i - j); //返回匹配串的位置
    }else
    {
        printf("failed\n");
        return 0;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////





void string_init(String *str)
{
    str->length = 0;
}
void str_assign(String *str,char *chars) ///将字符串chars存到string
{
    int len = strlen(chars);
    if(len > MAXSIZE)
    {
        return ;
    }
    str->length = 0;
    while(*chars != '\0')
    {
        str->str[str->length++] = *chars++;
    }
    str->str[str->length] = '\0';
}
int is_empty(String *str)
{
    return str->length == 0;
}
void str_cpy(String *dest, String *src)
{
    dest->length = 0;
    src->length = 0;
    while(src->str[src->length] != '\0')
    {
        dest->str[dest->length++] = src->str[src->length++];
    }
    dest->str[dest->length] = '\0';
}
void str_join(String *dest, String *src)
{
    if((dest->length + src->length) > MAXSIZE)
    {
        printf("over length!\n");
        return ;
    }
    int i;
    for(i = 0; i < src->length; i++)
    {
        dest->str[dest->length + i] = src->str[i];
    }
    dest->length += src->length;
}

int str_length(String *p)
{
    return p->length;
}
