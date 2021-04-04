#include <stdio.h>

int stack[512];
int top = 0;

void stack_init()
{
    top = 0;
}
void push(int data)
{
    stack[top++] = data;
}
int pop(void)
{
    return stack[--top];
}
int is_empty()
{
    return top == 0;
}

int fibo(int n);
int fibo_iteration(int n);
int main()
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        printf("%d\n", fibo_iteration(i));
    }

    
    //printf("fibo: %d\n", fibo(10));
    // while(!is_empty())
    // {
    //     int n = pop();
    //     if(n == 1 || n == 0)
    //     {
    //         val += n;
    //         continue;
    //     }
    //     //val += (n-1) + (n - 2);
    //     push(n - 1);
    //     push(n - 2);
    // }
    //printf("fibo %d\n", val);
    return 0;
}

int fibo(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    return (fibo(n - 1) + fibo(n - 2));
}
int fibo_iteration(int n)
{
    push(1);
    push(0);
    int i = 0;
    if(n < 2)
    {
        return pop() + pop();
    }
  
    for(i = 1; i < n; i++)
    {
        int first = pop();
        int sec = pop();
        push(first + sec);
        push(sec);
    }
    return pop() + pop();
}