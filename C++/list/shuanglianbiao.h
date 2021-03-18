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
    struct LNode *head;
    struct LNode *next;
} node;

void list_create(node &l, int n)
{
    l.head = NULL;
    l.next = NULL;
    node *t;
    t = &l;
    for (int i = 0; i < n; i++)
    {
        node *p = (node *)malloc(sizeof(LNode));
        scanf("%d", &(p->data.data));
        t->next = p;
        p->head = t;
        t = t->next;
        t->next = NULL;
    }
}

void list_print(node &l)
{
    node *p;
    p = l.next;
    node *t;
    t = p;
    while (p)
    {
        printf("%d ", p->data.data);
        t = p->head;
        p = p->next;
        //printf("%d\n", t->data);
    }
    printf("\n");
}

node *GetElem(node &l, int i)
{
    node *p;
    p = l.next;
    int n = 1;
    while (p && n < i)
    {
        p = p->next;
        n++;
    }
    // if(!p || n > i)return ERROR;
    return p;
}

int list_insert(node &l, int i, elemtype e)
{
    node *p;
    p = GetElem(l, i);
    if (!p)
        return ERROR;
    node *s;
    s = (node *)malloc(sizeof(LNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->head = p->head;
    p->head->next = s;
    s->next = p;
    p->head = s;
    return OK;
}

int list_delete(node &l, int i, elemtype &e)
{
    node *p;
    p = GetElem(l, i);
    if (!p)
        return ERROR;
    e = p->data;
    p->head->next = p->next;
    p->next->head = p->head;
    free(p);
    return OK;
}