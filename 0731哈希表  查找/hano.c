#include <stdio.h>

#define STACK_SIZE 60
typedef struct item
{
	int max_id;
	int left;
	char src;
	char dest;
	char aux;
}item;

item stack[STACK_SIZE];
int top = 0;

int is_full()
{
	return top == STACK_SIZE;
}

int is_empty()
{
	return top == 0;
}

void push(item data)
{
	if (!is_full())
	{
		stack[top++] = data;
	}
}

item pop()
{
	return stack[--top];
}

void hano(char src, char dest, char aux, int n)
{
	item cur = {n, n, src, dest, aux};
	item v;
	
	push(cur);
	while (!is_empty())
	{
		v = pop();
		if (v.left == 1)
		{
			printf("mov disk %d src %c to %c\n",  v.max_id, v.src, v.dest);
		}else
		{
			//disk n-1from t
			cur.left = v.left - 1;
			cur.max_id = v.max_id - 1;
			cur.src = v.aux;
			cur.dest = v.dest;
			cur.aux = v.src;
			push(cur);
			//
			cur.left = 1;
			cur.max_id = v.max_id;
			cur.src = v.src;
			cur.dest = v.dest;
			cur.aux = v.aux;
			push(cur);
			//
			cur.left = v.left - 1;
			cur.max_id = v.max_id - 1;
			cur.src = v.src;
			cur.dest = v.aux;
			cur.aux = v.dest;
			push(cur);
		}
	}
}

void hano_r(char src, char dest, char aux, int n)
{
	if (n == 1)
	{
		printf("mov disk %d from %c to %c\n", n, src, dest);
		return;
	}

	hano_r(src, aux, dest, n - 1);
	printf("mov disk %d from %c to %c\n", n, src, dest);
	hano_r(aux, dest, src, n - 1);
}

int main()
{
	hano('A', 'C', 'B', 3);
	printf("-------------------------------\n");
	hano_r('A', 'C', 'B', 3);
	return 0;
}
