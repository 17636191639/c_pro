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

//二路一次归并过程的算法
//low为本次二路归并排序的第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
void merge(int *v, int *v_aux, int low, int mid, int high)
{
    //mid+1为第2有序区第1个元素，mid为第1有序区的最后1个元素
    int i = low;            //i 指向第 1 有序区的第 1 个元素
    int j = mid + 1;        //j 指向第 2 有序区的第 1 个元素，high 为第 2 有序区的最后一个元素
    int k = 0;              //设置临时数组的指示标志 k

    //顺序选取两个有序区的较小元素，存储到v_t数组中，因为是递增排序
    while(i <= mid && j <= high)
    {
        //较小的元素，存入v_t临时数组中
        if(v[i] <= v[j])
        {
             v_aux[k++] = v[i++];
        }else
        {
             v_aux[k++] = v[j++];
        }
    }

    //比完之后，假如第1个有序区仍有剩余，则直接全部复制到 v_t 数组
    while(i <= mid)
    {
        v_aux[k++] = v[i++];
    }

     //比完之后，假如第2个有序区还有剩余，则直接全部复制到 v_t 数组
    while(j <= high)
    {
        v_aux[k++] = v[j++];
    }

    //将排好序的序列，重存回到 list 中 low 到 high 区间
    for(i = low, k = 0; i <= high; i++, k++)
    {
        v[i] = v_aux[k];
    }
}


//递归实现二路归并排序（分治法的思想）
void merge_sort(int *v, int *v_aux ,int low, int high)
{
    //二路归并排序，分为二路
    int mid = (low + high) / 2;

    //终止条件，low >= high， 不是while，且不含等号，否则死循环
	if(low < high)
	{
		//递归过程，二路归并排序递归过程
		merge_sort(v, v_aux ,low, mid);
		merge_sort(v, v_aux ,mid + 1, high);
		//归并
		merge(v, v_aux, low, mid, high);
	}
}

int main(int argc, char const *argv[])
{
	int v[] = {14, 99, 65, 97, 73, 13, 18, 0, 55, 32, -11, 101, 999, -111, 11, -90, 87, -60, 81, -10, 12, -119, 911, 375};

	int len = sizeof(v) / sizeof(v[0]);
	int *v_aux = (int *)malloc(len * sizeof(int));
	if (v_aux ==  NULL)
	{
		free(v_aux);
		printf("malloc failed\n");
		exit(1);
	}

	print_array(v, len);

	merge_sort(v, v_aux, 0, len - 1);
	print_array(v, len);

	free(v_aux);
	return 0;
}
