#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int item;
    struct node*next;
}node;

node *head = NULL;

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

void traverse()
{
    node *p = head;
    while ( p != NULL)
    {
        printf("%d ",p->item );
        p = p->next;
    }
    printf("\n");
}

void insert_node(node*p)
{
    p->next = head;
    head = p;
}

void rm_node_content(int num)
{
    node *p = head;
    node *pre = head;
    if(head->item == num)
    {
        head = head->next;

    }

    while (pre->next != NULL)
    {
        if (pre->next->item == num)
        {
            pre->next = pre->next->next;

        }else
        {
            pre = pre->next;
        }
        
    }
}

void rm_sm_node()
{
    node *sm = head;
    node *pre = head->next;

    while (pre != NULL)
    {
        if (pre->item < sm->item)
        {
            sm = pre;
        }
        pre = pre->next;
    }
    //printf("%d  ",sm->item);
    rm_node_content(sm->item);
}

int main ()
{
    int i;
    node *p;
    int target;
    srand(time(NULL));
    for(i = 0; i < 10;i++)
    {
        p = mk_node(rand() % 100 + 1);
        insert_node(p);
    }
    traverse();
    rm_sm_node();
    // scanf("%d",&target);
    // rm_node_content(target);
    traverse();
    return 0;
}
