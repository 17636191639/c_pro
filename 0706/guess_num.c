#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guess(int n,int right_num)
{
    if(n == right_num)
    {
        printf("WOW! You are so lucky\n");
        return 1;

    }
    else if (n > right_num)
    {
        printf("Oh, your num is too big!\n");
        return 0;
    }
    else if (n < right_num)
    {
        printf("your num is too small\n");
        return 0;
    }
    else 
    {
        return 0;
    }
}

void guess_level(int n)
{
    printf("you guessed %d time(s)\n",n);
    if (n < 5)
    {
        printf("you are a king\n");
    }
    else if (n >= 5 && n < 10)
    {
        printf("就这？？？\n");
    }
    else if (n >= 10)
    {
        printf("小垃圾\n");
    
    }
}

int main()
{
    srand(time(NULL));
    int rand_num = rand() % 100 + 1;
    int get_num;
    int guess_num = 0;

    printf("%d\n",rand_num);
    while(1)
    {
        scanf("%d",&get_num);
        guess_num++;
        if(guess(get_num, rand_num) == 1)
        {
            break;
        }

    }
    guess_level(guess_num);

    return 0;
}

