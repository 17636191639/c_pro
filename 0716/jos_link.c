#include <stdio.h>
#include <stdlib.h>

#define N 9

typedef struct node
{
    int item;
    struct node *next;
}node;

node *head = NULL;

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }
    p->item = item;
    p->next = NULL;
    return p;
}

node *freenode(node *p)
{
    free(p);
}

void insert_node(node *p)
{
    p->next = head;
    head = p;
}

void insert_node_l2b(node *p)
{
    node *pre = head;

    if(pre == NULL)
    {
        head = p;
        return;
    }
    if(p->item <= head->item)
    {
        insert_node(p);
        return;
    }
    while (pre->next != NULL)
    {
        if(p->item <= pre->next->item)
        {
            break;
        }
        pre = pre->next;
    }
    p->next = pre->next;
    pre->next = p;

}

void traverse()
{
    node *p = head;
    while(p != NULL)
    {
        printf("%d ",p->item);
        p = p->next;
    }
    printf("\n");
}

void destory()
{
    node *p = head;
    while (p != NULL)
    {
        freenode(p);
        p = p->next;
    }
}


void rm_node(node *p)
{
    node *pre = head;
    if(p == NULL)
    {
        return ;
    }
    if(p == head)
    {
        head = head->next;
        p = NULL;
        return;
    }
    while (pre != NULL)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p = NULL;
            return ;
        }
        pre = pre->next;
    }
}

void my_jos()
{
    node *p = head;
    node *pre = head;
    int i = 1;
    int num = N;
    node *free ;

    while (p != NULL)
    {
        if(p->next == NULL)
        {
            p->next = head;
            break;
        }
        p = p->next;
    }
    while(num > 1)
    {
        if(i == 2)
        {
            printf("kill:%d \n",pre->next->item);
            free = pre->next;
            pre->next = pre->next->next;
            freenode(free);
            i = 0;
            num--;
        }
        i++;
        pre = pre->next;
    }
    pre->next = NULL;
    printf("survivor:%d\n",pre->item);
}

int main()
{
    int i;
    node *p;
    for(i = 0; i < N; i++)
    {
        p = mk_node(i+1);
        insert_node_l2b(p);
    }
    traverse();
    my_jos();
    destory();
    return 0;
}
