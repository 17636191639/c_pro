#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int item;
    struct node *next;
}node;

node *head = NULL;

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
    p->next = head;
    head = p;
}

void insert_node_l2b(node *p)
{
    node *pre;

    if (head == NULL)
    {
        head = p;
        return;
    }

    if (p->item < head->item) 
    {
        p->next = head;
        head = p;
        return;
    }  

    pre = head;
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
    node *p = head;

    while (p->next != head)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

node *search_node(int target)
{
    node *p = head;

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

    if (head == NULL)
    {
        return;
    }

    if (head == p)
    {
        head = head->next;
        p->next = NULL;
        return;
    }

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
    node *nhead = head;
    head = NULL;

    while (nhead != NULL)
    {
        p = nhead;
        nhead = nhead->next;   
        //insert_node(p);
        p->next = head;
        head = p;
    }
}

void destroy()
{
    node *p;

    while (head != NULL)
    {
        p = head;
        head = head->next;
        free_node(p);
    }
}


void init(int n)
{
    node *r = NULL;
    int i = 1;

    head = mk_node(1);
    r = head;

    while (i < n)
    {
        r->next = mk_node(++i);
        r = r->next;
    }

    r->next = head; 
}

int josph(int n)
{
    int total = 1;
    int last;
    node *p;
    node *pre;
    
    init(n);
    pre = head;
    
    while (pre->next != pre)
    {
        total++;
        if (total == 3)
        {
            p = pre->next;
            pre->next = p->next;
            printf("%d ", p->item);
            free_node(p);
            total = 1;
        }

        pre = pre->next;
    }   
    printf("\n");

    last = pre->item;
    free_node(pre);

    return last;
}

int main()
{
    printf("the last is: %d\n", josph(5));
    return 0;
}
