#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *next;
    char val[20];
} LinkList;

LinkList *node, *head, *tail, *heads, *tails;

LinkList *init(char arr[])
{
    LinkList *node = (LinkList *)malloc(sizeof(LinkList));
    node->next = NULL;
    strcpy(node->val, arr);
    return node;
}

int a, b;

void man()
{
    head = NULL;
    printf("�ж�:\n��������������:");
    scanf("%d", &a);
    printf("���������ߵ�����: ");
    char name[20];
    int times = a;
    while (times--)
    {
        scanf("%s", name);
        node = init(name);
        if (!head)
        {
            head = node;
            head->next = head;
            tail = head;
        }
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
    node = head;
}

void woman()
{
    heads = NULL;
    printf("Ů��:\n��������������:");
    scanf("%d", &b);
    printf("���������ߵ�����: ");
    char name[20];
    int times = b;
    while (times--)
    {
        scanf("%s", name);
        node = init(name);
        if (!heads)
        {
            heads = node;
            heads->next = heads;
            tails = heads;
        }
        node->next = tails->next;
        tails->next = node;
        tails = node;
    }
    node = heads;
}

int main()
{
    man();
    woman();
    int x;
    printf("��������������: \n");
    scanf("%d", &x);
    LinkList *p1, *p2;
    p1 = head;
    p2 = heads;
    int times = a > b ? b : a;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < times; j++)
        {
            if (p1 && p2)
                printf("��Ե�����: %s %s\n", p1->val, p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        if (a - b == 0)
            printf("ȫ��������\n");
        else if (a - b > 0)
            printf("��һ��������δ������ߵ�����: %s\n", p1->val);
        else if (a - b < 0)
            printf("��һ��������δ������ߵ�����: %s\n", p2->val);
    }
}