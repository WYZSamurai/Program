#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct elemtype{
    int data;
}elemtype;

typedef struct LNode
{
    elemtype data;
    struct LNode *next;
} node;

void list_initial_head(node &l, int n)
{
    //头插�?
    l.next = NULL;
    node *r;
    r = &l;
    for (int i = 0; i < n; i++)
    {
        node *p = (node *)malloc(sizeof(LNode));
        scanf("%d", &(p->data.data));
        r->next = p;
        r = r->next;
        r->next = NULL;
    }
}

void list_initial_end(node &l, int n)
{
    //尾插�?
    l.next = NULL;
    for (int i = 0; i < n; i++)
    {
        node *p = (node *)malloc(sizeof(LNode));
        scanf("%d", &(p->data.data));
        p->next = l.next;
        l.next = p;
    }
}

void list_print(node &l)
{
    node *p;
    p = &l;
    while (p->next)
    {
        p = p->next;
        printf("%d ", p->data.data);
    }
    printf("\n");
}

int getElem(node &l, int i, elemtype &e)
{
    int j = 1;
    node *p;
    p = l.next;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

int list_insert(node &l, int i, elemtype e)
{
    node *p;
    p = &l;
    int n = 1;
    while (p && n < i)
    {
        p = p->next;
        n++;
    }
    if (!p || n > i)
        return ERROR;
    node *t = (node *)malloc(sizeof(LNode));
    t->data = e;
    t->next = p->next;
    p->next = t;
    return OK;
}

int list_delete(node &l, int i, elemtype &e)
{
    int n = 1;
    node *p;
    p = &l;
    while (p && n < i)
    {
        p = p->next;
        n++;
    }
    if (!p || n > i)
        return ERROR;
    node *q;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}