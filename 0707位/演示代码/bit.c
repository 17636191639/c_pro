#include <stdio.h>

void print_bin(unsigned int x);
int countbit(unsigned int x); 
unsigned int ror(unsigned int x,int num);
unsigned int ror2(unsigned int x,int num);
unsigned int get_bits(unsigned int x,int p1, int p2);
unsigned int get_unbits(unsigned int x,int p1, int p2);
unsigned int set_bit(unsigned int x,int p, int v);
unsigned int get_xor_bits(unsigned int x);
unsigned int get_xor_bits2(unsigned int x);

int main()
{
    int p1;
    int p2;

    print_bin(0x12345678);
    //scanf("%d %d", &p1, &p2);
    //print_bin(get_bits(0xdeadbeef, p1, p2));
    //print_bin(get_unbits(0xdeadbeef, p1, p2));
    //print_bin(set_bit(0xdeadbeef, p1, p2));
    print_bin(get_xor_bits(0x12345678));
    print_bin(get_xor_bits2(0x12345678));
    return 0;
}

unsigned int get_xor_bits(unsigned int x)
{
    return ror2(x, -1) ^ ror2(x, 1);
}

unsigned int get_xor_bits2(unsigned int x)
{
    int i;
    unsigned int total = 0;
    unsigned int left;
    unsigned int right;

    for (i = 1; i < 31; i++)
    {
       right = ((x >> (i - 1)) & 1u) << i;
       left =  ((x >> (i + 1)) & 1u) << i;
       total += right ^ left;
    }

    total += (x >> 31) ^ ((x >> 1) & 1u);
    total += (x ^ ((x >> 30) & 1u)) << 31;

    return total;
}

int countbit(unsigned int x)
{
    int total = 0;
    unsigned int mask = 1u;

    while (x > 0)
    {
        total += x & mask;
        x >>= 1;
    }

    return total;
}

unsigned int ror2(unsigned int x,int num)
{
    int i;
    
    while (num < 0)
    {
        num += 32;
    }

    num %= 32;

    for (i = 0; i < num; i++)
    {
        x = (x << 31) + (x >> 1);
    }

    return x;
}

unsigned int ror(unsigned int x,int num)
{
    while (num < 0)
    {
        num += 32;
    }

    num %= 32;

    return  (x << (32 - num)) + (x >> num);
}

void print_bin(unsigned int x)
{
    int i;
    
    for(i = 31; i >= 0; i--)
    {
        if (x & (1u << i))
        {
            putchar('1');
        }else
        {
            putchar('0');
        }

        if (i % 4 == 0)
        {
            putchar(' ');
        }
    }
    putchar('\n');
}

unsigned int get_bits(unsigned int x,int p1, int p2)
{
    return (x >> p1) & ~(~0u << (p2 - p1 + 1));
}

unsigned int get_unbits(unsigned int x,int p1, int p2)
{
    return get_bits(~x, p1, p2);
}

unsigned int set_bit(unsigned int x,int p, int v)
{
    if (v == 0)
    {
        return  x & ~(1u << p);
    }else
    {
        return x | (1u << p);
    }
}
