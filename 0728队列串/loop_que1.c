#include <stdio.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = 0;
int rear = 0; 

int is_empty()
{
    return front == rear;
}

int is_full()
{
    return (rear  + 1) %QUEUE_SIZE == front;
}

void enqueue(int data)
{
    if (!is_full())
    {
        queue[rear++] = data;
        rear %= QUEUE_SIZE;
    }   
}

int dequeue()
{
    int data = queue[front++];
    front %= QUEUE_SIZE;
    return data;
}

int main()
{
    int i;

    for (i = 0; i < 2; i++)
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