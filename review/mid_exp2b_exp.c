#include <stdio.h>
#include <stdlib.h>

typedef char data_type;

data_type stack[100];
data_type top = 0;

void stack_init()
{
    top = 0;
}
void push(data_type data)
{
    printf("push: %c\n", data);
    stack[top++] = data;
}
data_type pop()
{
    printf("pop: %c\n", stack[top - 1]);
    return stack[--top];
}
int is_empty()
{
    return top == 0;
}
data_type show_top()
{
    if(!is_empty())
    {
        return stack[top - 1];
    }else
    {
        return -1;
    }
    
}

int is_operator(char op)
{
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
        return 1;
    default:
        return 0;
    }
}

int priority(char op)
{
    switch (op)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}
void infix2suffix(char *src, char *des)//中缀表达式转后缀表达式
{
    while(*src != '\0')
    {
        if((*src == ' ') || (*src >= '0' && *src <= '9'))
        {
            *des++ = *src;
        }else if(is_operator(*src))
        {
            if((!is_empty()) && (priority(*src) >= priority(show_top())))
            {
                //char tmp = pop();
                push(*src);
                //push(tmp);
            }else 
            {
                push(*src);
            }
        }else if(*src == ')')
        {
            printf("*src == ')'\n");
            char tmp;
            while((!is_empty()) && ((tmp = pop()) != '('))
            {
                *des++ = tmp;
            }
        }
        
        src++;
    }

    while((!is_empty()))
    {
        *des++ = pop();
    }
    *des = '\0';
}
int main()
{
    char *s = "18 + ( 32 - 1 ) * 55";
    char des[100] = {0};
    infix2suffix(s, des);
    printf("after:%s\n", des);
    return 0;
}

