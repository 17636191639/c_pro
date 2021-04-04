#include <stdio.h>
#include <stdlib.h>

typedef char DATATYPE;

struct stack_node
{
     DATATYPE data;
     struct stack_node *next;
};

struct stack_node *stack_init()
{
    struct stack_node *top = (struct stack_node *)malloc(sizeof(struct stack_node));
    if(top == NULL)
    { 
        printf("malloc filed!\n");
        exit(1);
    }
    top->data = 0;
    top->next = NULL;
    return top;
}
void push(struct stack_node *top, DATATYPE data)
{
    struct stack_node *p = (struct stack_node *)malloc(sizeof(struct stack_node));
    if(p == NULL)
    { 
        printf("malloc filed!\n");
        exit(1);
    }
    p->data = data;
    p->next = top->next;
    top->next = p;
}
int pop(struct stack_node *top, DATATYPE *data)
{
    if(top->next == NULL)
    {
        return 0;
    }
    struct stack_node *p = top->next;
    *data = top->next->data;
    top->next = p->next;
    free(p);
    return 1;
}
int match_brackets(char *s)//×Ö·û´®Æ¥ÅäÀ¨ºÅ
{
    struct stack_node *top = stack_init();

    while(*s != '\0')
    {
        if(*s == '{' || *s == '[')
        {
            printf("push %c\n", *s);
            push(top, *s);
        }
        if(*s == '}')
        {
            DATATYPE c;
            if(pop(top, &c))
            {
                printf("pop: %c, \n", c);
                if(c != '{')
                {
                    return 0;
                }
            }
            
        }
        if(*s == ']')
        {
            DATATYPE c;
            if(pop(top, &c))
            {
                printf("pop: %c, \n", c);
                if(c != '[')
                {
                    return 0;
                }
            }  
        }
        s++;
    }
    if(top->next == NULL)
    {
        return 1;
    }
    while(top->next != NULL)
    {
        DATATYPE n;
        pop(top, &n);
        printf("more char %c\n", n);
    }
    return 0;
}

int main()
{
    char *s = "{}{[][][[]]}";
    if(match_brackets(s))
    {
        printf("match success!\n");
    }else
    {
        printf("match failed\n");
    }
    return 0;
}