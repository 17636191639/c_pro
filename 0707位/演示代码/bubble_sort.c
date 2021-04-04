#include <stdio.h>

int a[20] = {11, -10, 29, 29, 11, -10, 11, 11, 29, 0, 11, 0};
int len = 12;

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *a, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int *bubble_sort(int *a, int len)
{
    int i;
    int j;
    int is_ordered;
    int tmp;

    for (i = 0; i < len - 1; i++)
    {
        is_ordered = 1;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                is_ordered = 0;
            }
        }

        if (is_ordered == 1)
        {
            break;
        }


        print_array(a, len);
    }

    return a; 
}

int *select_sort(int *a, int len)
{
    int max_value = a[0];
    int max_pos = 0;
    int i;
    int j;

    for (i = 0; i < len - 1; i++)
    {   
        max_value = a[0];
        max_pos = 0; 
        for (j = 1; j < len - i; j++)
        {
            if (a[j] > max_value)
            {
                max_value = a[j];
                max_pos = j;
            }
        }

        if (max_pos != len - 1 - i)
        {
            swap(&a[len - 1 - i], &a[max_pos]);
        }
    }
}

int *insert_sort(int *a, int len)
{
    int i;
    int j;
    int value;

    for (i = 1; i < len; i++)
    {
        value = a[i];
        for (j = i - 1; j >= 0 && value < a[j]; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
        //        print_array(a, len);
    }

    return a;
}

int bin_search(int *a, int begin, int end, int target)
{
    int mid;

    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (a[mid] == target)
        {
            return mid;
        }else if(a[mid] > target)
        {
            end = mid - 1;
        }else
        {
            begin = mid + 1;
        }
    }

    return -1;
}

int bin_search_r(int *a, int begin, int end, int target)
{
    int mid = (begin + end) /  2;
    if (begin > end)
    {
        return -1;
    }

    if (a[mid] == target)
    {
        return mid;
    }else if(a[mid] > target)
    {
        return  bin_search_r(a, begin, mid - 1, target);
    }else
    {
        return  bin_search_r(a, mid + 1, end, target);
    }
}

void rm_repeat_item()
{
    int i;
    int j;
    int t_len = len;

    for (j = 0, i = 1; i < len; i++)
    {
        if (a[i] != a[j])
        {
            a[++j] = a[i];
        }else
        {
            t_len--;
        }
    }

    len = t_len;
}

int main()
{
    int target;
    int ret;

    print_array(a, len);
    insert_sort(&a[0], len);
    print_array(a, len);
    rm_repeat_item();
    print_array(a, len);
#if 0
    scanf("%d", &target);

    ret = bin_search_r(a, 0, len - 1, target);
    if (ret < 0)
    {
        printf("Can't find %d\n", target);
    }else
    {
        printf("%d %d %d\n", ret, target, a[ret]);
    }
#endif
    return 0;
}
