#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[512];
int top = 0;

void init_stack()
{
    top = 0;
}
void push(int item)
{
    stack[top++] = item;
}

int pop(void)
{
    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}

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

//冒泡排序
void bubble_sort(int *v, int len)
{
	int i;
	int j;

	int is_change = 1;

	for (i = 0; is_change && i < len; i++)
	{
		is_change = 0;

		for (j = 0; j < len - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v + j, v + j + 1);
				is_change = 1;
			}
		}
		// print_array(v, len);
	}

}

//递归实现快速排序
void quick_sort1(int *v, int left, int right)
{
    int key;
    int i;
    int j;

    if (left > right)
    {
        return;
    }

    key = v[left];
    i = left;
    j = right;

    //由小到大排序
    while(i < j)
    {    
        while ((i < j) && (v[j] >= key))
        {
            j--;
        }     
        
         while((i < j) && (v[i] <= key))
        {
            i++;
        }
        
        if (i < j)
        {
            swap(v + i, v + j);
        }

    }

    swap(v + i, v + left);
    
    quick_sort1(v, left, i - 1);      //左边
    quick_sort1(v, i + 1, right);     //右边
}

//以最右值为标准
int partition_right(int v[], int left, int right)
{
    int i = left;
    int j = right;
    int key = v[right];

    while (i < j)
    {   
        while ((i < j) && (v[i] <= key))
        {
            i++;
        }

        while ((i < j) && (v[j] >= key) )
        {
           j--;
        }

        if (i < j)
        {
            swap(v + i, v + j);
        }
    }

    swap(v + i, v + right);
   
    return i;
}

//以最左值为标准
int partition_left(int v[], int left, int right)
{
    int i = left;
    int j = right;
    int key = v[left];

    while (i < j)
    {  
        while ((i < j) && (v[j] >= key) )
        {
           j--;
        }

        while ((i < j) && (v[i] <= key))
        {
            i++;
        }

        if (i < j)
        {
            swap(v + i, v + j);
        }
    }

    swap(v + i, v + left);

    return i;
}

void quick_sort2(int *v, int left, int right)
{
    int i;

    if (left > right)
    {
        return;
    }

    i = partition_right(v, left, right);

    quick_sort2(v, left, i - 1);
    quick_sort2(v, i + 1, right);
}

#define push2(A, B)  push(B); push(A);

//迭代的方法实现快速排序
void quick_sort3(int *v, int left, int right)
{ 
    int i;
    init_stack(); 
    push2(left, right);

    while (!is_empty())
    {
        left = pop();
        right = pop(); 

        if (right <= left)
        {
            continue;
        } 
            
        i = partition_right(v, left, right);

        if (i - left > right - i)   //  选较长的一端先压栈
        { 
            push2(left, i - 1); 
            push2(i + 1, right); 
        }
        else
        { 
            push2(i + 1, right); 
            push2(left, i - 1); 
        }
    }
}

int main(int argc, char const *argv[])
{
	int v[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999, -111, 11, -100, 100, 87, 987, 12, 14, -99, 66};
	//int a[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999, -111, 11, -100, 100, 87, 987, 12, 14, -99, 66};
    //int a[10] = {5, 20, 1, 6, 9, 4, 10, 50, 2, 3};

    int a[10] = {5, 2, 6, 9, 8, 100, 6, 20, 10, 15};
	//int len = sizeof(v) / sizeof(v[0]);

	print_array(a, 10);

	// memcpy(a, v, sizeof(v));
	// bubble_sort(a, len);
	// print_array(a, len);
 
	//memcpy(a, v, sizeof(v));
	quick_sort1(a, 0, 10 - 1);
	print_array(a, 10);

	// memcpy(a, v, sizeof(v));
	// quick_sort2(a, 0, len - 1);
	// print_array(a, len);

    // memcpy(a, v, sizeof(v));
    // quick_sort3(a, 0, len - 1);
    // print_array(a, len);

	return 0;
}
