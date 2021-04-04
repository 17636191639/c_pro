#include<stdio.h>

void print_bin(unsigned int n);
unsigned int ror(unsigned int n, int num);
unsigned int set_v(unsigned int n, int p, int v );
void print_b(unsigned int n,int p1, int p2);
void print_b_n(unsigned int n,int p1, int p2);
unsigned int xor_en(unsigned int n);
unsigned int my_pow(int x, int y);

int main ()
{
    print_b(0xabcdbeef,8,16);
    print_b_n(0xabcdbeef,8,16);
    print_bin(set_v(0x00000001,5,1));
    print_bin(xor_en(0x01010101));
    return 0;

}

unsigned int set_v(unsigned int n, int p, int v )
{
    //n >>= p;
    n = ror(n,p);
    if ((n ^ v) == 1)
    {

    }else
    {
        if((n & 1) == 0)
        {
            n = n | v;
        }else
        {
            n = n & v;
        }
    }
    n = ror(n,-p);
    return n;
}
unsigned int ror(unsigned int n, int num)
{
    while(num < 0)
    {
        num += 32;
    }
    if (num > 32)
    {
        num %= 32;
    }

    return (n << (32-num)) + (n >> num);
    
}

void print_bin(unsigned int n)
{
    int i;
    for (i = 31; i >= 0; i--)
    {
        if(n & (1u << i))
        {
            putchar ('1');
        }else 
        {
            putchar('0');
        }
        if(i % 4 == 0)
        {
            putchar(' ');
        }
    }
    printf("\n");
}


void print_b(unsigned int n,int p1, int p2)
{
    if (p1 < p2)
    {

    }
    else if (p1 > p2)
    {
        p1 = p1 ^ p2;
        p2 = p1 ^ p2;
        p1 = p1 ^ p2;
    }else 
    {
        printf("error\n");
    }

        n >>= p1;
        while((p2- p1) > 0)
        {
            printf("%d",n & 1u);
            n >>= 1;
            p2 -= 1;
        }
     printf("\n");   
    
    
}

void print_b_n(unsigned int n,int p1, int p2)
{
    //int bit_n;

    if (p1 < p2)
    {

    }
    else if (p1 > p2)
    {
        p1 = p1 ^ p2;
        p2 = p1 ^ p2;
        p1 = p1 ^ p2;
    }else 
    {
        printf("error\n");
    }

        n >>= p1;

        while((p2- p1) > 0)
        {
            if(n & 1u)
            {
                putchar('0');
            }
            else 
            {
                putchar('1');
            }

           // printf("%d",bit_n);
            n >>= 1;
            p2 -= 1;
        }
     printf("\n");   
    
    
}

unsigned int xor_en(unsigned int n)
{
    int total = 0;
    int right;
    int mid;
    int left;
    int i;

    print_bin(n);

    right = n & 1u;
    mid = ror(n,1) & 1u;
    left = ror(n, 2) & 1u;
    total = total + (right ^ left) * my_pow(2,0);

    for (i = 1; i < 31; i++)
    {
        right = mid;
        mid = left;
        left = ror(n,i+2) & 1u;
        total += (right ^ left) * my_pow(2,i);

    }
    
    total = ror(total,-1);    
    return total;
}

unsigned int my_pow (int x,int y)
{
    int total = 1;

    if(y == 0)
    {
        return 1;
    }
    while(y > 0)
    {
        total *= x;
        y--;
    }

    return total;
}































