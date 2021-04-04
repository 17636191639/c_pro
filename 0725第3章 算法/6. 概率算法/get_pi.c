#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double get_pi(int n)
{
	int k = 0;
	int i;
	double x;
	double y;
	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		if (x * x + y * y <= 1.0)
		{
			k++;
		}
	}

	return 4.0 * k / n;
}

 
int main()
{
	printf("%lf\n", get_pi(100));
	printf("%lf\n", get_pi(10000));
	printf("%lf\n", get_pi(1000000));
	printf("%lf\n", get_pi(100000000));
	
	return 0;
}