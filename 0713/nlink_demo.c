#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int item;
    struct node *next;
}node;

node  sentry = {0, NULL};
node *head = &sentry;

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    p->item = item;
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

void insert_node_l2b(node *p)
{
    node *pre = head;

    while (pre->next != NULL)
    {
        if (p->item <= pre->next->item)
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
    node *p = head->next;

    while (p != NULL)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

node *search_node(int target)
{
    node *p = head->next;

    while (p != NULL)
    {
        if (p->item == target)
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

    while (pre->next != NULL)
    {
        if (pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            return;
        }

        pre = pre->next;
    }
}

void reverse()
{
    node *p;
    node *nhead = head->next;
    head->next = NULL;

    while (nhead != NULL)
    {
        p = nhead;
        nhead = nhead->next;  
        p->next = NULL; 
        insert_node(p);
    }
}

void destroy()
{
    node *p;

    while (head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free_node(p);
    }
}

int main()
{
    int target;
    node *p;
    int i;
    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        p = mk_node(rand() % 100 + 1);
        insert_node_l2b(p);
    }
    
    traverse();
    scanf("%d", &target);
    p = search_node(target);
    if (p == NULL)
    {
        printf("Can't find %d\n", target);
    }else
    {
        printf("%p %d %d\n", p, p->item, target);
        rm_node(p);
        free_node(p);
        p = NULL;
        traverse();
        reverse();
        traverse();
    }

    destroy();
    traverse();

    return 0;
}
