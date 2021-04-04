#include <stdio.h>
#include <stdlib.h>
//链表队列    内存足够的情况下无限插入
//一个头指针一个尾指针
//入队在表尾进行
//出队在表头进行
typedef struct node
{
    int data;
    struct node *next; 
}node;

node sentry = {0, NULL};
node *front = &sentry; //队列头指针
node *rear = &sentry;  //队列尾指针


node *mk_node(int item);
void insert_node(node *p);
void traverse();
void destory();
int rm_node(node *p);
node *search_node(int val);
int is_empty();
int de_queue();
void en_queue(node *p);
int main()
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        node *p = mk_node(i);
        en_queue(p);
    }
    while(!is_empty())
    {
        printf("de_queue: %d\n", de_queue());
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////
int de_queue()
{
    if(!is_empty())
    {
        node *p = front->next;
        int tmp = p->data;
        front->next = p->next;
        free(p);
        return tmp;
    }
    
}
void en_queue(node *p) /////队尾插入   rear一直指向队尾
{
    rear->next = p;
    rear = p;
}
int is_empty()
{
    return front->next == NULL;
}
/////////////////////////////////////////////////////////////////////////////////


node *search_node(int val)
{
    node *p = front->next;
    while(p != NULL)
    {
        if(p->data == val)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int rm_node(node *p)
{
    node *pre = front;
    while(pre->next != NULL)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            free(p);
            return 1;
        }
        pre = pre->next;
    }
    return 0;
}
node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    p->data = item;
    p->next = NULL;

    return p;
}
void insert_node(node *p)
{
    p->next = front->next;
    front->next = p;
}
void traverse()
{
    node *p = front->next;
    while(p != NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}
void destory()
{
    node *p = NULL;
    while(front->next != NULL)
    {
        p = front->next;
        front->next = p->next;
        free(p);
    }

}