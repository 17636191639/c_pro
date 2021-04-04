#include <stdio.h>
#include <math.h>
double n_num(int n)
{
     double pi=4;
    for (int i=2;i<=n;i++)
    {
        pi=pi+ pow((-1),(i-1))*4/(i+(i-1));
    }
    return pi;
}
int main()
{
    printf("%lf\n",n_num(1000000) );
    return 0;
} 
//this is a test