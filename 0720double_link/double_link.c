#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prior;
    int item;
    struct node *next;
}node;


node sentry = {NULL, 0, NULL};

node *head = &sentry;
node *pre = &sentry;

node *mk_node(int item)
{
    node *p =(node*) malloc(sizeof(node));
    if(p == NULL)
    {
        printf("malloc failed !\n");
        exit(1);
    }
    p->item = item;
    p->prior = NULL;
    p->next = NULL;
    return p;
}



void insert_node(node *p)
{
    if(head->next == NULL)
    {
        p->prior = head;
        p->next = head->next;
        head->next = p;
        pre = p;
        return;
    }
    p->prior = pre->prior;
    pre->prior = p;
    p->next = head->next;
    head->next = p;
    pre = p;
}

void free_node(node *p)
{
    free(p);
}

void traverse()
{
    node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->item);
        //printf("%d \n", p->prior->item);
        p = p->next;
    }
    printf("\n");
}

void traverse_rev()
{
    node *p = head->next;
    while (p->next != NULL)
    {
        //printf("%d ", p->item);
        //printf("%d \n", p->prior->item);
        p = p->next;
    }
    while(p->prior != NULL)
    {
        printf("%d ", p->item);
        p = p->prior;
    }
    printf("\n");
}

void destory()
{
    node *p = head;
    while(head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free_node(p);
    }
}

node *search_node(int target)
{
    node *p = head->next;

    while(p != NULL)
    {
        if(p->item == target)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void rm_node(node *p)
{
    node *pre_n = head;

    while (pre_n->next != NULL)
    {
        if(pre_n->next == p)
        {
            pre_n->next = p->next;
            if(p->next != NULL)
            {
                p->next->prior = p->prior;
            }

            return ;
        }
        pre_n = pre_n->next;
    }
}

int main()
{
    int i;
    node *p = NULL;
    int target;

    for (i = 0; i < 10; i++)
    {
        p = mk_node(i);
        insert_node(p);
    }
    traverse();
    //scanf("%d",&target);
    p = search_node(9);
    rm_node(p);
    traverse();
    traverse_rev();
    destory();
    return 0;
}
