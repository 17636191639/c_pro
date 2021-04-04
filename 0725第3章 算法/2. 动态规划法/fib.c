#include <stdio.h>

#define N 20

int fib_r(int n)
{
   if (n == 0 || n == 1)
   {
	   return n;
   }

   return fib_r(n - 1) + fib_r(n - 2);
}

int fib(int *dp, int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	if (!dp[n - 1])
	{
		dp[n - 1] = fib(dp, n - 1);
	}

	if(!dp[n - 2])
	{
		dp[n - 2] = fib(dp, n - 2);
	}

	return dp[n] = dp[n - 1] + dp[n - 2];
}

int main()
{
	int i;
	int dp[N + 1] = {0};

	for (i = 0; i <= N; i++)
	{
		printf("%d\n", fib_r(i));
		printf("%d\n", fib(dp, i));
	}

	return 0;
}
