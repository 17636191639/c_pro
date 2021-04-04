#include <stdio.h>
int stack[512];//自建栈
int top = 0;

void swap(int *a, int *b);
void print_arr(int *a, int len);
void bobble_sort(int *a, int len);
void select_sort(int *a, int len);
void quick_sort(int *a, int begin, int end);
void quick_sort2(int *a, int begin, int end);
void quick_sort3(int *a, int begin, int end);
void quick_sort_iteration(int *a, int begin, int end);
int partition_left(int *a, int begin, int end);
int main()
{
    int arr[10] = {5, 2, 6, 9, 8, 100, 6, 20, 10, 15};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, len);
    //bobble_sort(arr, len);
    //select_sort(arr, len);
    //quick_sort(arr, 0, len - 1);
    quick_sort2(arr, 0, len - 1);
    //quick_sort3(arr, 0, len - 1);
    //quick_sort_iteration(arr, 0, len - 1);
    print_arr(arr, len);
    return 0;    
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void print_arr(int *a, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }    
    printf("\n");
}
void bobble_sort(int *a, int len)
{

    int i, j;
    int change_flag = 1;//对冒泡排序优化
    for(i = 0; change_flag && i < len - 1; i++)
    {
        change_flag = 0;
        for(j = 0; j < len - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                change_flag = 1;
            }
        }
        
    }
}
void select_sort(int *a, int len)
{
    int i, j;
    int min_i;
    for(i = 0; i < len - 1; i++)
    {
        min_i = i;
        for(j = i; j < len; j++)
        {
            if(a[min_i] > a[j])// 如果当前最小值大于当前值
            {
                min_i = j; //find the min value
                //printf("current min value: %d \n", a[min_i]);
            }
        }   
        if(min_i != i)
        {
            swap(&a[i], &a[min_i]);
        }
        
        print_arr(a, len);
    }
}
//只单向移动
void quick_sort(int *a, int begin, int end) //以第一个元素为标准，把比它小的数据都放到它后边，放完之后把第一个元素的位置放到最后一个比它小的后边
{
    if(begin >= end )
    {
        return;
    }
    int key = a[begin];
    int save_index = begin + 1;
    int i = begin + 1;
    while(i <= end)
    {
        if(a[i] < key)
        {
            swap(&a[i], &a[save_index]);
            save_index++;
        }
        i++;
    }
    swap(&a[begin], &a[save_index - 1]);
    quick_sort(a, begin, save_index - 1);
    quick_sort(a, save_index, end);

}
//前后双向移动
void quick_sort2(int *a, int begin, int end)//挖坑填数  先从后往前把第一个小于key的值放到key原来的位置，再从前往后找大于key的值放到后边那个把值放进key原来位置的数那
{
    if(begin > end)
    {
        return;
    }
    int key = a[begin]; //将标准值记录
    int i = begin;
    int j = end;
    while(i < j)
    {
        while(j > i && a[j] >= key)
        {
            j--;
        }
        if(i < j)
        {
            a[i] = a[j]; 
            i++;
        }
        while(i < j && a[i] < key)
        {
            i++;
        }
        if(i < j)
        {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = key;//退出时i = j

    quick_sort2(a, 0, i - 1);
    //以参考值为分界线
    quick_sort2(a, i + 1, end);
}

//前后双向移动，移动完再交换值
void quick_sort3(int *a, int begin, int end)
{
    if(begin > end)
    {
        return ;
    }
    int i = begin;
    int j = end;
    int key = a[begin];
    while(i < j)
    {
        while((i < j) && (a[j] >= key))
        {
            j--;
        }
        while((i < j) && (a[i] <= key))
        {
            i++;
        }
        if(i < j)
        {
            swap(a + i, a + j);
        }
    }
    swap(a + begin, a + i); //将坑的值跟ij所在的位置交换

    quick_sort3(a, begin, i - 1);
    quick_sort3(a, i + 1, end);
}
////////////////////////////////////////////手动栈/////////////////////////
void stack_init()
{
    top = 0;
}
void push(int item)
{
    stack[top++] = item;
}
int pop()
{
    return stack[--top];
}
int is_empty()
{
    return top == 0;
}
#define MY_PUSH(a, b) push(b), push(a) //先入后出
void quick_sort_iteration(int *a, int begin, int end)
{
    int i;
    stack_init();
    MY_PUSH(begin, end);
    while(!is_empty())
    {
        begin = pop();
        end = pop();
        if(begin > end)
        {
            continue;
        }
        i = partition_left(a, begin, end);

        MY_PUSH(begin, i - 1);
        MY_PUSH(i + 1, end);
    }
}
int partition_left(int *a, int begin, int end)
{
    int i = begin;
    int j = end;
    int key = a[begin];
    while(i < j)
    {
        while(i < j && a[j] >= key)
        {
            j--;
        }
        while(i < j && a[i] <= key)
        {
            i++;
        }
        if(i < j)
        {
            swap(a + i, a + j);
        }
    }
    swap(a + begin, a + i); //将坑的值跟ij所在的位置交换
    return i;
}