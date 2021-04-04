#include <stdio.h>
#include <stdlib.h>
typedef int data_type;
#define QUE_SIZE 5
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
    return (q->rear == QUE_SIZE);
  
}
int en_queue(queue *q, data_type data)
{
    if(is_full(q))
    {
        return 0;
    }
    q->queue[q->rear++] = data;
    return 1;
}
int de_queue(queue *q, data_type *data) 
{
    if(is_empty(q))
    {
        return 0;
    }
    *data = q->queue[q->front++];
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
    for(i = 0; i < 10; i++)
    {
        int data;
        if(de_queue(&q, &data))
        {
            printf("de_queue data: %d\n", data);
        }
        
    }
////////////////////////////////////////当数据的空间全被使用过后，就不能再重新使用了
    for(i = 6; i < 10; i++)
    {
        if(!en_queue(&q, i))
        {
            printf("en queue failed!\n");
            break;
        }
    }
    for(i = 6; i < 10; i++)
    {
        int data;
        if(de_queue(&q, &data))
        {
            printf("de_queue data: %d\n", data);
        }
        
    }
    return 0;
}