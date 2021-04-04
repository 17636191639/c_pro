#include <stdio.h>
#include <stdlib.h>
//头节点链表
typedef struct node
{
    int data;
    struct node *next; 
}node;

node sentry = {0, NULL};
node *head = &sentry; //头节点
// void link_init()
// {
//     node *head = (node *)malloc(sizeof(node));
// }
node *mk_node(int item);
void insert_node(node *p);
void traverse();
void destory();
int rm_node(node *p);
node *search_node(int val);
int main()
{
    int i;
    node *rm = NULL;
    for(i = 0; i < 10; i++)
    {
        node *p = mk_node(i);
        insert_node(p);
        rm = p;
    }
    traverse();
    printf("find %d\n", search_node(5)->data);
    if(rm_node(rm))
    {
        printf("rm ok\n");
    }
    traverse();
    destory();

    return 0;
}
node *search_node(int val)
{
    node *p = head->next;
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
    node *pre = head;
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
    p->next = head->next;
    head->next = p;
}
void traverse()
{
    node *p = head->next;
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
    while(head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free(p);
    }

}