#include <stdio.h>
int Find_9(int n)
{       int total=0;
        while(n>0)
            {
                if(n%10==9)
                    total++;
                n/=10;
            }
        return total;

}
int main()
{
        int num=0;
        for (int i=0;i<100;i++)
        {
            num+=Find_9(i);

        }
       printf("%d\n", num);
       return 0;
}