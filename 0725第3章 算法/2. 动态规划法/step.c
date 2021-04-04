#include <stdio.h>

#define N 20

int step1(int n)
{
    if (n == 1 ||n == 2)
    {
        return n;
    }

    return step1(n - 1) +  step1(n - 2);
}

int step(int *dp, int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}

	/*判断n-1的状态有没有被计算过*/
	if (!dp[n - 1])
	{
		dp[n - 1] = step(dp, n - 1);
	}

	if(!dp[n - 2])
	{
		dp[n - 2] = step(dp, n - 2);
	}

	return dp[n] = dp[n - 1] + dp[n - 2];
}

int main()
{
	int i;
	int dp[N + 1] = {0};

	for (i = 1; i <=  20; i++)
	{
		printf("%d\n", step(dp, i));
		printf("%d\n", step(dp, i));

	}

	return 0;
}
