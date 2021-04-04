#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}node;
node sentry = {0, NULL};
node *head = &sentry;

void list_init()
{
    head->next = head;
}
node *mk_node(int data)
{
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        printf("malloc error\n");
        exit(1);
    }
    p->data = data;
    p->next = NULL;
    return p;
}
void insert_after_pos(node *pos, node *p)
{
    p->next = pos->next;
    pos->next = p;
}
node *search_node(int val)
{
    node *p = head->next;
    while(p != head)
    {
        if(p->data == val)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
node* find_pre(node *p)
{
    node *f = head;
    while(f->next != head)
    {
        if(f->next == p)
        {
            return f;
        }
        f = f->next;

    }
    return NULL;
}
void rm_node(node *pre, node *p)
{

    pre->next = p->next;
    p->next = NULL;
    free(p);
}
void destory()
{
    if(head->next == NULL)
    {
        return ;
    }
    node *p = head->next;
    while(p != head)
    {
        node *next = p->next;
        p->next = NULL;
        free(p);
        p = next;
    }
}
void traverse()
{
    node *p = head->next;
    while(p != head)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}
void jos_link(int total, int num);//约瑟夫环
//循环链表
int main()
{

    jos_link(5, 3);


    // int i ;
    // list_init();
    // for(i = 0; i < 10; i++)
    // {
    //     node *p = mk_node(i);
    //     insert_after_pos(head, p);
    // }
    // traverse();
    // node *p = NULL;  
    // if((p = search_node(5)) != NULL)
    // {
        
    //     rm_node(find_pre(p), p);
    //     printf("find \n");
    // }
    // traverse();
    return 0;
}
void jos_link(int total, int num)//约瑟夫环
{
    int i;
    destory();//刚开始先释放链表防止链表里边有结点
    list_init();
    head->data = 0; // 头节点里边放链表长度
    for(i = total; i > 0; i--)
    {
        node *p = mk_node(i);
        insert_after_pos(head, p);
        head->data++;
    }
    node *p = head->next;
    i = 1;
    while(head->data != 1)
    {
        if(p == head)
        {
            p = p->next;
            continue;
        }
        if(i % num == 0)
        {
            printf("kill %d\n", p->data);
            node *pre = find_pre(p);
            rm_node(pre, p);
            head->data--;
            p = pre;
        }
        p = p->next;
        i++;
        traverse();
    }
    traverse();
    destory();

}
