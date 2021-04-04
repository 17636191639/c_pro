#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int item;
    struct node *left;
    struct node * right;
}node;

node *root = NULL;

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("insert_node:malloc failure\n");
        exit(1);
    }

    p->item = item;
    p->left = NULL;
    p->right = NULL;

    return p;    
}

void free_node(node *p)
{
    free_node(p);
}

#if 1
void insert_node(int item)
{
    node *pre;
    node *parent;
    node *p = mk_node(item);

    parent = pre = root;
    if (root == NULL)
    {
        root = p;
        return ;
    }
 
    while (pre != NULL)
    {
        parent = pre;
        if (item > pre->item)
        {
            pre = pre->right;
        }else if(item < pre->item)
        {
            pre = pre->left;
        }else
        {
            free_node(p);
            return;
        }
    }

    if (p->item > parent->item)
    {
        parent->right = p;
    }else
    {
        parent->left = p;
    }
}
#endif


void insert_node_r(node *current, node *p)
{
    if (p->item > current->item)
    {
        if (current->right == NULL)
        {
            current->right = p;
        }else
        {
            insert_node_r(current->right, p);     
        }
    }else if (p->item < current->item)
    {
        if (current->left == NULL)
        {
            current->left = p;
        }else
        {
            insert_node_r(current->left, p);         
        }
    }else
    {
        free_node(p);
    }
}
 
void insert_node(int item)
{
    node *p = mk_node(item);
    if (root == NULL)
    {
        root = p;
    }else
    {
        insert_node_r(root, p);   
    }
}

void traverse_m(node *p)
{
    if (p == NULL)
    {
        return ;
    }
    traverse_m(p->left);
    printf("%d ",p->item);
    traverse_m(p->right);
}

void traverse_b(node *p)
{
    if (p == NULL)
    {
        return ;
    }
    printf("%d ",p->item);
    traverse_b(p->left);
    traverse_b(p->right);
}

void traverse_a(node *p)
{
    if (p == NULL)
    {
        return ;
    }
    traverse_a(p->left);
    traverse_a(p->right);
    printf("%d ",p->item);
}

node *search_node(node *current, int item)
{
    if (item < current->item)
    {
        if (current->left == NULL)
        {
            return NULL;
        }
        return search_node(current->left,item);
    }else if(item > current->item)
    {
        if (current->right == NULL)
        {
            return NULL;
        }
        return search_node(current->right,item);
    }

    return current;
}

int main()
{
    insert_node(8);
    insert_node(4);
    insert_node(9);
    insert_node(13);
    insert_node(11);
    printf("中序遍历\n");
    traverse_m(root);
    printf("\n");
    printf("后序遍历\n");
    traverse_a(root);
    printf("\n");
    printf("前序遍历\n");
    traverse_b(root);
    printf("\n");
    int item ;
    printf("please input you item:\n");
    scanf("%d",&item);

    node *p = search_node(root,item);
    if (p != NULL)
    {
        printf("node:%p: item %d\n",p,p->item);
    }else
    {
        printf("can't find %d in this tree\n",item);
    }

}
