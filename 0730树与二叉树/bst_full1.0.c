#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct node
{
    int item;
    struct node *left;
    struct node *right;
}node;

/*需要用到的栈操作*/
node *stack[512];
int top = 0;

void init_stack()
{
    top = 0;
}

void push(node  *p)
{
    stack[top++] = p;
}

node  *pop(void)
{
    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}

node *root = NULL;

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    p->item = item;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void free_node(node *p)
{
    free(p);
}

//插入节点 （迭代法）
void insert_node_n(int item)
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

//插入节点（递归）
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

//中序遍历(递归)
void traverse_m(node *p)
{
    if (p == NULL)
    {
        return ;
    }

    traverse_m(p->left);
    printf("%d ", p->item);
    traverse_m(p->right);
}

//前序遍历（递归）
void traverse_b(node *p)
{
    if (p == NULL)
    {
        return ;
    }

    printf("%d ", p->item);
    traverse_b(p->left);
    traverse_b(p->right);
}

//后续遍历（递归）
void traverse_a(node *p)
{
    if (p == NULL)
    {
        return;
    }

    traverse_a(p->left);
    traverse_a(p->right);
    printf("%d ", p->item);
}

//先序遍历（迭代）
void pre_order_traverse()
{
    node *p = root;
    node *right;

    init_stack();

    if (root == NULL)
    {
        return;
    }

    do
    {
        printf("%d ", p->item);

        right = p->right;
        if (right != NULL)
        {
            push(right);
        }

        p = p->left;
        if (p == NULL)
        {
            p = pop();
        }

    }while(p != NULL);
}

//中序遍历（迭代）
void in_order_traverse()
{
    node *p = root;
    node *right;
    int is_empty_stack = 0;

    init_stack();

    if (root == NULL)
    {
        return;
    }

    do
    {
        while (p != NULL)
        {
            push(p);
            p = p->left;
        }

        if (!is_empty())
        {
            p = pop();
            printf("%d ", p->item);
            p = p->right;
        }
        else
        {
            is_empty_stack = 1;
        }
    }while(!is_empty_stack);
}

#define MAX_NODE  50

//后续遍历 （迭代）
void  post_order_traverse( )
{
    node *s1[MAX_NODE];   //保存结点指针
    node *p = root;
    int s2[MAX_NODE];     //S2保存结点的状态标志变量tag    0 ：结点暂不能访问  1 ： 结点可以被访问
    int top = 0;
    int is_empty_stack = 1;

    if (root == NULL)
    {
        printf("Binary Tree is Empty!\n") ;
        return;
    }

    do
    {
        while (p != NULL)
        {
            s1[++top] = p ;   //入栈
            s2[top] = 0 ;

            p = p->left ;

            is_empty_stack = 0;  //栈不空
        }

        //查看栈s1里是否有节点
        if  (top == 0)
        {
            is_empty_stack = 1;
        }
        else if (s2[top] == 0)    //如果栈顶的节点第一次被访问
        {
            p = s1[top]->right;
            s2[top] = 1 ;
        }
        else
        {
            //第二次访问该节点
            p = s1[top];
            top-- ;
            printf("%d ",  p->item);
            p = NULL;
        }
    }while (!is_empty_stack);

}

//层次遍历
void  level_order_traverse()
{
    node *queue[MAX_NODE];
    node *p = root;
    int front = 0;
    int rear = 0;

    if  (root == NULL)
    {
        printf("Binary Tree is Empty!\n") ;
        return;
    }

    queue[rear++] = p;

    while (front < rear)
    {
        p = queue[front++];

        printf("%d ", p->item);

        if (p->left != NULL)
        {
            queue[rear++] = p->left;    /*   左结点入队  */
        }

        if (p->right != NULL)
        {
            queue[rear++] = p->right;    /*   左结点入队  */
        }
    }
}

//求二叉树的叶子结点数
int search_leaves()
{
    node *p = root;
    node *right;
    int total  = 0;
    init_stack();

    if (root == NULL)
    {
        return 0;
    }

    do
    {
        if (p->left == NULL  && p->right == NULL)
        {
            total++;
        }

        right = p->right;
        if (right != NULL)
        {
            push(right);
        }

        p = p->left;
        if (p == NULL)
        {
            p = pop();
        }

    }while(p != NULL);

    return total;
}

