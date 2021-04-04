#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prior;
    int data;
    struct node *next; 
};
struct node sentry = {NULL, 0, NULL}; ///头节点
struct node *head = &sentry;
struct node *mk_node(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node)); 
    if(p == NULL)
    {
        printf("malloc failed!\n");
        exit(1);
    }
    p->prior = NULL;
    p->data = data;
    p->next = NULL;
    return p;
}
void insert_after_head(struct node *p)
{
    if(head->next == NULL)
    {
        p->next = head->next;
        head->next = p;
        p->prior = head;
        return;
    }
    head->next->prior = p;
    p->next = head->next;
    head->next = p;
    p->prior = head;
    
}
void traverse()
{
    struct node *p = head->next;
    while(p != NULL)
    {
        printf("%d, \n", p->data);
        printf("prior->data: %d, \n", p->prior->data);
        p = p->next;
    }
    printf("\n");
}
void traverse_rev()
{
    struct node *p = head->next;
    while(p->next != NULL)//先让p跑到最后一个结点
    {
        p = p->next;
    }
    while(p->prior != NULL)
    {
        printf("%d, ", p->data);
        p = p->prior;
    }
}

int main()
{

    int i;
    for(i = 0; i < 10; i++)
    {
        struct node *p = mk_node(i);
        insert_after_head(p);
    }
    traverse();
    traverse_rev();
    return 0;
}