#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//打印一个数组
void print_array(int *a, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}

int str_index(const char *s, const char *t, int pos)
{
	int i = pos;
	int j = 0;

	while (s[i] != '\0' && t[j]!= '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}else
		{
			i = i - j + 1;
			j = 0;
			//printf("%d\n", i);
		}
	}

	if (t[j] == '\0')
	{
		return i - j;
	}else
	{
		return -1;
	}
}

void get_next(const char *t, int *next, int len)
{
	int j = 0;
	int k = -1;

	next[j] = -1;

	while (t[j] != '\0')
	{
		if (k == -1 || t[j] == t[k])
		{
			next[++j] = ++k;
		}else
		{
			k = next[k];
		}
	}	
}

void get_next2(const char *t, int *next, int len)
{
	int j = 0;
	int k = -1;

	next[j] = -1;

	while (t[j] != '\0')
	{
		if (k == -1 || t[j] == t[k])
		{
			++j;
			++k;
			if (t[j] == t[k])
			{
				next[j] = next[k];
			}else
			{
				next[j] = k;
			}
		}else
		{
			k = next[k];
		}
	}
}


int str_index_kmp(const char *s, const char *t, int pos)
{

	int i = pos;
	int j = 0;
	int len = strlen(t);
	
	int *next = (int *)malloc(sizeof(int) * (len + 1));
	if (next == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}

	get_next(t, next, len);
	print_array(next, len);

	get_next2(t, next, len);
	print_array(next, len);

	while (s[i] != '\0' && t[j]!= '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}else if (j == 0)
		{
			i++;
		}else
		{
			j = next[j];
			printf("%d\n", i);
		}
	}

	free(next);

	if (t[j] == '\0')
	{
		return i - j;
	}else
	{
		return -1;
	}

}


int main()
{
	int pos;
	char buf[20] = "ABACCCCABABCDHI";
	const char *t = "ABAB";
	pos = str_index(buf, t, 0);
	if (pos  > 0)
	{
		printf("%s\n", buf  + pos);
	}
	
	pos =  str_index_kmp(buf, t, 0);
	if (pos  > 0)
	{
		printf("%s\n", buf  + pos);
	}
	

	return 0;
}