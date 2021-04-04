#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//��ӡһ������
void print_array(int *a, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}


//ֱ�Ӳ�������
void insert_sort1(int *a, int len)
{
	int i;
	int j;
	int current_value;
	int pos;

	for (i = 1; i < len; i++)
	{
		current_value = a[i];

		//�ҵ�λ��
		for (j = 0; j < i; j++)
		{
			if (current_value < a[j])
			{
				break;
			}
		}

		//�����ǰ��ĳ��λ�ã����룬����Ϊ���ֵ�����ò���
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

//�۰��������
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

		//�ҵ�λ��
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

		//���ַ���ʱ�����ر�׼����ҪУ׼
		if (current_value > a[mid])
		{
			mid = mid + 1;
		}

		//�ƶ�����
		for (j = i; j > mid; j--)
		{
			a[j] = a[j - 1];
		}

		//��������
		a[mid] = current_value;

		//print_array(a, len);
	}
}

//��ϣ������
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

//����ϣ������
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
