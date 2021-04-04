#include <stdio.h>
#include <stdlib.h>

int *init(int n)
{
    int i;
    int *p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("malloc faield\n");
        exit(1);
    }
    
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    

    return p;
}

void uninit(int *p)
{
    free(p);
}

int josph(int n)
{
    int total = 0;
    int left = n;
    int last;
    int i = 0;
    int *people = init(n);

    while(left > 1)
    {
        if (people[i] != 0)
        {
            total++;
            if (total == 3)
            {
                left--;
                printf("%d ", people[i]);
                people[i] = 0;
                total = 0;
            }

        }

        i++;
        i %= n; 
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (people[i] != 0)
        {
            last = people[i];
            break;
        }
    }

    uninit(people);

    return last;
}

int main()
{
    printf("the last is: %d\n", josph(5));

    return 0;
}
