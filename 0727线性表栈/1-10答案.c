#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct sq_list 
{
	int array[MAX_SIZE];
	int len;
}sq_list;

void print_array(sq_list *s)
{
	int i; 
	for (i = 0; i < s->len; i++)
	{
		printf("%3d ", s->array[i]);
	}
	printf("\n");
}

/* 顺序表练习题*/


/*1.从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值，
    空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行.
*/
int del_min(sq_list *s)
{
    int i;
	int min_value = s->array[0]; 
	int min_pos = 0;
    
	if (s->len == 0)
	{
		printf("sq_list is empty\n");
		exit(1);
	}

	for (i = 1; i < s->len; i++)
	{
		if (s->array[i] < min_value)
		{
			min_pos = i;
			min_value = s->array[i];
		}
	}

	s->array[min_pos] = s->array[s->len - 1];
	s->len--;

	return min_value;
}

/*
 *2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1).
 */
void reverse(sq_list *s)
{
	int i;
	int len = s->len;
	int tmp;

	for (i = 0; i < s->len / 2; i++)
	{
		tmp = s->array[i];
		s->array[i] = s->array[len - i - 1];
		s->array[len - i - 1] = tmp;
	}
}

/*
 *3.对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，
    该算法删除线性表中所有值为x的数据元素，
 */
int del_x(sq_list *s, int x)
{
	int i;
	int j = 0;
	int len = s->len;

	if (s->len == 0)
	{
		printf("sq_list is empty\n");
		exit(1);
	}

	for (i = 0; i < s->len; i++)
	{
		if (s->array[i] != x)
		{
			s->array[j++] = s->array[i];
		}else
		{
			len--;
		}	
	}

	s->len = len;
}

/*
 *4.从有序顺序表中删除其值在给定值s与t之间(要求s < t)的所有元素，
 *  如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 */
int del_s_t_sorted(sq_list *sq, int s, int t)
{
	int i;
	int j;
	int len;

	if (sq->len == 0)
	{
		printf("sq_list is empty\n");
		exit(1);
	}

	if (s > t)
	{
		printf("error range\n");
		exit(1);
	}

    //找到比s大的位置
	for (i = 0; i < sq->len; i++)
	{
		if (sq->array[i] > s)
		{
			break;
		}
	}

    //找到比t大的位置
	for (j = i; j < sq->len; j++)
	{
		if (sq->array[j] > t)
		{
			break;
		}
	}

	len = sq->len - (j - i);

    //开始拷贝，丢掉s t之间的所有元素
	for ( ; j < sq->len; j++)
	{
		sq->array[i] = sq->array[j];
		i++;
	}

	sq->len = len;
}

/*
 *5.从顺序表中删除其值在给定值s与t之间(包含s和t，要求s < t）的所有元素，
    如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 */
int del_a_b_unsorted(sq_list *sq, int s, int t)
{
	int i;
	int j = 0;
	int len = sq->len;

	if (sq->len == 0)
	{
		printf("sq_list is empty\n");
		exit(1);
	}

	if (s > t)
	{
		printf("error range\n");
		exit(1);
	}

	for (i = 0; i < sq->len; i++)
	{
		if (sq->array[i] < s || sq->array[i] > t)
		{
			sq->array[j++] = sq->array[i];
		}else
		{
			len--;
		}	
	}

	sq->len = len;
}

/*
 6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 */
void unique_sorted(sq_list *sq)
{
	int i;
	int j = 0;
	int len = sq->len;

    //i用于取数据
    //j用于写数据
	for (i = 1; i < sq->len; i++)
	{
        //例子：11122233344455678889
		if (sq->array[j] != sq->array[i])
		{
			sq->array[j + 1] = sq->array[i];
			j++;
		}else
		{
			len--;
		}
	}

	sq->len = len;
}

/*
 *7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 */
void merge(sq_list *s1, sq_list *s2, sq_list *s3)
{
	int i_1 = 0;
	int i_2 = 0;
	int i_3 = 0;

	if (s1->len + s2->len > MAX_SIZE)
	{
		printf("too big\n");
		exit(1);
	}

	while (i_1 < s1->len && i_2 < s2->len)
	{
		if (s1->array[i_1] < s2->array[i_2])
		{
			s3->array[i_3++] = s1->array[i_1++];
		}else
		{
			s3->array[i_3++] = s2->array[i_2++];
		}
	}

	while (i_1 < s1->len)
	{
		s3->array[i_3++] = s1->array[i_1++];
	}

	while (i_2 < s2->len)
	{
		s3->array[i_3++] = s2->array[i_2++];
	}

	s3->len = i_3;
}

