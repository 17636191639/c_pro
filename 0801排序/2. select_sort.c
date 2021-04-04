#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//交换
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

//选择一个数组中最小的数据
int select_min(int *v, int start, int end)
{
	int i;
	int min = v[start];
	int min_pos = start;

	for (i = start; i < end; i++)
	{
		if (min > v[i])
		{
			min = v[i];
			min_pos = i;
		}
	}

	return min_pos;
}

//简单选择排序
void simple_select_sort(int *v, int n)
{
	int i = 0;
	int min_pos;

	for (i = 0; i < n; i++)
	{
		min_pos = select_min(v, i, n);
		swap(v + i, v + min_pos);
	//	print_array(v, len);
	}
}

//大根堆进行调整
void adjust_heap(int *v, int start, int end)
{
    int root_value = v[start];
    int parent = start;
    int i;

    if (start == end)
    {
    	return;
    }

	//从节点start开始到end为止， 自上而下比较， 如果子女的值大于双亲，则子女上升，原来的双亲下落到
	//大子女的位置，这样逐层处理，将一个集合的局部调整为大根堆
    for (i = start * 2 + 1; i < end; i = i * 2 + 1)
    {
        //如果右边值大于左边值，指向右边
        if ((i + 1 < end) && (v[i] < v[i+1]))
        {
            i++;
        }

        if (root_value >= v[i])
        {
        	break;
        }
        else
        {
            v[parent] = v[i];
            parent = i;
        }
    }

    //put the value in the final position
    v[parent] = root_value;
}

//堆排序主要算法
void heap_sort(int v[], int  len)
{
	int i;

    //1.构建大根堆
    for (i = len / 2 - 1; i >= 0; i--)
    {
        //put the value in the final position
        adjust_heap(v, i, len);
    }

    //2.调整堆结构+交换堆顶元素与末尾元素
    for (i = len - 1; i > 0; i--)
    {
        //堆顶元素和末尾元素进行交换
        swap(v, v + i);

        adjust_heap(v, 0, i);//重新对堆进行调整
    }
}

int main(int argc, char const *argv[])
{
	int v[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999,-111,11, -90, 87, -60, 81, -10, 12, -119, 911, 375};
	int a[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999,-111,11, -90, 87, -60, 81, -10, 12, -119, 911, 375};
	
	int len = sizeof(v) / sizeof(v[0]);

	print_array(a, len);
	
	memcpy(a, v, sizeof(v));
	simple_select_sort(a, len);
	print_array(a, len);
	
	memcpy(a, v, sizeof(v));
	simple_select_sort(a, len);
	print_array(a, len);

	return 0;
}
