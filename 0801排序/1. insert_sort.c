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


//直接插入排序
void insert_sort1(int *a, int len)
{
	int i;
	int j;
	int current_value;
	int pos;

	for (i = 1; i < len; i++)
	{
		current_value = a[i];

		//找到位置
		for (j = 0; j < i; j++)
		{
			if (current_value < a[j])
			{
				break;
			}
		}

		//如果在前面某个位置，插入，否则即为最大值，不用插入
		if (j < i)
		{
			pos = j;

			for (j = i; j > pos; j--)
			{
				a[j] = a[j - 1];
			}

			a[pos] = current_value;
		}

		//print_array(a, len);
	}
}

void insert_sort2(int *v, int len)
{
	int i;
    int j = 0;
    int current_value;

    for(i = 1; i < len; i++)
    {
        if(v[i] < v[i - 1])
        {
            current_value = v[i];

            for(j = i - 1; (j >= 0) && (v[j] > current_value); j--)
            {
                v[j + 1] = v[j] ;
            }

            v[j + 1] = current_value;
        }
        //print_array(a, len);
    }
}

//折半插入排序
void bin_insert_sort(int *a, int len)
{
	int i;
	int j;
	int current_value;
	int low;
	int high;
	int mid;

	for (i = 1; i < len; i++)
	{
		low = 0;
		high = i - 1;
		current_value = a[i];

		//找到位置
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (current_value < a[mid])
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}
		}

		//二分法有时不是特别精准，需要校准
		if (current_value > a[mid])
		{
			mid = mid + 1;
		}

		//移动数据
		for (j = i; j > mid; j--)
		{
			a[j] = a[j - 1];
		}

		//插入数据
		a[mid] = current_value;

		//print_array(a, len);
	}
}

//简单希尔排序
void shell_sort1(int *v, int len)
{
	int gap;
	int i;
	int j;

	for (gap = len / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < len; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (v[j] < v[j + gap])
				{
					break;
				}

				swap(v + j, v + j + gap);
			}

		}
		//print_array(v, len);
	}
}

//常见希尔排序
void shell_sort2(int *v, int len)
{
    int j = 0 ;
    int i;
    int current_value;
    int gap = len;

    do
    {
        gap = gap / 3  + 1;

        for(i = gap; i < len; i++)
        {
            if(v[i] < v[i - gap])
            {
                current_value = v[i];

                for(j = i - gap;  (j >= 0) && (v[j] > current_value); j -= gap)
                {
                    v[j + gap] = v[j];
                }

                v[j + gap] = current_value;
            }
        }
    }while(gap > 1);
}

int main(int argc, char const *argv[])
{
	int v[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999,-111,11, -90, 87, -60, 81, -10, 12, -119, 911, 375};
	int a[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999,-111,11, -90, 87, -60, 81, -10, 12, -119, 911, 375};

	int len = sizeof(v) / sizeof(v[0]);

	print_array(a, len);

	memcpy(a, v, sizeof(v));
	insert_sort1(a, len);
	print_array(a, len);

	memcpy(a, v, sizeof(v));
	insert_sort2(a, len);
	print_array(a, len);


	memcpy(a, v, sizeof(v));
	bin_insert_sort(a, len);
	print_array(a, len);

	memcpy(a, v, sizeof(v));
	shell_sort1(a, len);
	print_array(a, len);

	memcpy(a, v, sizeof(v));
	shell_sort2(a, len);
	print_array(a, len);

	return 0;
}
