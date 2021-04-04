#include <stdio.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = 0;
int rear = 0; 
int is_enque = 0;

int is_empty()
{
    return front == rear && is_enque == 0;
}

int is_full()
{
    return rear == front  && is_enque == 1 ;
}

void enqueue(int data)
{
    if (!is_full())
    {
        is_enque = 1;
        queue[rear++] = data;
        rear %= QUEUE_SIZE;
    }   
}

int dequeue()
{
    is_enque = 0;
    int data = queue[front++];
    front %= QUEUE_SIZE;
    return data;
}

int main()
{
    int i;

    for (i = 0; i < 9; i++)
    {
        enqueue(i);
    }

    while (!is_empty())
    {
        printf("%d\n", dequeue());
    }

    for (i = 5; i < 10; i++)
    {
        enqueue(i);
    }

    while (!is_empty())
    {
        printf("%d\n", dequeue());
    }

    return 0;
}