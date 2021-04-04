#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node 
{
    int item;
    struct node *next;
}node;

node sentry = {0, NULL};
node *head = &sentry;

node *mk_node(int num);
void free_node(node *p);

void insert_node(node *p);
void traverse();
node *search_node(int target);

void rm_node(node *p);
void destory ();
void link_rev();
void insert_node_l2b(node *p);

void init()
{
    head->next = head;    
}

int main()
{
    srand(time(NULL));
    int i;
    node *p;
    init();
    int target;

    for(i = 0; i < 10; i++)
    {
        p = mk_node(rand() % 100 + 1);
        insert_node_l2b(p);

    }
    link_rev();
    traverse();
    destory();
    return 0;
}

void insert_node_l2b(node *p)
{
    node *pre = head;
    while(pre->next != head)
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

node *mk_node(int num)
{
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }
    p->item = num;
    p->next = NULL;
    return p;
}

void free_node(node *p)
{
    free(p);
}

void insert_node(node *p)
{
    p->next = head->next;
    head->next = p;
}

void traverse()
{
    node *p = head->next;

    while (p != head)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

node *search_node(int target)
{
    node *p = head->next;

    while(p != head)
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
    node *pre = head;
    
    while (pre->next != head)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            return ;
        }
        pre = pre->next;
    }
}

void destory ()
{
    node*p;

    while (head->next != head)
    {
        p = head->next;
        head->next = p->next;
        free_node(p);
    }
}

void link_rev()
{
    node *p;
    node *nhead = head->next;
    head->next = head;

   while(nhead != head)
   {
        p = nhead;
        nhead = nhead->next;
        p->next = NULL;
        insert_node(p);

   }
}
