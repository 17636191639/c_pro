#include <stdio.h>

#define N 6

void print_arr(int a[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n" );
}

// void josephus(int a[N])
// {
//     int len = N;
//     int i = 1;
//     int j;
//     int kill_flag = 0;

//     while (len > 1)
//     {
//         if(i > len)
//         {
//             i =  len % 3 ? ;
//             printf("1111111111\n");
//             printf("%d\n",i);
//         }
//         if(i % 3 == 0)
//         {
//             printf("kill %d\n", a[i - 1]);

//             for(j = i;j < len; j++)
//             {
//                 a[j - 1] = a[j];
//             }
//             len--;
//             i++;
//         }else
//         {
//              i++;
//         }


//         printf("%d\n", i);
//         //print_arr(a);
//     }
//     printf("survivor: %d\n", a[0]);
// }

void my_jos(int a[N])
{
    int len = N;
    int i = 1;
    int n = 1;
    int j;
    while (len > 1)
    {

        if (i == 3)
        {
            printf("kill %d\n", a[n - 1]);

            for(j = n;j < len; j++)
            {
                a[j - 1] = a[j];
            }
            if (n == len)
            {
                n = 1;
                i = 1;
            }
            i = 1;
            len--;

            print_arr(a);

        }else if (n == len)
        {
            n = 1;
            i++;
            printf("i :%d\n", i);
        }
        else
        { 
            n++;
            i++;
        }


    }
    printf("survivor: %d\n", a[0]);
}

int main ()
{
    int i;
    int a[N];

    for(i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    my_jos(a);
    return 0;
}
