//非递归算法实现二路归并排序，length代表数组长度，即数组最大下标是 legth - 1
void mergeSort(int List[],int length)
{
    //回忆图解的过程，二路归并算法的流程，不同于递归，递归是先递归语句，然后归并函数，这样归并函数是倒序执行（和递归函数执行顺序相反）
    int size = 1;
    int low;
    int mid;
    int high;
    //size 是标记当前各个归并序列的high-low，从1，2，4，8，……，2*size
    while(size <= length - 1)
    {
        //从第一个元素开始扫描，low代表第一个分割的序列的第一个元素
        low = 0;
        //当前的归并算法结束的条件
        while(low + size <= length - 1)
        {
            //mid代表第一个分割的序列的最后一个元素
            mid = low + size - 1;
            //high 代表第二个分割的序列的最后一个元素
            high = mid + size;
            //判断一下：如果第二个序列个数不足size个
            if(high > length - 1){
                //调整 high 为最后一个元素的下标即可
                high = length - 1;
            }
            //调用归并函数，进行分割的序列的分段排序
            merge(List, low, mid, high);
            //打印出每次归并的区间
            cout << "low:" << low << " mid:" << mid << " high:" << high << endl;
            //下一次归并时第一序列的第一个元素位置
            low = high + 1;
        }// end of while
        //范围扩大一倍，二路归并的过程
        size *= 2;
    }// end of while
}

int main()
{
    int arr[] = {22, 33, 44, 11, 8, 9, 55, 77, 15, 28, 88, 99,
    22, 33, 44, 11, 8, 9, 55, 77, 15, 28, 88,22, 33, 44, 11, 8, 
    9, 55, 77, 15, 28, 88, 99,22, 33, 44, 11, 8, 9, 55, 77, 15, 28,
     88,22, 33, 44, 11, 8, 9, 55, 77, 15, 28, 88, 99};
    int len = (int)sizeof(arr) / sizeof(*arr);
    int i;
    merge_sort(arr, len);
    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return(0);
}