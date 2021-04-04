#include <stdio.h>

int is_palindrome(int n)
{
    int total = 0;
    int o_n = n;

    while(n > 0)
    {
        total = total *10 + (n % 10);
        n /= 10;
    }
    //printf("%d\n",total );

    if (total == o_n)
    {
        return 1;
    } else
    {
        return 0;       
    }

}

int main ()
{
    if(is_palindrome(12321) == 1)
    {
        printf("the number is a palindrome number\n");
    }else
    {
        printf("the number isn't a palindrome number\n");
    }   
    return 0;
}
