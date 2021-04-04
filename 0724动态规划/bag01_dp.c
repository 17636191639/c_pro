#include <stdio.h>

#define CAPACITY  10                        //背包的容量
#define N         5                         //n为物品的个数

int max(int a, int b)
{
   return a > b ? a : b;
}

void print_array(int *v, int n)
{
    int i;

    for (i = 0; i < n; ++i)
    {
        printf("%3d ", v[i]);
    }
    printf("\n");
}

int package0_1(int m[][CAPACITY + 1], int *wt, int *value, int n)//n代表物品的个数
{
    int i = 0;					//个数
    int w;						//重量

    /*********************************放置前0个物品*********************************/
    for (w = 0; w <= CAPACITY; w++)
    {
        m[i][w] = 0;
    }

    /*********************************放置1 ~ n个物品**********************************/
    for(i = 1; i <= n; i++)
    {
        for(w = 0; w <= CAPACITY; w++)
        {
            if (wt[i - 1] <= w)
            {
                    m[i][w] = max(value[i-1] + m[i-1][w-wt[i-1]], m[i-1][w]);
            }
            else
            {
                    m[i][w] = m[i-1][w];
            }
        }
    }

	return m[n][CAPACITY];
}

void answer( int *x, int m[][CAPACITY + 1], int *wt, int n)
{
    int w = CAPACITY;                       /*i = n, j= CAPACITY坐标上存放着背包容量为c时的最大价值*/
    int i;

    for(i = n - 1; i >= 0; i--)
    {
        if(m[i + 1][w] == m[i][w])
        {
            x[i] = 0;
        }
        else
        {
            x[i] = 1;                 /*如果当前物品放入了背包*/
            w = w - wt[i];            /*重新计算背包剩余容量，以计算在取最优时其他物品的取舍情况*/
        }
    }
}

int main()
{
    int wt[N]    = {2, 2, 6, 5, 4};             //物品的重量
    int value[N] = {6, 3, 5, 4, 6};             //物品对应的价值
    int m[N + 1][CAPACITY + 1] = {0}; 			//动态规划表， 行号代表选择几件放入保证，列号表示装入物品的总重量
    int x[N] = {0};								//答案表，每一个物品是否放入包中
    int i;

	printf("The best value is: %d\n", package0_1(m, wt, value, N));

    for(i = 0; i <= CAPACITY; i++)
    {
        printf("%3d ", i);
    }
    printf("\n");

    for(i = 0; i <= N; i++)
    {
        print_array(m[i], CAPACITY + 1);
    }

    answer(x, m, wt, N);

    printf("The best answer is:\n");
    print_array(x, N);

    return 0;
}
