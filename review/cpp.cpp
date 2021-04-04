#include <iostream>
void print_arr(int *a, int len = 10);
int main()
{
    int a[10] = {0};
    print_arr(a);
    return 0;
}
void print_arr(int *a, int len)
{
    for(int i = 0; i < len; i++)
    {
        std::cout << a[i] << ", " << std::endl;
    }
    
}