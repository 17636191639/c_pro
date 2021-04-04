#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;

}node;

node *head = NULL;
node * tail = NULL;

node *mk_node(int value);
void traverse();
void insert_node(node *p);
node * search_node(int target);
void rm_node(node *p);
void free_node(node *p);
void destory();

int main()
{
    int i;
    node *p = NULL;
    int target;
    
    for (i = 0; i < 10; i++)
    {
        p = mk_node(i + 1);
        insert_node(p);
    }
    traverse();

    scanf("%d", &target);
    p = search_node(target);
    rm_node(p);
    destory();
    return 0;
}



void rm_node(node *p)
{
    node *pre = head;
    if(head == NULL)
    {
        return ;
    }

    if(p == head)
    {
        head = head->next;
        p->next = NULL;
        return ;
    }

    while(pre->next != head)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            printf("rm complete!\n");
            return ;
        }
        pre = pre->next;
    }
}

node * search_node(int target)
{
    node *p = head;
    while (p->next != head)
    {
        if(p->item == target)
        {
            printf("Find  %d ! \n",p->item);
            return p;
        }

        p = p->next;    
    }
    if(p->item == target)
    {
        printf("Find  %d ! \n",p->item);
        return p;
    }
    printf("can't find\n");
    return NULL;
}

void insert_node(node *p)
{
    

    if(head == NULL)
    {
        head = p;
        p->next = head;
        tail = head;
        return;
    }
    p->next = head;
    head = p;
    tail ->next = head;

}

void traverse()
{
    node *p = head;
    if(head == NULL)
    {
        printf("NULL link!\n");
        return;
    }
    while(p->next != head)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("%d ", p->item);
    printf("\n");    
}

node *mk_node(int value)
{
    node *p = (node *)malloc(sizeof(node));

    if ( p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    } 

    p -> item = value;
    p -> next = NULL;

    return p;
}

void free_node(node *p)
{
    free(p);
}

void destory()
{
    node *p;

    while(head != tail)
    {
        p = head;
        head = head->next;
        free_node(p);
    }
    free_node(tail);
}




