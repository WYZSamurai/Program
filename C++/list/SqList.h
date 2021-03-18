#include <cstdio>
#include <cstdlib>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAX 100     //��ʼ�����ڴ�
#define increase 10 //��������

typedef struct sql
{
    //�������Ա�
    int *base;    //��ַ
    int length;   //��ǰ����
    int listsize; //��ǰ�Ĵ���������sizeof(int)�����ܳ���
} SqList;

int Initial_sq(SqList &L)
{
    //��ʼ���յ����Ա�
    L.base = (int *)malloc(MAX * sizeof(int)); //�����ֽڿռ�
    if (!L.base)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = MAX;
    return OK;
}

int list_insert(SqList &L, int i, int elem)
{
    //�ڵ�i��λ��֮ǰ����Ԫ��elem��ʱ�临�Ӷ�O(n)
    if (i < 1 || i > L.length + 1)
        return ERROR; //iֵ���Ϸ�
    if (L.length >= L.listsize)
    { //�ռ����������ӷ���
        L.base = (int *)realloc(L.base, (L.listsize + increase) * sizeof(int));
        if (!L.base)
            exit(ERROR);
        L.listsize += increase;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.base[j] = L.base[j - 1];
    }
    L.base[i - 1] = elem;
    L.length++; //��ǰ���ȼ�һ
    return OK;
}

int list_delete(SqList &l, int i, int *e)
{
    //ɾ����i��Ԫ�أ�����e������ֵ��ʱ�临�Ӷ�O(n)
    if (i < 1 || i > l.length + 1)
        return ERROR;
    *e = l.base[i - 1];
    for (int j = i; j < l.length; j++)
    {
        l.base[j - 1] = l.base[j];
    }
    l.length--;
    return OK;
}

void list_print(SqList &l)
{
    printf("length=%d,listsize=%d.\n", l.length, l.listsize);
    for (int i = 0; i < l.length; i++)
    {
        printf("%d\n", l.base[i]);
    }
}

int compare(int a, int b)
{
    if (a == b)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int list_search(SqList &l, int e, int (*compare)(int a, int b))
{
    int i = 1;
    int *p;
    p = l.base;
    while (i <= l.length && !(*compare)(*p++, e))
        i++;
    if (i <= l.length)
        return i;
    else
        return 0;
}