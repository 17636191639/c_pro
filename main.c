#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����
struct Person
{
    char name[32];
    int age;
};

//���Ԫ�صĻص�����
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

//�ڵ�ṹ��
struct Node
{
    void *data;
    struct Node *next;
};

//����ṹ��
struct List
{
    struct Node *head;
    int size;
};

//��װ����������ṹ�尲ȫ
typedef void * LinkList;

/**
 * ��ʼ������
 * @return ����
 */
LinkList linkListInit()
{
    //����һ������
    struct List *list = (struct List *)malloc(sizeof(struct List));
    if(NULL == list)
    {
        return NULL;
    }

    list->head = (struct Node *)malloc(sizeof(struct Node));
    //��ʼ��ͷ�ڵ�ʹ�С
    list->head->data = NULL;
    list->head->next = NULL;
    list->size = 0;

    return list;
}

/**
 * �������Ԫ��
 * @param linkList Ҫ����������
 * @param data Ҫ������Ԫ��
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

    //����װ�������ԭ����
    struct List *list = (struct List *)linkList;
    printf("list size: %d\n", list->size);
    //����һ��ڵ�ռ�
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(NULL == node)
    {
        return;
    }

    //��������
    node->data = data;
    node->next = list->head;
    list->head = node;
    print(node->data);
    //���´�С
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
//    struct Person luwan = {16, "����¹��"};
//    struct Person chutian = {15, "�������"};
//    struct Person xiaoli = {16, "�����"};
//    struct Person tiantian = {16, "����"};

    appendLinkList(linkList, &xuanwo);
    //appendLinkList(linkList, &zuozhu);
//    appendLinkList(linkList, &luwan);
//    appendLinkList(linkList, &chutian);
//    appendLinkList(linkList, &xiaoli);
//    appendLinkList(linkList, &tiantian);

    foreachLinkList(linkList, print);


    ///////////////���ڵ����  sucess
    // struct Node test;
    // test.data = &xuanwo;
    // test.next = NULL;


    // struct Person *person = (struct Person *)test.data;
    // printf("name: %s\n age :%d\n", person->name, person->age);
    return 0;
}