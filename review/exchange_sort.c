#include <stdio.h>
int stack[512];//�Խ�ջ
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
    int change_flag = 1;//��ð�������Ż�
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
            if(a[min_i] > a[j])// �����ǰ��Сֵ���ڵ�ǰֵ
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
//ֻ�����ƶ�
void quick_sort(int *a, int begin, int end) //�Ե�һ��Ԫ��Ϊ��׼���ѱ���С�����ݶ��ŵ�����ߣ�����֮��ѵ�һ��Ԫ�ص�λ�÷ŵ����һ������С�ĺ��
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
//ǰ��˫���ƶ�
void quick_sort2(int *a, int begin, int end)//�ڿ�����  �ȴӺ���ǰ�ѵ�һ��С��key��ֵ�ŵ�keyԭ����λ�ã��ٴ�ǰ�����Ҵ���key��ֵ�ŵ�����Ǹ���ֵ�Ž�keyԭ��λ�õ�����
{
    if(begin > end)
    {
        return;
    }
    int key = a[begin]; //����׼ֵ��¼
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
    a[i] = key;//�˳�ʱi = j

    quick_sort2(a, 0, i - 1);
    //�Բο�ֵΪ�ֽ���
    quick_sort2(a, i + 1, end);
}

//ǰ��˫���ƶ����ƶ����ٽ���ֵ
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
    swap(a + begin, a + i); //���ӵ�ֵ��ij���ڵ�λ�ý���

    quick_sort3(a, begin, i - 1);
    quick_sort3(a, i + 1, end);
}
////////////////////////////////////////////�ֶ�ջ/////////////////////////
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
#define MY_PUSH(a, b) push(b), push(a) //������
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
    swap(a + begin, a + i); //���ӵ�ֵ��ij���ڵ�λ�ý���
    return i;
}