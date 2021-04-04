#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_D   4                    //最大数是多少位
#define NUM_BUCKET 10                //定义桶的数目，这里是10进制

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


//求某一位上的数字 321， 最高位时k为1
int get_m_digit(int x, int k)
{
    int r[MAX_D] = {1000, 100, 10, 1};

    #if 0
    int t = x;
    int i;

    if (k < 1 || k > MAX_D)
    {
        return -1;
    }

    for (i = 0; i < MAX_D - k; ++i)
    {
    	x = x / 10;
    }
    #endif

    return x / r[k - 1] % 10;
}

//求某一位上的数字 321， 最低位时k为1
int get_l_digit(int x, int k)
{
    int r[MAX_D] = {1, 10, 100, 1000};

    return x / r[k - 1] % 10;
}

//MSD 递归的方法实现
void msd_radix_sort(int *v, int * aux_v,int left, int right, int k)
{
    int i;
    int j;
    int value;
    int p1;
    int p2;
    int count[NUM_BUCKET];
    int posit[NUM_BUCKET];

    if (left >= right || k > MAX_D)
    {
        return;
    }

    for (i = 0; i < NUM_BUCKET; ++i)
    {
        count[i] = 0;
    }

    for (i = left; i <= right; i++)
    {
        value = get_m_digit(v[i], k);
        count[value]++;                             //统计各桶元素的个数
    }

    posit[0] = 0;                                   //预先计算各桶开始存放位置

    for (i = 1; i < NUM_BUCKET; i++)
    {
        posit[i] = count[i - 1] + posit[i - 1];      //安排各桶元素位置
    }

    for (i = left; i <= right; i++)
    {
        value = get_m_digit(v[i], k);
        aux_v[posit[value]] = v[i];                 //记录
        posit[value]++;
    }

    j  = 0;
    i  = left;
    while (i <= right)
    {
        v[i++] = aux_v[j++];
    }

    p1 = left;
    for (i = 0; i < NUM_BUCKET; i++)
    {
        p2 = p1 + count[i] - 1;
        msd_radix_sort(v, aux_v, p1, p2, k + 1);
        p1 = p2 + 1;
    }
}


//LSD 递归的方法实现
void lsd_radix_sort1(int *v, int *aux_v, int left, int right, int k)
{
    int i;
    int j;
    int value;
    int count[NUM_BUCKET];
    int posit[NUM_BUCKET];

    if (left >= right || k > MAX_D)
    {
        return;
    }

    for (i = 0; i < NUM_BUCKET; ++i)
    {
        count[i] = 0;
    }

    for (i = left; i <= right; i++)
    {
        value = get_l_digit(v[i], k);
        count[value]++;                             //统计各桶元素的个数
    }

    posit[0] = 0;                                   //预先计算各桶开始存放位置

    for (i = 1; i < NUM_BUCKET; i++)
    {
        posit[i] = count[i - 1] + posit[i - 1];      //安排各桶元素位置
    }

    for (i = left; i <= right; i++)
    {
        value = get_l_digit(v[i], k);
        aux_v[posit[value]] = v[i];                 //记录
        posit[value]++;
    }

    j  = 0;
    i  = left;
    while (i <= right)
    {
        v[i++] = aux_v[j++];
    }

    for (i = 0; i < NUM_BUCKET; i++)
    {
        lsd_radix_sort1(v, aux_v, left, right, k + 1);
    }
}

//LSD 迭代的方法实现
void lsd_radix_sort2(int *v, int *aux_v, int left, int right, int k)
{
    int i;
    int j;
    int value;
    int count[NUM_BUCKET];
    int posit[NUM_BUCKET];

    if (left >= right || k > MAX_D)
    {
        return;
    }

    for (; k <= MAX_D; k++)
    {

        for (i = 0; i < NUM_BUCKET; ++i)
        {
            count[i] = 0;
        }

        for (i = left; i <= right; i++)
        {
            value = get_l_digit(v[i], k);
            count[value]++;                             //统计各桶元素的个数
        }

        posit[0] = 0;                                   //预先计算各桶开始存放位置

        for (i = 1; i < NUM_BUCKET; i++)
        {
            posit[i] = count[i - 1] + posit[i - 1];      //安排各桶元素位置
        }

        for (i = left; i <= right; i++)
        {
            value = get_l_digit(v[i], k);
            aux_v[posit[value]] = v[i];                 //记录
            posit[value]++;
        }

        j  = 0;
        i  = left;
        while (i <= right)
        {
            v[i++] = aux_v[j++];
        }
    }
}

int main(int argc, char const *argv[])
{
    int v[] = {1214, 1199, 65, 197, 6273, 8113, 2218, 0, 9955, 32, 101, 1999, 11, 9990, 87, 60, 81, 10, 5112, 119, 911, 375};
    int a[] = {1214, 1199, 65, 197, 6273, 8113, 2218, 0, 9955, 32, 101, 1999, 11, 9990, 87, 60, 81, 10, 5112, 119, 911, 375};

    int len = sizeof(v) / sizeof(v[0]);
    int *v_t = (int *)malloc(len * sizeof(int));
    if (v_t ==  NULL)
    {
        free(v_t);
        printf("malloc failed\n");
        exit(1);
    }

    print_array(v, len);

    msd_radix_sort(v, v_t, 0, len - 1, 1);
    print_array(v, len);

    memcpy(v, a, sizeof(a));
    lsd_radix_sort1(v, v_t, 0, len - 1, 1);
    print_array(v, len);

    memcpy(v, a, sizeof(a));
    lsd_radix_sort2(v, v_t, 0, len - 1, 1);
    print_array(v, len);

    free(v_t);
    return 0;
}
