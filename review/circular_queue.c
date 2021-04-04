#include <stdio.h>
#include <stdlib.h>
typedef int data_type;
#define QUE_SIZE 10

//循环队列   解决假溢出现象

typedef struct queue
{
    data_type queue[QUE_SIZE];
    data_type front;
    data_type rear;

}queue;
void queue_init(queue *q)
{
    q->front = q->rear = 0;
}
int is_empty(queue *q)
{
    if(q->front == q->rear)
    {
        return 1;
    }
    return 0;
}
int is_full(queue *q)
{
    if((q->rear + 1) % QUE_SIZE == q->front)//队尾指针再往前跑一下追上头指针就是队满
    {
        return 1;
    }
    return 0; 
  
}
int en_queue(queue *q, data_type data)
{
    if(is_full(q))
    {
        return 0;
    }
    q->queue[q->rear] = data;//将数据放到队尾
    printf("en queue data:%d \n", q->queue[q->rear]);
    q->rear = (q->rear + 1) % QUE_SIZE; //队尾指针后移
    return 1;
}
int de_queue(queue *q, data_type *data) 
{
    if(is_empty(q))
    {
        return 0;
    }
    *data = q->queue[q->front];
    q->front = (q->front + 1) % QUE_SIZE;
    return 1;
}
int main()
{
    queue q;
    queue_init(&q);
    int i = 0;
    for(i = 0; i < 20; i++)
    {
        if(!en_queue(&q, i))
        {
            printf("en queue failed!\n");
            break;
        }
    }
    for(i = 0; i < 20; i++)
    {
        int data;
        if(de_queue(&q, &data))
        {
            printf("de_queue data: %d\n", data);
        }
        
    }
/////////////////////////////////////循环链表使用过后还可以继续重新使用， rear所指的位置始终不能放数据 
//////////                      判断队空队满
//////‘1. 还可以设置一个变量表示当前队列存放多少有效元素
///////2. 设置一个标志表示上一次是入队还是出队

    for(i = 10; i < 20; i++)
    {
        if(!en_queue(&q, i))
        {
            printf("en queue failed!\n");
            break;
        }
    }
    for(i = 0; i < 20; i++)
    {
        int data;
        if(de_queue(&q, &data))
        {
            printf("de_queue data: %d\n", data);
        }
        
    }
    return 0;
}