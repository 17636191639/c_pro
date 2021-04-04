#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL; //定义一个全局得头指针

void free_node(node *p);
node *mk_node(int data);
int rm_node(node *p);
void insert_node(node *p);
void traverse();
void destory();
void rev_link(); //翻转整个链表

int main()
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        node *p = mk_node(i);
        insert_node(p);
    }
    traverse();
    //printf("find it : %d\n",search_node(5)->data);
    // if(rm_node(head))
    // {
    //     printf("rm ok\n");
    // }
    rev_link();
    traverse();
    destory();
    return 0;
}

void rev_link() //翻转整个链表
{
    node *p = head;
    node *p_next = NULL;
    node *pre = NULL;
    while(p != NULL)
    {
        
        p_next = p->next;//记录p的next
        p->next = pre;//将p->next指向前端结点
        pre = p;//记录p
        p = p_next;  //让p指向原来的next
    }
    head = pre;
}


node *mk_node(int data)
{
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        printf("malloc failed! \n");
        exit(1);
    }
    p->data = data;
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
    while(head != NULL)
    {
        p = head;
        head = head->next;
        free_node(p);
    }
}
node *search_node(int data)
{
    node *p = head;
    while(p != NULL)
    {
        if(p->data == data)
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
    if(head == NULL)
    {
        return 0;
    }
    if(head == p)
    {
        head = head->next;
        free_node(p);
        return 1;
    }
    while(pre->next != NULL)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            free_node(p);
            return 1;
        }
        pre = pre->next;
    }
    return -1;
}