//求二叉树的深度
int  search_depth()
{
    node  *queue[MAX_NODE];
    node *p = root;
    int front = 0;
    int rear = 0;
    int depth = 0;
    int level = 0;               /*level总是指向访问层的最后一个结点在队列的位置*/

    if  (root == NULL)
    {
        printf("Binary Tree is Empty!\n") ;
        return 0;
    }

    queue[rear++] = p;
    level = rear;

    while (front < rear)
    {
        p = queue[front++];

        if (p->left != NULL)
        {
            queue[rear++] = p->left;    /*   左结点入队  */
        }

        if (p->right != NULL)
        {
            queue[rear++] = p->right;    /*   左结点入队  */
        }

        /*  正访问的是当前层的最后一个结点  */
        if (front == level)
        {
            depth++;
            level = rear;
        }
    }

    return depth;
}

//二叉树的查找
node *search_node(node *current, int item)
{
    if (item < current->item)
    {
        if (current->left == NULL)
        {
            return NULL;
        }
        return search_node(current->left, item);
    }else if(item > current->item)
    {
        if (current->right == NULL)
        {
            return NULL;
        }
        return search_node(current->right, item);
    }

    return current;
}

void delete_node (int value)
{
    node *backfather;         //父结点指针
    node *ptr;                //删除结点指针
    node *next;               //子结点指针
    int pos;                  //删除位置

    backfather = root;          //设置父节点指针初值
    ptr = root;

    //查找值为value的结点
    if (root->item == value)
    {
        pos = 0;                //查寻到待删除的结点为根结点
    }else
    {
        while (ptr != NULL)
        {
            if (ptr->item == value)
            {
                break;
            }
            else
            {
                backfather = ptr;
                if (ptr->item > value)
                {
                    ptr = ptr->left;    //左子树
                    pos = -1;
                }
                else
                {
                    ptr = ptr->right;   //右子树
                    pos = 1;
                }
            }
        }
    }

    //没有找到值为value的结点
    if (backfather == NULL)
    {
        return ;
    }

    //删除叶子结点或左右子树不同时存在的结点
    if (ptr->left == NULL || ptr->right == NULL)
    {

        if (pos == 0)                	//如果需要删除的节点是根节点
        {
            if (root->right != NULL)
            {
                root = root->right;
            }else
            {
                root = root->left;
            }
        }else if (pos < 0)	    	    //如果删除的结点是左子结点
        {
            if (ptr->left != NULL)
            {
                backfather->left = ptr->left;
            }else
            {
                backfather->left = ptr->right;
            }
        }else				            //如果删除的节点是右子结点
        {
            if (ptr->left != NULL)
            {
                backfather->right = ptr->left;
            }else
            {
                backfather->right = ptr->right;
            }
        }

        free_node(ptr);

        return;
    }

    /*有左子树也有右子树的情况 */
    backfather = ptr;                   //父节点指向当前节点
    next = ptr->left;                   //设置子节点
    while (next->right != NULL)
    {
        backfather = next;
        next = next->right;
    }
    ptr->item = next->item;             //替换数据

    //把最右面的结点删除
    if (backfather->right == next)
    {
        backfather->right = next->left;
    }else if(backfather->left == next)
    {
        backfather->left = next->left;
    }
    
    //printf("del is %d\n", next->item);
    free_node(next);

    return;
}


//二叉树的销毁
void destroy_btree(node *p)
{
    if (p == NULL)
    {
        return ;
    }

    destroy_btree(p->left);
    destroy_btree(p->right);

    printf("node %2d is destroyed\n", p->item);
    free_node(p);
}

int main()
{
    int item;
#if 0
    insert_node(20);
    insert_node(10);
    insert_node(26);
    insert_node(6);
    insert_node(16);
    insert_node(24);
    insert_node(30);
    insert_node(3);
    insert_node(5);
    insert_node(8);
    insert_node(7);
    insert_node(12);
    insert_node(18);
    insert_node(22);
    insert_node(25);
    insert_node(28);
    insert_node(32);
#endif

#if 1
    insert_node(5);
    insert_node(2);
    insert_node(10);
    insert_node(3);
    insert_node(9);
    insert_node(20);
#endif

    printf("后序遍历\n");
    traverse_a(root);
    printf("\n");
    post_order_traverse();
    printf("\n");

    printf("前序遍历\n");
    traverse_b(root);
    printf("\n");

    pre_order_traverse();
    printf("\n");

    printf("中序遍历\n");
    traverse_m(root);
    printf("\n");

    in_order_traverse();
    printf("\n");

    level_order_traverse();
    printf("\n");

    printf("leaves have %d\n", search_leaves());
    printf("levels have %d\n", search_depth());

    printf("please input you item:\n");
    scanf("%d", &item);

    node *p = search_node(root, item);
    if (p != NULL)
    {
        printf("node:%p: item %d\n", p, p->item);
        delete_node(item);
        traverse_m(root);
        printf("\n");

    }else
    {
        printf("can't find %d in this tree\n",item);
    }

    destroy_btree(root);

    return 0;
}
