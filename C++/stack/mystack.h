#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define INCREASE 1

typedef struct
{
    char *a;
} elemtype;

typedef struct stacknode
{
    elemtype data;
    struct stacknode *next;
} S;

void Init(S &s)
{
    s.next = NULL;
    printf("��ʼ����ջ\n");
}

int StackLength(S s)
{
    int n = 0;
    S *p;
    p = &s;
    while (p->next)
    {
        p = p->next;
        n++;
    }
    printf("ջ�ĳ����ǣ� %d\n", n);
    return n;
}

int GetTop(S s, elemtype &e)
{
    if (!s.next)
        return ERROR;
    e = (s.next)->data;
    //printf("ջ��Ԫ���ǣ� %c\n", e);
    return OK;
}

int Push(S &s, elemtype e)
{
    S *p = (S *)malloc(sizeof(stacknode));
    p->data = e;
    p->next = s.next;
    s.next = p;
    //printf("��%c��ջ\n", e);
    return OK;
}

int Pop(S &s, elemtype &e)
{
    GetTop(s, e);
    S *p;
    p = s.next;
    s.next = p->next;
    free(p);
    //printf("�ѳ�ջ����ջԪ��Ϊ�� %c\n", e);
    return OK;
}

void ClearStack(S &s)
{
    elemtype e;
    S *p;
    p = s.next;
    while (p)
    {
        p = p->next;
        Pop(s, e);
    }
    printf("����ջ\n");
}

void DestroyStack(S &s)
{
    ClearStack(s);
    free(s.next);
    printf("�ѻ�ջ\n");
}

int StackEmpty(S s)
{
    if (s.next)
    {
        printf("not Empty\n");
        return TRUE;
    }
    else
    {
        printf("is Empty\n");
        return FALSE;
    }
}