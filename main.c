#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//人类
struct Person
{
    char name[32];
    int age;
};

//输出元素的回调函数
void print(void *persons)
{
    struct Person *person = (struct Person *)persons;
    printf("name: %s\n age: %d\n", person->name, person->age);
}

int compare(void *person1, void *person2)
{
    struct Person *person11 = (struct Person *)person1;
    struct Person *person22 = (struct Person *)person2;

    if((person11->name == person22->name) && (person11->age == person22->age))
    {
        return 1;
    }

    return 0;
}

//节点结构体
struct Node
{
    void *data;
    struct Node *next;
};

//链表结构体
struct List
{
    struct Node *head;
    int size;
};

//封装，保护链表结构体安全
typedef void * LinkList;

/**
 * 初始化链表
 * @return 链表
 */
LinkList linkListInit()
{
    //申请一块链表
    struct List *list = (struct List *)malloc(sizeof(struct List));
    if(NULL == list)
    {
        return NULL;
    }

    list->head = (struct Node *)malloc(sizeof(struct Node));
    //初始化头节点和大小
    list->head->data = NULL;
    list->head->next = NULL;
    list->size = 0;

    return list;
}

/**
 * 链表加入元素
 * @param linkList 要操作的链表
 * @param data 要操作的元素
 */
void appendLinkList(LinkList linkList, void *data)
{
    if(NULL == linkList)
    {
        return;
    }

    if(NULL == data)
    {
        return;
    }

    //将封装后的链表还原回来
    struct List *list = (struct List *)linkList;
    printf("list size: %d\n", list->size);
    //申请一块节点空间
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(NULL == node)
    {
        return;
    }

    //插入数据
    node->data = data;
    node->next = list->head;
    list->head = node;
    print(node->data);
    //更新大小
    ++list->size;
    printf("list size : %d\n", list->size);
}

void deleteLinkList(LinkList linkList, void *data, int (*compare)(void *, void *))
{
    if(NULL == linkList)
    {
        return;
    }

    if(NULL == data)
    {
        return;
    }

    struct List *list = (struct List *)linkList;
    struct Node *lastNode = list->head;

    for(int i = 0; i < list->size; ++i)
    {
        if(compare(data, list->head))
        {
            struct Node *node = list->head;
            list->head = list->head->next;
            free(node);
            node = NULL;
            return;
        }

        if(compare(data, lastNode->next))
        {
            struct Node *node = lastNode->next;
            lastNode->next = lastNode->next->next;
            free((node));
            node = NULL;
            return;
        }

        lastNode = lastNode->next;
    }
}

void foreachLinkList(LinkList linkList, void (*print)(void *))
{
    if(NULL == linkList)
    {
        return;
    }

    struct List *list = (struct List *)linkList;
    struct Node *node = list->head;

    for(int i = 0; i < list->size; ++i)
    {
        print(node);
        node = node->next;
    }
}

int main(int argc, char *argv[])
{
    LinkList linkList = linkListInit();

    struct Person xuanwo = {"xuanwo", 16};
    //struct Person zuozhu = {"zuozhu", 17};
//    struct Person luwan = {16, "奈良鹿丸"};
//    struct Person chutian = {15, "日向雏田"};
//    struct Person xiaoli = {16, "李洛克"};
//    struct Person tiantian = {16, "天天"};

    appendLinkList(linkList, &xuanwo);
    //appendLinkList(linkList, &zuozhu);
//    appendLinkList(linkList, &luwan);
//    appendLinkList(linkList, &chutian);
//    appendLinkList(linkList, &xiaoli);
//    appendLinkList(linkList, &tiantian);

    foreachLinkList(linkList, print);


    ///////////////单节点测试  sucess
    // struct Node test;
    // test.data = &xuanwo;
    // test.next = NULL;


    // struct Person *person = (struct Person *)test.data;
    // printf("name: %s\n age :%d\n", person->name, person->age);
    return 0;
}