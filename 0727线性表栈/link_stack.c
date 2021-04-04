#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int item;
    struct node *next;
}node;

node *head = NULL;

node *mk_node(int item)
{
    node *p =(node *) malloc(sizeof(node));
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

void traverse()
{
    node *p = head;

    while (p != NULL)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

node * search_node(int item)
{
    node *p = head;

    while (p != NULL)
    {
        if (p->item == item)
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

void reverse()
{
    node *p;
    node *nhead = NULL;

    while (head != NULL)
    {
        p = head;
        head = head->next;
        
        p->next = nhead;
        nhead = p;
    }

    head = nhead;
}


void push(int item)
{
    node *p = mk_node(item);
    insert_node(p);
}

int is_empty()
{
    return head == NULL;
}

int pop()
{
    int item;
    node *p = head;
    head = head->next;
    p->next = NULL;

    item = p->item;
    free_node(p);

    return item;
}

int main()
{
    push(1);
      push(2);
        push(3);
          push(4);
            push(5);
              push(6);
                push(7);
                while(!is_empty())
                {
                    printf("%d\n", pop());
                }

    return 0;
}
