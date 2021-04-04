#include <stdio.h>

#define STACK_SIZE 6

int stack[STACK_SIZE];
int top = 0;

int is_full()
{
	return top == STACK_SIZE;
}

int is_empty()
{
	return top == 0;
}

void push(int item)
{
	if (!is_full())
	{
		stack[top++] = item;
	}
}

int pop()
{
	return stack[--top];
}

void print(unsigned int x, unsigned int scale)
{
	int c;

	while (x > 0)
	{
		c = x % scale;
		if (c <= 10)
		{
			push(c + '0');
		}else
		{
			push(c - 10 + 'A');
		}
		
		x = x / scale;
	}

	while(!is_empty())
	{
		printf("%c", pop());
	}
}

int is_match(const char *str)
{
	char c; 
	while (*str != '\0')
	{
		if (*str == '[' || *str == '(')
		{
			push(*str);
		}else if(*str == ']')
		{
			c = pop();
			if (c != '[')
			{
				return 0;
			}
		}else if(*str == ')')
		{
			c = pop();
			if (c != '(')
			{
				return 0;
			}
		}

		str++;
	}

	if (is_empty())
	{
		return 1;
	}else
	{
		return 0;
	}
	
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	
	while(!is_empty())
	{
	    printf("%d\n", pop());
	}

	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);
	push(12);
	
	while(!is_empty())
	{
	    printf("%d\n", pop());
	}
    return 0;
}
