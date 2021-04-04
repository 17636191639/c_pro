#include <stdio.h>
#include <stdlib.h>

typedef struct ploy
{
    int expn;
    float coef;
    struct ploy* next;
}ploy;

ploy sentry1 = {0, 0, NULL};
ploy sentry2 = {0, 0, NULL};
ploy sentry3 = {0, 0, NULL};

ploy *head1 = &sentry1;
ploy *head2 = &sentry2;
ploy *head3 = &sentry3;

ploy *mk_ploy(int expn, int coef)
{
    ploy *p = (ploy *)malloc(sizeof(ploy));

    if(p == NULL)
    {
        printf("malloc failed!");
        exit(1);
    }

    p->expn = expn;
    p->coef = coef;
    p->next = NULL;

    return p;
}


void insert_ploy(ploy *p, ploy *head)
{
    if(p->coef == 0)
    {
        free(p);
        return ;
    }
    p->next = head->next;
    head->next = p;

}
void free_ploy(ploy *p)
{
    free(p);
}

void traverse(ploy *head)
{
    ploy *p = head->next;

    while (p != NULL)
    {
        printf("%.1fx^%d  ",p->coef, p->expn);
        p = p->next;
    }
    printf("\n");
}

void rm_ploy(ploy *p, ploy *head)
{
    ploy *pre = head;

    while (pre->next != NULL)
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
void put_ploy(ploy *p, ploy *head)
{
    ploy *dest = head->next;
    ploy *tmp = NULL;

    if(p->coef == 0)
    {
        return;
    }

    while(dest != NULL)
    {
        if(dest->expn == p->expn)
        {
            dest->coef += p->coef;
            //add after == 0 ..... .. .. . . .. 
            if(dest->coef == 0)
            {
                rm_ploy(dest, head);
            }
            return;
        }
        dest = dest->next;
    }

    tmp = mk_ploy(p->expn, p->coef);
    insert_ploy(tmp, head);

}

void add_ploy(ploy *ploy1,ploy *ploy2, ploy *ploy3)
{
    ploy *p1 = ploy1->next;
    ploy *p2 = ploy2->next;

    while(p1 != NULL)
    {
        put_ploy(p1, ploy3);
        p1 = p1->next;
    }
    while(p2 != NULL)
    {
        put_ploy(p2, ploy3);
        p2 = p2->next;
    }

}

void destory (ploy *head)
{
    ploy *p;

    while (head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free_ploy(p);
    }
}

int main()
{
    int i;
    ploy *p = NULL;

    for(i = 0; i < 10; i++)
    {
        p = mk_ploy(i, i);
        insert_ploy(p, head1);
    }

    for(i = 1; i > -10; i--)
    {
        p = mk_ploy(abs(i), i);
        insert_ploy(p, head2);
    }

    add_ploy(head1, head2, head3);

    traverse(head1);
    traverse(head2);
    traverse(head3);
    destory(head1);
    destory(head2);
    destory(head3);
    return 0;
}
