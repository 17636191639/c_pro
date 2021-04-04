#include <stdio.h>
#include <stdlib.h>
typedef int data_type;
#define QUE_SIZE 10

//ѭ������   ������������

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
    if((q->rear + 1) % QUE_SIZE == q->front)//��βָ������ǰ��һ��׷��ͷָ����Ƕ���
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
    q->queue[q->rear] = data;//�����ݷŵ���β
    printf("en queue data:%d \n", q->queue[q->rear]);
    q->rear = (q->rear + 1) % QUE_SIZE; //��βָ�����
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
/////////////////////////////////////ѭ������ʹ�ù��󻹿��Լ�������ʹ�ã� rear��ָ��λ��ʼ�ղ��ܷ����� 
//////////                      �ж϶ӿն���
//////��1. ����������һ��������ʾ��ǰ���д�Ŷ�����ЧԪ��
///////2. ����һ����־��ʾ��һ������ӻ��ǳ���

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