//插入排序
void insert_sort(sq_list *s)
{
	int i = 0;
	int j;
	int value;

	for (i = 0; i < s->len - 1; i++)
	{ 
		value = s->array[i + 1];
		for (j = i; j >= 0 &&  value < s->array[j]; j--)
		{
			s->array[j + 1] = s->array[j];
		}
		s->array[j + 1] = value;
	}
}

void reverse_2(int *a, int left, int right)
{
	int tmp;

	while (left < right)
	{
		tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;

		left++;
		right--;
	}
}

/*
 *8.已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3…,am)和(b1,b2, b3…, bn). 
 *  试编写一个函数，将数组中两个顺序表的位置互换，即将(b1, b2, b3…, bn). 放在(a1, a2, a3…, am)的前面。
 */
void exchange(sq_list *s, int m, int n)
{
    //整个数组全部转置
	reverse_2(s->array, 0, m + n - 1);
    //将前n个转置
	reverse_2(s->array, 0, n - 1);
    //将后m个转置
	reverse_2(s->array, n, m + n - 1);
}

/*
 *9.线性表(a1, a2, a3…, an)中的元素递增有序且按顺序存储于计算机内。 
	要求设计一算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素位置相交换，
	若找不到则将其插入表中并使表中元素仍递增有序。
 */
void insert_one(sq_list *s, int x)
{
	int begin = 0;
	int end = s->len - 1;
	int mid;
	int tmp;
	int i;

	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (s->array[mid] == x)
		{
			break;
		}else if (s->array[mid] > x)
		{
			end = mid - 1;
		}else
		{
			begin = mid + 1;
		}
	}

	if (s->array[mid] == x && mid != s->len - 1)
	{
		tmp = s->array[mid];
		s->array[mid] = s->array[mid + 1];
		s->array[mid + 1] = tmp;
	}

    printf("%d %d\n", begin, end);

    if (begin > end)
	{
        for (i = s->len - 1; i >= 0 &&  x < s->array[i]; i--)
		{
			s->array[i + 1] = s->array[i];
		}
		s->array[i + 1] = x;
        s->len++;
    }

}
/*
 *10.【2010统考真题】设将n(n>1）个整数存效到一维数组R中。
    设计一个在时间和空间两方面都尽可能高效的算法。将R中保存的序列循环左移p(O<p<n）个位置，
    即将R中的数据由(X_0,X_1,…,X_(n-1))变换为(X_p,X_(p+1),…,X_(n-1),X_0,X_1,…,X_(p-1))。
 */
void exchange_ror(sq_list *s, int p)
{
    //整个数组全部转置
	reverse_2(s->array, 0, s->len - 1);
    //将前len - p个转置
	reverse_2(s->array, 0, s->len - p - 1);
    //将后p个转置
	reverse_2(s->array, s->len - p, s->len - 1);
}



int main()
{
	sq_list s1 = {{13, 22, 21, 15, 19, 25, 2, 17, 51, 7, 19, 42}, 12}; 
	sq_list s2 = {{3, 12, 21, 5, 19, 25, 32, 17, 51, 27, 9, 21}, 12};
	sq_list s3 = {{0}, 0};
	//sq_list s1 = {{3, 2, 21, 3, 9, 5, 2, 7, 5, 7, 9, 2}, 12}; 
	//insert_sort(&s1);
	// insert_sort(&s2);
	//print_array(&s1);
	// print_array(&s2);
	//reverse(&s1);
	//print_array(&s1);
	//printf("the min is %d\n", del_min(&s1));
	//del_x(&s1, 2);
	//del_a_b_unsorted(&s1, 3, 11);
	//unique_sorted(&s1);
	//merge(&s1, &s2, &s3);
	//print_array(&s1);

	// print_array(&s1);
	// exchange(&s1, 4, 8);
	// print_array(&s1);
	// insert_sort(&s1);
	// print_array(&s1);
	// insert_one(&s1, 10);
    //exchange_ror(&s1, 5);

    //print_array(&s1);

    getchar();
    return 0;
}