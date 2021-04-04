#include <stdio.h>
int per_num(int n)
{
    
    int factor=0;//yinshu
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            factor+=i;
        }
    }
    if(n==factor)
    {
        return 1;
    }
    else
        return 0;
    
}
int main()
{
    for(int i=1;i<1000;i++)
    {
        if(per_num(i)==1)
        printf("%d\n",i );
    }
    return 0;

}